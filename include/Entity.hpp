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
public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex, int w, int h);
    Vector2f& position();
    SDL_Rect getCurrentFrame();
    SDL_Texture* getTex();
};