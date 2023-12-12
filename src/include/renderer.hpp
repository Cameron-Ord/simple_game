#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Renderer {
    public:
        Renderer(int scr_width, int scr_height);
        ~Renderer();
        SDL_Texture* load_texture(const char* filename);
        void draw_player(int* x, int* y, SDL_Texture* player_texture);
        void prepare_scene();
        void present_scene();
    private:
        SDL_Renderer* renderer;
        SDL_Window* window;
};
