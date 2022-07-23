//
// Created by Alexander Farrell on 6/18/22.
//

#include "material.h"

Material::Material(Shader *shader) {
    this->shader = shader;
//    this->uniform_count = uniform_count;
//
//    if (this->uniform_count < 0) {
//        this->uniforms = uniforms;
//
//        for (int i = 0; i < this->uniform_count; i++) {
//            this->uniforms[i].get_location(this->shader->program);
//        }
//    } else {
//        this->uniforms = nullptr;
//    }
}

Material::~Material() {
    for (auto & uniform : this->uniforms) {
        delete uniform;
    }
}

void Material::prepare() {
    glUseProgram(this->shader->program);

    for (int i = 0; i < this->textures.size(); ++i) {
        this->textures[i]->bind(i);
    }

    for (auto & uniform : this->uniforms) {
        uniform->bind();
    }
}

Uniform* Material::add_uniform(Uniform * uniform) {
    uniform->get_location(this->shader->program);
    this->uniforms.push_back(uniform);
    return uniform;
}

Texture *Material::add_texture(Texture *texture) {
    this->textures.push_back(texture);
    return texture;
}
