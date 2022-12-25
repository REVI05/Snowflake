#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Entity.hpp>

class Screen
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Screen(const char* title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filepath);
    void clean();
    void clear();
    void render(Entity& p_entity);
    void display();
};