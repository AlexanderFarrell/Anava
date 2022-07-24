//
// Created by Alexander Farrell on 6/25/22.
//

#include "TextureFilters.h"

void TextureFilters::ApplyNoise(Texture *texture) {
    for (int x = 0; x < texture->getWidth(); ++x) {
        for (int y = 0; y < texture->getHeight(); ++y) {
            SetRGBByte(texture->data,
                       TwoToOne(y, x, texture->getHeight()),
                       rand_char_unit(),
                       rand_char_unit(),
                       rand_char_unit());
        }
    }
}

void TextureFilters::ApplyNoise(Texture *texture, float min, float max) {
    char byte_min = (char)(min * 255);
    char byte_max = (char)(max * 255);
    for (int x = 0; x < texture->getWidth(); ++x) {
        for (int y = 0; y < texture->getHeight(); ++y) {
            SetRGBByte(texture->data,
                       TwoToOne(y, x, texture->getHeight()),
                       rand_char(byte_min, byte_max),
                       rand_char(byte_min, byte_max),
                       rand_char(byte_min, byte_max));
        }
    }
}

Texture *TextureFilters::CreateGradient(glm::vec3 start, glm::vec3 end) {
    auto* texture = new Texture(2, 2, false, false);

    texture->data[0] = (char)start[0]*255;
    texture->data[1] = (char)start[1]*255;
    texture->data[2] = (char)start[2]*255;

    texture->data[3] = (char)start[0]*255;
    texture->data[4] = (char)start[1]*255;
    texture->data[5] = (char)start[2]*255;

    texture->data[6] = (char)end[0]*255;
    texture->data[7] = (char)end[1]*255;
    texture->data[8] = (char)end[2]*255;

    texture->data[9] = (char)end[0]*255;
    texture->data[10] = (char)end[1]*255;
    texture->data[11] = (char)end[2]*255;

    texture->buffer();
    return texture;
}

Texture *TextureFilters::CreateCornerGradient(glm::vec3 lt, glm::vec3 rt, glm::vec3 lb, glm::vec3 rb) {
    auto* texture = new Texture(2, 2, false, false);

    texture->data[0] = (char)lt[0]*255;
    texture->data[1] = (char)lt[1]*255;
    texture->data[2] = (char)lt[2]*255;

    texture->data[3] = (char)rt[0]*255;
    texture->data[4] = (char)rt[1]*255;
    texture->data[5] = (char)rt[2]*255;

    texture->data[6] = (char)lb[0]*255;
    texture->data[7] = (char)lb[1]*255;
    texture->data[8] = (char)lb[2]*255;

    texture->data[9] =  (char)rb[0]*255;
    texture->data[10] = (char)rb[1]*255;
    texture->data[11] = (char)rb[2]*255;

    texture->buffer();
    return texture;
}

void TextureFilters::ApplyNoiseUnit(Texture *texture, float min, float max) {
    char byte_min = (char)(min * 255);
    char byte_max = (char)(max * 255);
    for (int x = 0; x < texture->getWidth(); ++x) {
        for (int y = 0; y < texture->getHeight(); ++y) {
            char v = rand_char(byte_min, byte_max);
            SetRGBByte(texture->data,
                       TwoToOne(y, x, texture->getHeight()),
                       v,
                       v,
                       v);
        }
    }
}

void TextureFilters::BlendMultiply(Texture *texture, float r, float g, float b) {
    for (int x = 0; x < texture->getWidth(); ++x) {
        for (int y = 0; y < texture->getHeight(); ++y) {
            int index = TwoToOne(y, x, texture->getHeight());
            float rin = texture->data[index+0] / 255.0f;
            float gin = texture->data[index+1] / 255.0f;
            float bin = texture->data[index+2] / 255.0f;


            SetRGBByte(texture->data,
                       TwoToOne(y, x, texture->getHeight()),
                       (char)((rin * r) * 255),
                       (char)((gin * r) * 255),
                       (char)((bin * r) * 255));
        }
    }
}

Texture *TextureFilters::CreateSpace(int width, int height, float starChance) {
    auto* texture = new Texture(width, height, false, false);
    for (int x = 0; x < texture->getWidth(); ++x) {
        for (int y = 0; y < texture->getHeight(); ++y) {
            if (rand_float_unit() < starChance) {
                char v = rand_char_unit();
                SetRGBByte(texture->data,
                           TwoToOne(y, x, texture->getHeight()),
                           v,
                           v,
                           v);
            }
        }
    }
    return texture;
}
