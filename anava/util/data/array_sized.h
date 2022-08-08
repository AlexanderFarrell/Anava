//
// Created by Alexander Farrell on 8/8/22.
//

#ifndef TEST_ANAVA_GAME_ARRAY_SIZED_H
#define TEST_ANAVA_GAME_ARRAY_SIZED_H

template <class T>
class array_sized {
public:
    array_sized() {
        t = nullptr;
        size = 0;
    }
    array_sized(T *t, int size) : t(t), size(size) {}
    ~array_sized(){
        delete[] t;
    }

    int size;
    T* t;
};


#endif //TEST_ANAVA_GAME_ARRAY_SIZED_H
