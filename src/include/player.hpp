#pragma once
#include <SDL2/SDL.h>
#include "renderer.hpp"

class Player {
    public:
        Player(Renderer* renderer_obj, int scr_width, int scr_height);
        ~Player();
        SDL_Texture* get_texture();
        int* get_x();
        int* get_y();
    private:
        int x;
        int y;
        SDL_Texture* player_texture;
};