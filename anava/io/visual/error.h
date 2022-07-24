//
// Created by Alexander Farrell on 6/24/22.
//

#ifndef ANAVA_T_THREE_ERROR_H
#define ANAVA_T_THREE_ERROR_H

#include <OpenGL/gl3.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

inline void display_matrix(glm::mat4 matrix) {
    const auto* pS = (const float*)glm::value_ptr(matrix);
    for (int i = 0; i < 16; ++i) {
        if (i % 4 == 0 && i != 0) {
            printf("\n");
        }
        printf("%.4f   ", pS[i]);
    }
    printf("\n\n");
}

//inline void display_matrix4(float *matrix) {
//    int x;
//    int y;
//    for (y = 0; y < 4; ++y) {
//        for (x = 0; x < 4; ++x) {
//            printf("%.4f ", matrix[x + (y * 4)]);
//        }
//        printf("\n");
//    }
//}

//inline void display_arr(float* a, int length) {
//    for (int i = 0; i < length; ++i) {
//        printf("%d - %f\n ", i, a[i]);
//    }
//    printf("\n");
//}

template <typename T>
inline void display_arr(T* a, int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << i << " - " << a[i] << "\n";
        //printf("%d - %f\n ", i, a[i]);
    }
    printf("\n");
}

inline void print_max_texture_size() {
    int mts;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &mts);
    printf("Max Texture Size: %d\n", mts);
}

inline void check_for_errors_gl(int code) {
    GLenum a = glGetError();

    if (a != GL_NO_ERROR) {
        char error[250];
        sprintf(error, "Graphics Error\n - Code: %d\n - ID: %d\n - Message:", a, code);
        switch (a) {
            case GL_INVALID_ENUM:
                printf("%s Invalid Enum", error);
                exit(1);
            case GL_INVALID_VALUE:
                printf("%s Invalid Value", error);
                exit(1);
            case GL_INVALID_OPERATION:
                printf("%s Invalid Operation", error);
                exit(1);
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                printf("%s Invalid Framebuffer Operation", error);
                exit(1);
            case GL_OUT_OF_MEMORY:
                printf("%s Out of Graphics Memory", error);
                exit(1);
//            case GL_STACK_OVERFLOW:
//                printf("%s GL Stack OVERflow", error);
//                exit(1);
//            case GL_STACK_UNDERFLOW:
//                printf("%s GL Stack UNDERflow", error);
//                exit(1);
            default:
                printf("%s Unknown Error", error);
                exit(1);
        }
    }
}

#endif //ANAVA_T_THREE_ERROR_H
