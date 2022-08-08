//
// Created by Alexander Farrell on 7/23/22.
//

#ifndef ANAVA_FS_H
#define ANAVA_FS_H

#include <string>
#include <fstream>
#include <unordered_map>
#include "../../util/data/array_sized.h"

class FS {
public:
    std::string game_path;
//    std::string engine_path;

    FS();
    std::string load_as_string(const std::string& relative_path) const;
    std::ifstream get_in_filestream(const std::string& relative_path) const;
    std::ofstream get_out_filestream(const std::string& relative_path) const;

    std::unordered_map<std::string, std::string> load_config(const std::string& relative_path) const;
    array_sized<std::string> get_mods_list() const;
};


#endif //ANAVA_FS_H
