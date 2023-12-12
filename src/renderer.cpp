#include "include/renderer.hpp"
#include <iostream>


Renderer::Renderer(int scr_width, int scr_height){
    int window_flags, render_flags;
    render_flags = SDL_RENDERER_ACCELERATED;
    window_flags = 0;

    window = SDL_CreateWindow("Metroidvania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, scr_width, scr_height, window_flags);
    if(window == NULL){
        printf("Could not create window: %s\n", SDL_GetError());
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, render_flags);
    if(renderer == NULL){
        printf("Could not create renderer: %s\n", SDL_GetError());
        exit(1);
    }
}

Renderer::~Renderer(){
    std::cout<<"Destroyed"<<std::endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

SDL_Texture* Renderer::load_texture(const char* filename){
    SDL_Texture* texture;
    texture = IMG_LoadTexture(renderer, filename);
        if(texture == NULL){
        printf("SDL TEXTURE ERROR: %s\n", SDL_GetError());
    }
    return texture;
}

void Renderer::draw_player(int* x, int* y, SDL_Texture* player_texture){
    SDL_Rect destination;
    destination.x = *x;
    destination.y = *y;
    destination.w = 82;
    destination.h = 82;
    int err = SDL_RenderCopy(renderer, player_texture, NULL, &destination);
    if(err < 0){
        printf("SDL TEXTURE ERROR: %s\n", SDL_GetError());
    } 
}

void Renderer::prepare_scene(){
    SDL_RenderClear(renderer);
}

void Renderer::present_scene(){
    SDL_RenderPresent(renderer);
}