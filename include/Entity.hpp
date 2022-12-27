#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Vector2f.hpp>

class Entity
{
private:
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
    unsigned char opacity;
public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex, int w, int h, unsigned char p_opacity);
    Vector2f& position();
    SDL_Rect getCurrentFrame();
    SDL_Texture* getTex();
    unsigned char getOpacity();
};