//
// Created by Alexander Farrell on 7/23/22.
//

#ifndef ANAVA_IO_H
#define ANAVA_IO_H

#include "audio/audio.h"
#include "ui/UI.h"
#include "visual/visual.h"
#include "fs/fs.h"
#include "network/network.h"

class IO {
public:
    Audio* audio;
    Visual* visual;
    UI* ui;
    FS* fs;
    Input* input;
    Network* network;

    explicit IO(Window* window);
    ~IO();

    void update(Window* window);
};


#endif //ANAVA_IO_H
