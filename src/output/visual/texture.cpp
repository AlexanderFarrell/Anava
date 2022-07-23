//
// Created by Alexander Farrell on 6/24/22.
//

#include "texture.h"

int textureBindings[] = {
        GL_TEXTURE0,
        GL_TEXTURE1,
        GL_TEXTURE2,
        GL_TEXTURE3,
        GL_TEXTURE4,
        GL_TEXTURE5,
        GL_TEXTURE6,
        GL_TEXTURE7,
        GL_TEXTURE8,
        GL_TEXTURE9,
        GL_TEXTURE10
};

Texture::Texture(int width, int height, bool genMipmap, bool generate) {
    GLuint t;
    this->binding = 0;
    this->width = width;
    this->height = height;
    this->genMipmap = genMipmap;
    this->min_filter = Nearest;
    this->mag_filter = Nearest;
    this->data = new char[width * height * 3];

    if (generate) {
        this->buffer();
    }
}

void Texture::buffer() {
    glDeleteTextures(1, &this->binding);
    glGenTextures(1, &this->binding);
    glBindTexture(GL_TEXTURE_2D, this->binding);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->min_filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->mag_filter);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->data);

    if (genMipmap) {
        glGenerateMipmap(GL_TEXTURE_2D);
    }
}

void Texture::bind(int n) {
    glActiveTexture(textureBindings[n]);
    glBindTexture(GL_TEXTURE_2D, this->binding);
}

int Texture::getWidth() const {
    return width;
}

int Texture::getHeight() const {
    return height;
}
