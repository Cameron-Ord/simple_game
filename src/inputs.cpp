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
                start_jump(y);
                break;
            case InputType::LEFT:
                std::cout<<"MOVING LEFT ON ON KEYDOWN: "<<moving_left<<std::endl;
                moving_left = true;
                break;
            case InputType::RIGHT:
                moving_right = true;
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
            case InputType::LEFT:
                std::cout<<"MOVING LEFT ON RELEASE: "<<moving_left<<std::endl;
                moving_left = false;
                break;
            case InputType::RIGHT:
                moving_right = false;
                break;
            default:
                break;
        }
    }
}

void Movement_Inputs::start_jump(int* y){
    std::cout <<"MOVING LEFT ON JUMP: "<<moving_left<<std::endl;
    std::cout<<"MOVING RIGHT ON JUMP: "<<moving_right<<std::endl;
    if(!is_jumping){
        is_jumping = true;
        jump_speed = 20.0;
        velocity = jump_speed;
        gravity = 1.0;
        initial_y = *y;
    }
}

void Movement_Inputs::update_jump(int* y) {
    if (is_jumping) {
        float float_y = static_cast<float>(*y);
        float_y -= velocity;
        velocity -= gravity;
        *y = static_cast<int>(float_y);
        if (*y == initial_y) {
            is_jumping = false;
        }
    }
}

void Movement_Inputs::handle_walk(int* x){
    if(moving_left){
        *x -= 8;
    } else if(moving_right){
        *x += 8;
    }
}

void Movement_Inputs::take_input(int* x, int* y){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        SDL_Scancode scancode = event.key.keysym.scancode;
        switch (event.type){
        case SDL_QUIT:
        std::cout<<"quiting"<<std::endl;
            exit(0);
            break;
        case SDL_KEYDOWN:
            key_down(scancode, x, y);
            break;
        case SDL_KEYUP:
            key_release(scancode, x, y);
            break;
        default:
            break;
        }
    }
    handle_walk(x);
    update_jump(y);

}