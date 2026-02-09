#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <string>
#include "math/pch_math.h"

namespace wizmrenderer
{
    class core_gl_shader
    {
    public:
    core_gl_shader(const char* vertex_file_path, const char* fragment_file_path);
	core_gl_shader(const char* compute_file_path);
	void use_shader();
	unsigned int get_shader_id() const { return shader_id; }

public:
	bool is_compute = false;
	unsigned int shader_id; // this is opengl specific


public:
	void setBool(std::string const& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(shader_id, name.c_str()), (int)value);
	}
	// ------------------------------------------------------------------------
	void setInt(std::string const& name, int value) const
	{
		glUniform1i(glGetUniformLocation(shader_id, name.c_str()), value);
	}
	// ------------------------------------------------------------------------
	void setUInt(std::string const& name, unsigned int value) const
	{
		glUniform1ui(glGetUniformLocation(shader_id, name.c_str()), value);
	}
	// ------------------------------------------------------------------------
	void setFloat(std::string const& name, float value) const
	{
		glUniform1f(glGetUniformLocation(shader_id, name.c_str()), value);
	}
	// ------------------------------------------------------------------------
	void setVec2(std::string const& name, const glm::vec2& value) const
	{
		glUniform2fv(glGetUniformLocation(shader_id, name.c_str()), 1, &value[0]);
	}
	void setVec2(std::string const& name, float x, float y) const
	{
		glUniform2f(glGetUniformLocation(shader_id, name.c_str()), x, y);
	}
	// ------------------------------------------------------------------------
	void setVec3(std::string const& name, const glm::vec3& value) const
	{
		glUniform3fv(glGetUniformLocation(shader_id, name.c_str()), 1, &value[0]);
	}
	void setVec3(std::string const& name, float x, float y, float z) const
	{
		glUniform3f(glGetUniformLocation(shader_id, name.c_str()), x, y, z);
	}
	// ------------------------------------------------------------------------
	void setVec4(std::string const& name, const glm::vec4& value) const
	{
		glUniform4fv(glGetUniformLocation(shader_id, name.c_str()), 1, &value[0]);
	}
	void setVec4(std::string const& name, float x, float y, float z, float w) const
	{
		glUniform4f(glGetUniformLocation(shader_id, name.c_str()), x, y, z, w);
	}
	// ------------------------------------------------------------------------
	void setMat2(std::string const& name, const glm::mat2& mat) const
	{
		glUniformMatrix2fv(glGetUniformLocation(shader_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
	// ------------------------------------------------------------------------
	void setMat3(std::string const& name, const glm::mat3& mat) const
	{
		glUniformMatrix3fv(glGetUniformLocation(shader_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
	// ------------------------------------------------------------------------
	void setMat4(std::string const& name, const glm::mat4& mat) const
	{
		glUniformMatrix4fv(glGetUniformLocation(shader_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
	// ------------------------------------------------------------------------
	void setUVec3(std::string const& name, const glm::uvec3& value) const
	{
		glUniform3ui(glGetUniformLocation(shader_id, name.c_str()), value.x, value.y, value.z);
	}
	// ------------------------------------------------------------------------
	void setUVec2(std::string const& name, const glm::uvec2& value) const
	{
		glUniform2ui(glGetUniformLocation(shader_id, name.c_str()), value.x, value.y);
	}


private:
	void checkCompileErrors(GLuint shader, std::string type, std::string path)
	{
		GLint success;
		GLchar infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				//wizm::add_console_line("path::" + path, CONSOLE_ERROR_LOG);
				//wizm::add_console_line("ERROR::SHADER_COMPILATION_ERROR of type:" + type + infoLog, CONSOLE_ERROR_LOG);

			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				//wizm::add_console_line("path::" + path, CONSOLE_ERROR_LOG);
				//wizm::add_console_line("ERROR::PROGRAM_LINKING_ERROR of type:" + type + infoLog, CONSOLE_ERROR_LOG);
			}
		}
	}


    };    
}

