//
// Created by Alexander Farrell on 6/22/22.
//

#ifndef ANAVA_T_THREE_TYPE_MAP_H
#define ANAVA_T_THREE_TYPE_MAP_H

#include <iostream>
#include <unordered_map>
#include <typeindex>
#include <cstdlib>

class TypeMap {
private:
    std::unordered_map<std::type_index, void*> types;

public:
    TypeMap();
    ~TypeMap();

    template<class T>
    T* add_item(T* item) {
//        auto a = std::type_index(typeid(T));
//        void* b = (void*)item;
//        this->types.insert(a, b);
//        int a;

        this->types[std::type_index(typeid(T))] = (void*)item;
        return item;
    }

    void clear() {
//        for (auto state: this->types) {
//            free(state.second);
//        }
        this->types.clear();
//        std::cout << "Count of elements: " << this->types.size() << "\n";
    }

    std::__hash_map_iterator<std::__hash_iterator<std::__make_hash_node_types<std::__hash_value_type<std::type_index, void *>, void *>::_NodeTp *>>
    begin() {
        return this->types.begin();
    }

    std::__hash_map_iterator<std::__hash_iterator<std::__make_hash_node_types<std::__hash_value_type<std::type_index, void *>, void *>::_NodeTp *>>
    end() {
        return this->types.end();
    }

    template<class T>
    void remove_item() {
        this->types.erase(this->types.find(typeid(T)));
    }

    template<class T>
    T* get_item() {
         return (T*)this->types[typeid(T)];
    }

    template<class T>
    bool has_item() {
        return (this->types.find(typeid(T)) != this->types.end());
    }

//    void erase() {
//        for (auto i : this->types.erase()) {
//            delete i;
//        }
//    }

    bool empty() {
        return this->types.empty();
    }

    user_size_t size() {
        return this->types.size();
    }
};


#endif //ANAVA_T_THREE_TYPE_MAP_H
