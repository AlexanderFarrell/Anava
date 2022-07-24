//
// Created by Alexander Farrell on 7/2/22.
//

#include "font.h"

Font::Font(const std::string& filename, int font_size) {
    const char* filename_c = filename.c_str();
    this->font_size = font_size;
    this->max_size = 0;
    unsigned long lengthFilename = strlen(filename_c);

    char pathFile[lengthFilename + 150];

    sprintf(pathFile, "../../content/visual/font/%s", filename_c);
    this->texture = new Texture(4096, 4096, false, false);

//    printf("Filename: %s\n", pathFile);

    FT_Library ft;
    if (FT_Init_FreeType(&ft)) {
        throw std::runtime_error("ERROR: Could not init font - Error initializing FreeType Library\n");
//        throw "ERROR: Could not init font - Error initializing FreeType Library\n";
    }

    FT_Face face;
    if (FT_New_Face(ft, pathFile, 0, &face)) {
        throw std::runtime_error("ERROR: Failed to load font\n");
        throw "ERROR: Failed to load font\n";
    }

    FT_Set_Pixel_Sizes(face, 0, font_size);
    int pen_x = 0;
    int pen_y = 0;

    for (int i = 0; i < GLYPH_COUNT; i++) {
        FT_Load_Char(face, i, FT_LOAD_RENDER | FT_LOAD_FORCE_AUTOHINT | FT_LOAD_TARGET_LIGHT);
        FT_Bitmap* bmp = &face->glyph->bitmap;

        if (pen_x + bmp->width >= TEXTURE_SIZE_FONT) {
            pen_x = 0;
            pen_y += ((face->size->metrics.height >> 6) + 1);
        }


        for (int x = 0; x < bmp->width; ++x) {
            for (int y = 0; y < bmp->rows; ++y) {
                int xx = pen_x + x;
                int yy = pen_y + y;
                this->texture->data[(yy * TEXTURE_SIZE_FONT + xx)*3] = bmp->buffer[y * bmp->pitch + x];
            }
        }

        if (this->max_size < face->glyph->bitmap_top) {
            this->max_size = face->glyph->bitmap_top;
        }

        this->glyphs[i].x0 = pen_x;
        this->glyphs[i].y0 = pen_y;
        this->glyphs[i].x1 = pen_x + bmp->width;
        this->glyphs[i].y1 = pen_y + bmp->rows;
        this->glyphs[i].bitmap_left = face->glyph->bitmap_left;
        this->glyphs[i].bitmap_top = face->glyph->bitmap_top;
        this->glyphs[i].width = face->glyph->bitmap.width;
        this->glyphs[i].height = face->glyph->bitmap.rows;
//        this->glyphs[i].
        this->glyphs[i].advance = face->glyph->advance.x >> 6;
        pen_x += bmp->width + 1;
    }

    FT_Done_FreeType(ft);
    this->texture->buffer();
}

int Font::get_width(const std::string &text) {
    int width = 0;

    for (int i = 0; i < text.size(); ++i) {
        width += this->glyphs[text[i]].advance;
    }

    return width;
}
