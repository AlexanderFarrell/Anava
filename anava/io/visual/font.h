//
// Created by Alexander Farrell on 7/2/22.
//

#ifndef ANAVA_T_THREE_FONT_H
#define ANAVA_T_THREE_FONT_H

#include <ft2build.h>
#include FT_FREETYPE_H"freetype/freetype.h""freetype/freetype.h"

#include <string>
#include <iostream>
#include "texture.h"
#include "mesh.h"

#define GLYPH_COUNT 128
#define TEXTURE_SIZE_FONT 4096

//struct Glyph {
//    int x0, y0
//};

//https://gist.github.com/baines/b0f9e4be04ba4e6f56cab82eef5008ff

struct Glyph {
    int x0, y0, x1, y1;
    float width, height, bearing;
    int bitmap_left, bitmap_top;
    int advance;
};

class Font {
private:
    FT_Face face;
public:
    int font_size;
    int max_size;
    Texture* texture;
    Glyph glyphs[GLYPH_COUNT];

    Font(const std::string& filename, int font_size);
    int get_width(const std::string& text);
};


#endif //ANAVA_T_THREE_FONT_H
