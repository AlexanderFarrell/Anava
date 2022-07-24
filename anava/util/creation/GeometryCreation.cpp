//
// Created by Alexander Farrell on 6/25/22.
//

#include "GeometryCreation.h"
#include "../data/swizzle.h"

Mesh * GeometryCreation::CreateSquare() {
    return CreateSquare(1.0f);
}

Mesh *GeometryCreation::CreateSquare(float size) {
//    auto attributes = new VertexAttribute[2];
//
//    auto position = &attributes[0];
//    position->init(3, 4);
//    SetXYZ(position->data + 0, 0.0f, 0.0f, 0.0f);
//    SetXYZ(position->data + 3, 0.0f, size, 0.0f);
//    SetXYZ(position->data + 6, size, 0.0f, 0.0f);
//    SetXYZ(position->data + 9, size, size, 0.0f);
//    position->create_buffer();
//
//    auto uvs = &attributes[1];
//    uvs->init(2, 4);
//    SetXY(uvs->data, 0.0f, 0.0f);
//    SetXY(uvs->data + 2, 1.0f, 0.0f);
//    SetXY(uvs->data + 4, 0.0f, 1.0f);
//    SetXY(uvs->data + 6, 1.0f, 1.0f);
//    uvs->create_buffer();
//
//    int * indices = new int[6];
//    SetXYZInt(indices, 0, 1, 2);
//    SetXYZInt(indices+3, 1, 2, 3);
//
//    auto mesh = new Mesh(attributes, 2, indices, 6);
//    return mesh;
    return GeometryCreation::CreateRectangle(size, size);
}

Mesh *GeometryCreation::CreateText(Font *font, const std::string& text) {
    auto attributes = new VertexAttribute[2];
    int charCount = text.size();
    int vertexCount = charCount*4;

    float xPen = 0.0f;

    auto position = &attributes[0];
    auto uvs = &attributes[1];
    position->init(3, vertexCount);
    uvs->init(2, vertexCount);

    for (int i = 0; i < charCount; ++i) {
        Glyph* glyph = &font->glyphs[text[i]];
        int vertexOffset = i*4*3;
        int uvOffset = i*4*2;
        auto yLow = (float)(font->max_size - glyph->bitmap_top);
        auto yHigh = (float)(yLow + glyph->height);
//        printf("Font Size: %d, Bitmap Top: %d, Glyph Height: %f\n", font->font_size, glyph->bitmap_top, glyph->height);
//        printf("yLow: %f, yHigh: %f\n", yLow, yHigh);
        SetXYZ(position->data + vertexOffset + 0, 0.0f + xPen, yLow, 0.0f);
        SetXYZ(position->data + vertexOffset + 3, 0.0f + xPen, yHigh, 0.0f);
        SetXYZ(position->data + vertexOffset + 6, glyph->width + xPen, yLow, 0.0f);
        SetXYZ(position->data + vertexOffset + 9, glyph->width + xPen, yHigh, 0.0f);

        SetXY(uvs->data + uvOffset,
              glyph->x0/(float)TEXTURE_SIZE_FONT,
              glyph->y0/(float)TEXTURE_SIZE_FONT);
        SetXY(uvs->data + uvOffset + 2,
              glyph->x0/(float)TEXTURE_SIZE_FONT,
              glyph->y1/(float)TEXTURE_SIZE_FONT);
        SetXY(uvs->data + uvOffset+ 4,
              glyph->x1/(float)TEXTURE_SIZE_FONT,
              glyph->y0/(float)TEXTURE_SIZE_FONT);
        SetXY(uvs->data + uvOffset + 6,
              glyph->x1/(float)TEXTURE_SIZE_FONT,
              glyph->y1/(float)TEXTURE_SIZE_FONT);

        xPen += glyph->advance;
    }

    //Size - Width, Rows
    //Bearing - Left, Top
    // Size.Rows - Size.Top
    // Size.Rows + Size.Rows

//    display_arr(position->data, position->count*position->count_per_vertex);
//    display_arr(uvs->data, uvs->count*uvs->count_per_vertex);

    position->create_buffer();
    uvs->create_buffer();

    int * indices = new int[6*charCount];
    for (int i = 0; i < charCount; ++i) {
        int vertexOffset = i*4;
        SetXYZInt(indices+ (i*6), vertexOffset+0, vertexOffset+1, vertexOffset+2);
        SetXYZInt(indices+3+ (i*6), vertexOffset+1, vertexOffset+2, vertexOffset+3);
    }

//    display_arr(indices, 6*charCount);

    Mesh* mesh = new Mesh(attributes, 2, indices, 6*charCount);
    return mesh;
}

void GeometryCreation::UpdateText(Mesh *mesh, Font *font, std::string text) {

}

Mesh *GeometryCreation::CreateRectangle(float width, float height) {
    auto attributes = new VertexAttribute[2];

    auto position = &attributes[0];
    position->init(3, 4);
    SetXYZ(position->data + 0, 0.0f, 0.0f, 0.0f);
    SetXYZ(position->data + 3, 0.0f, height, 0.0f);
    SetXYZ(position->data + 6, width, 0.0f, 0.0f);
    SetXYZ(position->data + 9, width, height, 0.0f);
    position->create_buffer();

    auto uvs = &attributes[1];
    uvs->init(2, 4);
    SetXY(uvs->data, 0.0f, 0.0f);
    SetXY(uvs->data + 2, 1.0f, 0.0f);
    SetXY(uvs->data + 4, 0.0f, 1.0f);
    SetXY(uvs->data + 6, 1.0f, 1.0f);
    uvs->create_buffer();

    int * indices = new int[6];
    SetXYZInt(indices, 0, 1, 2);
    SetXYZInt(indices+3, 1, 2, 3);

    auto mesh = new Mesh(attributes, 2, indices, 6);
    return mesh;
}
