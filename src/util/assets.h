//
// Created by Alexander Farrell on 6/23/22.
//

#ifndef ANAVA_T_THREE_ASSETS_H
#define ANAVA_T_THREE_ASSETS_H


#include <cstdio>
#include <cstdlib>

char *load_file_as_string(char *filename) {
#ifdef DEBUG_LOG
    printf("Loading file %s...\n", filename);
#endif
    char *buffer = nullptr;
    long length;
    FILE *file = fopen(filename, "rb");

    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = (char*)malloc(length + 1);
        if (buffer) {
            fread(buffer, 1, length, file);
            fclose(file);
            buffer[length] = '\0';
            return buffer;
        } else {
            printf("Cannot load file, out of memory.\n");
            fclose(file);
            return nullptr;
        }
    } else {
        printf("Failed to load file as string %s.\n", filename);
        return nullptr;
    }
}


#endif //ANAVA_T_THREE_ASSETS_H
