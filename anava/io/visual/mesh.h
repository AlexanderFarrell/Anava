//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_MESH_H
#define ANAVA_T_THREE_MESH_H

#include <OpenGL/gl3.h>

class VertexAttribute {
public:
    int count_per_vertex;
    int count;
    GLuint buffer;

    VertexAttribute(int count_per_vertex, int count, float *data);
    ~VertexAttribute();
    void create_buffer();

public:
    VertexAttribute();
    VertexAttribute(int count_per_vertex, int count);

    void init(int count_per_vertex, int count);

    float *data;
};

class Mesh {
    GLuint vao;
    GLuint index_buffer;
    int *indices;
    VertexAttribute* vertex_buffers;
    int vbo_count;
    int vertex_count;
    int index_count;

    ~Mesh();

public:
    void draw();

    Mesh(VertexAttribute* attributes,
         int attribute_count,
         int *indices,
         int index_count);
};


#endif //ANAVA_T_THREE_MESH_H
