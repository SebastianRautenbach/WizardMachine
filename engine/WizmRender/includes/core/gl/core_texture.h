#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <string>
#include "math/pch_math.h"

class core_gl_texture
{
public:
    core_gl_texture(const char* file_path, bool vert_on_load = true);
    void bind_texture();
    void delete_texture();
    void unbind_texture();
    void set_texture(const char* file_path, bool vert_on_load = true);

    unsigned int get_texture_id() const {return texture_id;};
    
private:
    unsigned int texture_id;
};
