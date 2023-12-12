#include <SDL2/SDL.h>
#include <iostream>

#include "include/renderer.hpp"
#include "include/player.hpp"
#include "include/inputs.hpp"
int main(int argc, char* argv[]){
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        printf(
            "Couldn't init SDL VIDEO: %s\n", SDL_GetError()
        );
        return 1;
    }
    {
        int scr_width, scr_height;
        scr_width = 1280;
        scr_height = 720;
        Renderer renderer_obj(scr_width, scr_height);
        Player player_obj(&renderer_obj, scr_width, scr_height);
        SDL_Texture* player_texture = player_obj.get_texture();
        int* player_x = player_obj.get_x();
        int* player_y = player_obj.get_y();
        Movement_Inputs movement_inputs;


        bool game_running = true;
        while(game_running){
            renderer_obj.prepare_scene();
            movement_inputs.take_input(player_x, player_y);
            renderer_obj.draw_player(player_x, player_y, player_texture);
            renderer_obj.present_scene();
            SDL_Delay(16);
        }
    }

    SDL_Quit();
    return 0;
}