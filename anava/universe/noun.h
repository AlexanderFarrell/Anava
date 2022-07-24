//
// Created by Alexander Farrell on 6/22/22.
//

#ifndef ANAVA_T_THREE_NOUN_H
#define ANAVA_T_THREE_NOUN_H

#include "../util/data/type_map.h"

class Noun {
private:
public:
    TypeMap states; //temporary
    Noun* previous;
    Noun* next;

    Noun();
    ~Noun();

public:
    class State {
    public:
        Noun* noun;

        State();
        ~State();

        virtual void Begin();
        virtual void End();
    };

    template<class T>
    inline T* add_state(T* item) {
        static_assert(std::is_base_of<State, T>::value, "State added must be of type State");
        ((State*)item)->noun = this;
        auto ret_val = this->states.add_item(item);
        ((State*)item)->Begin();
        return ret_val;
    }

    template<class T>
    inline void remove_state() {
        static_assert(std::is_base_of<State, T>::value, "State added must be of type State");
        ((State*)this->states.template get_item<T>())->End();
        ((State*)this->states.template get_item<T>())->noun = nullptr;
        this->states.remove_item<T>();
    }

    template<class T>
    inline T* get_state() {
        return this->states.get_item<T>();
    }

    template<class T>
    inline bool has_state() {
        return this->states.has_item<T>();
    }
};


#endif //ANAVA_T_THREE_NOUN_H
