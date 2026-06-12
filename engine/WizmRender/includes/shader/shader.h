#pragma once
#include <glad/glad.h>
#include <iostream>
#include <string>

#include "math/mat2.h"
#include "math/mat3.h"
#include "math/mat4.h"


namespace wizm
{
	namespace core
	{
		class core_gl_shader {
		public:
			core_gl_shader(const char* vertex_file_path, const char* fragment_file_path);
			core_gl_shader(const char* compute_file_path);
			void use_shader();
			unsigned int get_shader_id() { return shader_id; }
		
		public:
			bool is_compute = false;
			unsigned int shader_id;
		
		
		public:
			void setBool(std::string name, bool value) const
			{
				glUniform1i(glGetUniformLocation(shader_id, name.c_str()), (int)value);
			}
			// ------------------------------------------------------------------------
			void setInt(std::string name, int value) const
			{
				glUniform1i(glGetUniformLocation(shader_id, name.c_str()), value);
			}
			// ------------------------------------------------------------------------
			void setUInt(std::string name, unsigned int value) const
			{
				glUniform1ui(glGetUniformLocation(shader_id, name.c_str()), value);
			}
			// ------------------------------------------------------------------------
			void setFloat(std::string name, float value) const
			{
				glUniform1f(glGetUniformLocation(shader_id, name.c_str()), value);
			}
			// ------------------------------------------------------------------------
			void setVec2(std::string name, const math::vec2<float>& value) const
			{
				glUniform2fv(glGetUniformLocation(shader_id, name.c_str()), 1, &value[0]);
			}
			void setVec2(std::string name, float x, float y) const
			{
				glUniform2f(glGetUniformLocation(shader_id, name.c_str()), x, y);
			}
			// ------------------------------------------------------------------------
			void setVec3(std::string name, const math::vec3<float>& value) const
			{
				glUniform3fv(glGetUniformLocation(shader_id, name.c_str()), 1, &value[0]);
			}
			void setVec3(std::string name, float x, float y, float z) const
			{
				glUniform3f(glGetUniformLocation(shader_id, name.c_str()), x, y, z);
			}
			// ------------------------------------------------------------------------
			void setVec4(std::string name, const math::vec4<float>& value) const
			{
				glUniform4fv(glGetUniformLocation(shader_id, name.c_str()), 1, &value[0]);
			}
			void setVec4(std::string name, float x, float y, float z, float w) const
			{
				glUniform4f(glGetUniformLocation(shader_id, name.c_str()), x, y, z, w);
			}
			// ------------------------------------------------------------------------
			void setMat2(std::string name, const math::mat2<float>& mat) const
			{
				glUniformMatrix2fv(glGetUniformLocation(shader_id, name.c_str()), 1, GL_TRUE, &mat[0][0]);
			}
			// ------------------------------------------------------------------------
			void setMat3(std::string name, const math::mat3<float>& mat) const
			{
				glUniformMatrix3fv(glGetUniformLocation(shader_id, name.c_str()), 1, GL_TRUE, &mat[0][0]);
			}
			// ------------------------------------------------------------------------
			void setMat4(std::string name, const math::mat4<float>& mat) const
			{
				glUniformMatrix4fv(glGetUniformLocation(shader_id, name.c_str()), 1, GL_TRUE, &mat[0][0]);
			}
			// ------------------------------------------------------------------------
			void setUVec3(std::string name, const math::vec3<unsigned int>& value)
			{
				glUniform3ui(glGetUniformLocation(shader_id, name.c_str()), value[0], value[1], value[2]);
			}
			//// ------------------------------------------------------------------------
			void setUVec2(std::string name, const math::vec2<unsigned int>& value)
			{
				glUniform2ui(glGetUniformLocation(shader_id, name.c_str()), value[0], value[1]);
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
}


