#include "core/gl/core_shader.h"
#include "utils/file_utils.h"

wizmrenderer::core_gl_shader::core_gl_shader(const char* vertex_file_path, const char* fragment_file_path)
{
    std::string VShaderFF = wizmcore::read_file_to_str(vertex_file_path);
    std::string FShaderFF = wizmcore::read_file_to_str(fragment_file_path);
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

wizmrenderer::core_gl_shader::core_gl_shader(const char* compute_file_path)
{
    is_compute = true;
    std::string CShaderFF = wizmcore::read_file_to_str(compute_file_path);
    const char* compute_shader_source = CShaderFF.c_str();

    unsigned int comute_shader = glCreateShader(GL_COMPUTE_SHADER);
    glShaderSource(comute_shader, 1, &compute_shader_source, NULL);
    glCompileShader(comute_shader);

    checkCompileErrors(comute_shader, "COMPUTE", compute_file_path);

    shader_id = glCreateProgram();
    glAttachShader(shader_id, comute_shader);
    glLinkProgram(shader_id);



    glDeleteShader(comute_shader);
}

void wizmrenderer::core_gl_shader::use_shader()
{
	glUseProgram(shader_id);
}
