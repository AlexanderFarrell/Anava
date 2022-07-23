//
// Created by Alexander Farrell on 6/18/22.
//

#include "uniform.h"
#include <cstdlib>
#include <cstring>

Uniform::Uniform(const std::string& name, int size) {
    this->data = (float*)malloc(sizeof(float) * size);
//    strcpy(this->name, name);
    unsigned long i = name.size() + 1;
    this->name = (char*)malloc(i);
    strcpy(this->name, name.c_str());
}

Uniform::~Uniform() {
    free(this->data);
    free(this->name);
}

void Uniform::get_location(GLuint program) {
    this->location = glGetUniformLocation(program, this->name);
}

void Uniform::bind() {
    throw std::runtime_error("Base method called for uniform");
}

void UniformMat4::bind() {
    glUniformMatrix4fv(
            this->location,
            1,
            (this->transpose) ? 1 : 0,
            this->data
            );
}

UniformMat4::UniformMat4(const std::string& name) : Uniform(name, 16) {
    this->transpose = false;
}

void UniformVec4::bind() {
    glUniform4fv(
            this->location,
            1,
            this->data
    );
}

void UniformVec3::bind() {
    glUniform3fv(
            this->location,
            1,
            this->data
            );
}

void UniformVec2::bind() {
    glUniform2fv(
            this->location,
            1,
            this->data
    );
}

void UniformVec1::bind() {
    glUniform1fv(
            this->location,
            1,
            this->data
    );
}
