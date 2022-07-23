//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_UNIFORM_H
#define ANAVA_T_THREE_UNIFORM_H

#include <OpenGL/gl3.h>
#include <string>

class Uniform {
protected:
    char * name;
    GLint location;
public:
    float *data;
    Uniform(const std::string& name, int size);
    ~Uniform();
    void get_location(GLuint program);
    virtual void bind();
};

class UniformMat4: public Uniform {
public:
    bool transpose;
    void bind() override;
    explicit UniformMat4(const std::string& name);
};

class UniformVec4: public Uniform {
public:
    void bind() override;
};

class UniformVec3: public Uniform {
public:
    void bind() override;
};

class UniformVec2: public Uniform {
public:
    void bind() override;
};

class UniformVec1: public Uniform {
public:
    void bind() override;
};

#endif //ANAVA_T_THREE_UNIFORM_H
