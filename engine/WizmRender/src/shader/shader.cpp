#include "../includes/shader/shader.h"
#include "utils/file_utils.h"

wizm::renderer::core_gl_shader::core_gl_shader(const char* vertex_file_path, const char* fragment_file_path)
{
    std::string VShaderFF = core::read_file_to_str(vertex_file_path);
    std::string FShaderFF = core::read_file_to_str(fragment_file_path);
    const char* vertexShaderSource = VShaderFF.c_str();
    const char* fragmentShaderSource = FShaderFF.c_str();


    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    checkCompileErrors(vertexShader, "VERTEX", vertex_file_path);


    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    checkCompileErrors(fragmentShader, "FRAGMENT", fragment_file_path);


    shader_id = glCreateProgram();
    glAttachShader(shader_id, vertexShader);
    glAttachShader(shader_id, fragmentShader);
    glLinkProgram(shader_id);

    int success;
    char infoLog[512];

    glGetProgramiv(shader_id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

wizm::renderer::core_gl_shader::core_gl_shader(const char* compute_file_path)
{
    is_compute = true;
    std::string CShaderFF = core::read_file_to_str(compute_file_path);
    const char* compute_shader_source = CShaderFF.c_str();

    unsigned int compute_shader = glCreateShader(GL_COMPUTE_SHADER);
    glShaderSource(compute_shader, 1, &compute_shader_source, NULL);
    glCompileShader(compute_shader);

    checkCompileErrors(compute_shader, "COMPUTE", compute_file_path);

    shader_id = glCreateProgram();
    glAttachShader(shader_id, compute_shader);
    glLinkProgram(shader_id);
    
    glDeleteShader(compute_shader);
}

void wizm::renderer::core_gl_shader::use_shader() const
{
    glUseProgram(shader_id);
}
