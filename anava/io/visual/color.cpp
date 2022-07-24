//
// Created by Alexander Farrell on 6/18/22.
//

#include "color.h"

void Color::set(float r, float g, float b, float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Color::set(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}
