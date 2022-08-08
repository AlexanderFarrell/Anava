//
// Created by Alexander Farrell on 7/23/22.
//

#include "fs.h"
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <dirent.h>
#include <vector>

FS::FS() {
    char path[200];
    getcwd(path, sizeof(path));
    this->game_path = std::string(path);
//    std::cout << "Game Path: " << this->game_path << "\n";
}

std::string FS::load_as_string(const std::string& relative_path) const {
    std::ifstream i(this->game_path + "/" + relative_path);
    std::stringstream buffer;
    buffer << i.rdbuf();
    i.close();
    return buffer.str();
}

std::ifstream FS::get_in_filestream(const std::string &relative_path) const {
    return std::ifstream(this->game_path + "/" + relative_path);
}

std::ofstream FS::get_out_filestream(const std::string &relative_path) const {
    return std::ofstream(this->game_path + "/" + relative_path);
}

std::unordered_map<std::string, std::string> FS::load_config(const std::string &relative_path) const {
    auto ret_val = std::unordered_map<std::string, std::string>();

    auto fs = this->get_in_filestream(relative_path);

    std::string line;
    while(std::getline(fs, line)) {
        auto size = line.size();
        if ((size > 1 && line[0] == ';') || size < 3) {
            continue;
        }
        auto sep = line.find('=');
        std::string key = line.substr(0, sep);
        std::string value = line.substr(sep+1, size);
        ret_val[key] = value;
    }

    return ret_val;
}

array_sized<std::string> FS::get_mods_list() const {
    std::vector<std::string> v;
    char path[this->game_path.length()+10];
    sprintf(path, "%s/Mods/", this->game_path.c_str());

    DIR *dir = opendir(path);
    struct dirent *entry = readdir(dir);

    while (entry != nullptr) {
//        std::cout << entry->d_name << " " << ((entry->d_type == DT_DIR) ? "Dir" : "Not Dir") << "\n";
        if (entry->d_type == DT_DIR && entry->d_name[0] != '.') {
            v.emplace_back(entry->d_name);
        }
        entry = readdir(dir);
    }

    int as_int = v.size();

    closedir(dir);

    auto * ret_val = new std::string[v.size()];

    for (int i = 0; i < v.size(); ++i) {
        ret_val[i] = v[i];
    }

    v.clear();
    array_sized<std::string> r;
    r.t = ret_val;
    r.size = as_int;
    return r;
}
