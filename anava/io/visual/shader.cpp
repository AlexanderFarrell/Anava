//
// Created by Alexander Farrell on 6/18/22.
//

#include <cstring>
//#include <filesystem>
#include "shader.h"
#include "../../util/assets.h"
#include "error.h"

GLuint compile_shader(char * source, GLenum type) {
    GLuint shader = glCreateShader(type);

//    printf("%s\n", source);
    glShaderSource(shader, 1, (const GLchar *const *)&source, nullptr);
    check_for_errors_gl(100);

    glCompileShader(shader);
    check_for_errors_gl(101);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    check_for_errors_gl(102);

    if (status != GL_TRUE) {
        int length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        check_for_errors_gl(103);
        char *buffer = (char *) malloc(length);
        glGetShaderInfoLog(shader,
                           length,
                           nullptr,
                           buffer);
        check_for_errors_gl(141);
        printf("ERROR: Error when compiling shader\n - %s\n", buffer);
        exit(1);
    }

    return shader;
}

GLuint create_programVF(char * vert_source,
                        char * frag_source) {
    GLuint vert_shader = compile_shader(vert_source, GL_VERTEX_SHADER);
    GLuint frag_shader = compile_shader(frag_source, GL_FRAGMENT_SHADER);

    GLuint program = glCreateProgram();
    glAttachShader(program, vert_shader);
    check_for_errors_gl(142);
    glAttachShader(program, frag_shader);
    check_for_errors_gl(143);
    glLinkProgram(program);
    check_for_errors_gl(144);
    check_for_errors_gl(10);

    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);

    if (status != GL_TRUE) {
        int length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        char *buffer = (char *) malloc(length);
        check_for_errors_gl(201);
        glGetProgramInfoLog(program,
                            length,
                            nullptr,
                            buffer);
        check_for_errors_gl(202);
        printf("ERROR: Error when linking shader program\n - %s\n", buffer);
        exit(1);
    }

    return program;
}

Shader::Shader(char * vert_source,
               char * frag_source) {
    this->program = create_programVF(vert_source, frag_source);
}

Shader::~Shader() {
    glDeleteProgram(this->program);
}

//Shader *Shader::from_files(char *vert_filename, char *frag_filename) {
Shader *Shader::from_files(const std::string& filename) {
    const char * name = filename.c_str();
    unsigned long length = strlen(name);

    char vert_path[length + 150];
    char frag_path[length + 150];

    //sprintf(vert_path, "../../content/visual/shader/%s.vert.glsl", name);
    //sprintf(frag_path, "../../content/visual/shader/%s.frag.glsl", name);
//    std::cout << std::filesystem::current_path();

    sprintf(vert_path, "./visual/common_shaders/%s.vert.glsl", name);
    sprintf(frag_path, "./visual/common_shaders/%s.frag.glsl", name);

    char *vert = load_file_as_string(vert_path);
    char *frag = load_file_as_string(frag_path);

    return new Shader(vert, frag);
}
