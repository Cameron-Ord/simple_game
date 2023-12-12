#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <unordered_map>

enum class InputType {
    SPACE,
    DOWN,
    LEFT,
    RIGHT
};

class Movement_Inputs {
    public:
        Movement_Inputs();
        void take_input(int* x, int* y);
        void key_release(SDL_Scancode scancode, int* x, int* y);
        void key_down(SDL_Scancode scancode, int* x, int* y);
    private:
        std::unordered_map<SDL_Scancode, InputType> input_map;
};