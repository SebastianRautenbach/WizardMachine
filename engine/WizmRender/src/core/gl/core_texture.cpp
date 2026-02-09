#define STB_IMAGE_IMPLEMENTATION
#include "core/gl/core_texture.h"
#include "image/stb_image.h"

core_gl_texture::core_gl_texture(const char* file_path, bool vert_on_load)
{
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(vert_on_load);
    unsigned char* data = stbi_load(file_path, &width, &height, &nrChannels, 0);
    if (data)
    {
        GLenum internalFormat = GL_RGBA;

        if (nrChannels == 1) {
            internalFormat = GL_RED;
        }
        else if (nrChannels == 3) {
            internalFormat = GL_RGB;
        }
        else if (nrChannels == 4) {
            internalFormat = GL_RGBA;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, internalFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture: " << file_path << std::endl;
    }
    stbi_image_free(data);

    unbind_texture();
}

void core_gl_texture::bind_texture()
{
	glBindTexture(GL_TEXTURE_2D, texture_id);
}

void core_gl_texture::delete_texture()
{
	glDeleteTextures(1, &texture_id);
}

void core_gl_texture::unbind_texture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void core_gl_texture::set_texture(const char* file_path, bool vert_on_load)
{
    glBindTexture(GL_TEXTURE_2D, texture_id);


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(vert_on_load);

    unsigned char* data = stbi_load(file_path, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}
