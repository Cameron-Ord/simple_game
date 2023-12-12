#include "include/inputs.hpp"
#include <iostream>

Movement_Inputs::Movement_Inputs(){
    input_map[SDL_SCANCODE_SPACE] = InputType::SPACE;
    input_map[SDL_SCANCODE_DOWN] = InputType::DOWN;
    input_map[SDL_SCANCODE_LEFT] = InputType::LEFT;
    input_map[SDL_SCANCODE_RIGHT] = InputType::RIGHT;
}


void Movement_Inputs::key_down(SDL_Scancode scancode, int* x, int* y){
    std::unordered_map<SDL_Scancode, InputType>::iterator iter = input_map.find(scancode);
    if(iter != input_map.end()){
        InputType input_type = iter->second;
        switch (input_type){
            case InputType::SPACE:
                *y -= 100;
                break;
            case InputType::DOWN:
                *y += 8;
                break;
            case InputType::LEFT:
                *x -= 8;
                break;
            case InputType::RIGHT:
                *x += 8;
                break;
            default:
                break;
        }
    }
}

void Movement_Inputs::key_release(SDL_Scancode scancode, int* x, int* y){
    std::unordered_map<SDL_Scancode, InputType>::iterator iter = input_map.find(scancode);
    if(iter != input_map.end()){
        InputType input_type = iter->second;
        switch (input_type){
            case InputType::SPACE:
                *y -= -100;
                break;
            case InputType::DOWN:
                *y += 2;
                break;
            case InputType::LEFT:
                *x -= 2;
                break;
            case InputType::RIGHT:
                *x += 2;
                break;
            default:
                break;
        }
    }
}

void Movement_Inputs::take_input(int* x, int* y){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        SDL_Scancode scancode = event.key.keysym.scancode;
        switch (event.type){
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            if(event.key.repeat == 0){
                key_down(scancode, x, y);
            } else {
                key_down(scancode, x, y);
            }
            break;
        case SDL_KEYUP:
            key_release(scancode, x, y);
            break;
        default:
            break;
        }
    }
}