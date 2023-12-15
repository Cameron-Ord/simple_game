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
        void start_jump(int* y);
        void update_jump(int* y);
        void handle_walk(int* x);
    private:
        std::unordered_map<SDL_Scancode, InputType> input_map;
        bool is_jumping = false;
        int initial_y;
        float velocity;
        float gravity;
        float jump_speed;
        bool moving_right;
        bool moving_left;
};