//
// Created by Alexander Farrell on 6/24/22.
//

#ifndef ANAVA_T_THREE_TEXTURE_H
#define ANAVA_T_THREE_TEXTURE_H

#include <OpenGL/gl3.h>

//enum TextureMinFilter {
//    Nearest = GL_NEAREST_MIPMAP_NEAREST,
//    Bilinear = GL_LINEAR_MIPMAP_NEAREST,
//    Trilinear = GL_LINEAR_MIPMAP_LINEAR
//};
//
//enum TextureMagFilter {
//    NearestMag = GL_NEAREST_MIPMAP_NEAREST,
//    BilinearMag = GL_LINEAR_MIPMAP_NEAREST,
//    TrilinearMag = GL_LINEAR_MIPMAP_LINEAR
//};

enum TextureFilter {
    Nearest = GL_NEAREST,
    Linear = GL_LINEAR,
    LinearMipMaps = GL_LINEAR_MIPMAP_LINEAR
};

class Texture {
private:
    int width;
    int height;
    bool genMipmap;
public:
    int getWidth() const;

    int getHeight() const;

private:
    int max_anisotropic;
public:
    TextureFilter min_filter;
    TextureFilter mag_filter;
    char* data;
    GLuint binding;
    Texture(int width, int height, bool genMipmap, bool generate);
    void buffer();
    void bind(int n);
};


#endif //ANAVA_T_THREE_TEXTURE_H
