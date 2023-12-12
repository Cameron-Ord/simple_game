#include "include/player.hpp"

int* Player::get_x(){
    return &x;
}
int* Player::get_y(){
    return &y;
}
SDL_Texture* Player::get_texture(){
    return player_texture;
}

Player::Player(Renderer* renderer_obj, int scr_width, int scr_height){
    player_texture = renderer_obj->load_texture("gfx/guy.jpg");
    x = scr_width / 2;
    y = scr_height / 2;
}

Player::~Player(){

}