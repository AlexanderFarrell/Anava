//
// Created by Alexander Farrell on 7/23/22.
//

#include "fs.h"
#include <cstdlib>
#include <unistd.h>
#include <iostream>

FS::FS() {
    char path[200];
    getcwd(path, sizeof(path));
    this->game_path = std::string(path);
    std::cout << "Game Path: " << this->game_path << "\n";
}
