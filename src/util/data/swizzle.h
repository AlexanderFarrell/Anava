//
// Created by Alexander Farrell on 5/30/22.
//

#ifndef POLAR_HAMLET_SWIZZLE_H
#define POLAR_HAMLET_SWIZZLE_H

//void SetVarsFloat(float * data, int count, ...);
//void SetVarsInt(int * data, int count, ...);
//
//void SetXY(float * data, float x, float y);
//void SetXYZ(float * data, float x, float y, float z);
//void SetXYZW(float * data, float x, float y, float z, float w);
//
//void SetXYInt(int * data, int x, int y);
//void SetXYZInt(int * data, int x, int y, int z);
//void SetXYZWInt(int * data, int x, int y, int z, int w);

inline int TwoToOne(int x, int y, int width) {
    return x + (y * width);
}

inline void SetRGBAByte(char * data, int offset, char r, char g, char b, char a) {
    data[(offset * 4) + 0] = r;
    data[(offset * 4) + 1] = g;
    data[(offset * 4) + 2] = b;
    data[(offset * 4) + 3] = a;
}

inline void SetRGBByte(char * data, int offset, char r, char g, char b) {
    data[(offset * 3) + 0] = r;
    data[(offset * 3) + 1] = g;
    data[(offset * 3) + 2] = b;
}

inline void SetXY(float * data, float x, float y) {
    data[0] = x;
    data[1] = y;
}

inline void SetXYZ(float * data, float x, float y, float z) {
    data[0] = x;
    data[1] = y;
    data[2] = z;
}

inline void SetXYZW(float * data, float x, float y, float z, float w) {
    data[0] = x;
    data[1] = y;
    data[2] = z;
    data[3] = w;
}

inline void SetXYInt(int * data, int x, int y) {
    data[0] = x;
    data[1] = y;
}

inline void SetXYZInt(int * data, int x, int y, int z) {
    data[0] = x;
    data[1] = y;
    data[2] = z;
}

inline void SetXYZWInt(int * data, int x, int y, int z, int w) {
    data[0] = x;
    data[1] = y;
    data[2] = z;
    data[3] = w;
}

#endif //POLAR_HAMLET_SWIZZLE_H
