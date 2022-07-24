//
// Created by Alexander Farrell on 6/18/22.
//

#include "mesh.h"
#include "error.h"
#include <iostream>

VertexAttribute::VertexAttribute(int count_per_vertex, int count) {
    this->count_per_vertex = count_per_vertex;
    this->count = count;
    this->data = new float[count_per_vertex * count];
}

VertexAttribute::VertexAttribute(int count_per_vertex, int count, float *data) : count_per_vertex(count_per_vertex),
                                                                                 count(count), data(data) {}

void VertexAttribute::create_buffer() {
    glGenBuffers(1, &this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER,
                 this->buffer);
    glBufferData(GL_ARRAY_BUFFER,
                 (GLsizeiptr) (this->count * this->count_per_vertex * sizeof(float)),
                 this->data,
                 GL_STATIC_DRAW);
}

VertexAttribute::~VertexAttribute() {
    glDeleteBuffers(1, &this->buffer);
}

VertexAttribute::VertexAttribute() {
    this->count_per_vertex = 0;
    this->count = 0;
    this->data = nullptr;
}

void VertexAttribute::init(int count_per_vertex_in, int count_in) {
    this->count_per_vertex = count_per_vertex_in;
    this->count = count_in;
    this->data = new float[count_per_vertex_in * count_in];
}

Mesh::Mesh(VertexAttribute *attributes, int attribute_count, int *indices, int index_count) {
    this->vbo_count = attribute_count;
    this->vertex_buffers = attributes;
    this->index_count = index_count;
    this->indices = indices;
    this->vertex_count = attributes->count;//attributes->count / attributes->count_per_vertex;

//    std::cout << "Attributes: " << attributes << "\n"
//        << "Attribute Count: " << attribute_count << "\n"
//        << "Indices: " << indices << "\n"
//        << "Index Count: " << index_count << "\n";

    //VBOs
    for (int i = 0; i < attribute_count; i++) {
        this->vertex_buffers[i].create_buffer();
        check_for_errors_gl(50000 + i);
    }

    //VAOs
    glGenVertexArrays(1, &this->vao);
    check_for_errors_gl(5);
    glBindVertexArray(this->vao);
    check_for_errors_gl(6);

    for (int i = 0; i < attribute_count; ++i) {
        glEnableVertexAttribArray(i);
        check_for_errors_gl(7);
        glBindBuffer(GL_ARRAY_BUFFER,
                     this->vertex_buffers[i].buffer);
        check_for_errors_gl(8);
        glVertexAttribPointer(i,
                              this->vertex_buffers[i].count_per_vertex,
                              GL_FLOAT,
                              GL_FALSE,
                              0,
                              nullptr);
        check_for_errors_gl(9);
    }

    glGenBuffers(1, &this->index_buffer);
    check_for_errors_gl(10);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->index_buffer);
    check_for_errors_gl(11);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 (GLsizeiptr) (index_count * sizeof(int)),
                 this->indices,
                 GL_STATIC_DRAW);
    check_for_errors_gl(12);
//    printf("%d\n", index_count);
}

void Mesh::draw() {
    glBindVertexArray(this->vao);
    check_for_errors_gl(300);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,
                 this->index_buffer);
    check_for_errors_gl(301);
    glDrawElements(GL_TRIANGLES,
                   this->index_count,
                   GL_UNSIGNED_INT,
                   (void *) 0);
    check_for_errors_gl(302);
}

Mesh::~Mesh() {
    delete[] this->vertex_buffers;
    glDeleteBuffers(1, &this->index_buffer);
}
