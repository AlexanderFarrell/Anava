//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_SHADER_H
#define ANAVA_T_THREE_SHADER_H

#include <OpenGL/gl3.h>
#include <string>

class Shader {
public:
    GLuint program;
    Shader(char * vert_source, char * frag_source);
    ~Shader();

    static Shader* from_files(const std::string& filename);
};

//Shader* from_files(std::string vert_filename, std::string frag_filename) {
//    throw "Not implemented";
//}

#endif //ANAVA_T_THREE_SHADER_H
