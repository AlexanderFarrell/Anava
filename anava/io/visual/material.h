//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_MATERIAL_H
#define ANAVA_T_THREE_MATERIAL_H


#include "shader.h"
#include "uniform.h"
#include "texture.h"
#include <vector>

class Material {
private:
    std::vector<Uniform*> uniforms;
    std::vector<Texture*> textures;
public:
    Shader * shader;
//    int uniform_count;

    Material(Shader* shader);
    ~Material();

    void prepare();
    Uniform * add_uniform(Uniform * uniform);
    Texture * add_texture(Texture * texture);
};


#endif //ANAVA_T_THREE_MATERIAL_H
