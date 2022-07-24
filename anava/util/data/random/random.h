//
// Created by Alexander Farrell on 5/23/22.
//

#ifndef POLAR_HAMLET_RANDOM_H
#define POLAR_HAMLET_RANDOM_H

#include <stdlib.h>
#include <ctime>
#include "mersenne_twister.h"

inline void seed_with_time() {
    //init_genrand(time(NULL));
    srand(time(NULL));
}

inline void seed(unsigned long seed) {
    init_genrand(seed);
}

inline int rand_coin() {
    return rand() % 2;
}

inline int rand_dice() {
    return (rand() % 6) + 1;
}

inline float rand_float_unit() {
    return (float) (rand() % 10000) / 10000.0;
}


inline char rand_char_unit() {
    return (char) (rand() % 256);
}

inline char rand_char(char min, char max) {
    return (char) ((rand() % (max-min)) + min);
}

inline float rand_float(float min, float max) {
    return ((float) (rand() % 10000) / 10000.0) * (max - min) + min;
}

#endif //POLAR_HAMLET_RANDOM_H
