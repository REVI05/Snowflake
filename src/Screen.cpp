#include<Screen.hpp>

#include <SDL2/SDL.h>
#include <iostream>

Screen::Screen(const char* p_title, int p_w, int p_h)
    : window(nullptr), renderer(nullptr)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* Screen::loadTexture(const char* p_filepath)
{
    SDL_Texture* tex = IMG_LoadTexture(renderer, p_filepath);

    if(tex == nullptr)
    {
        std::cout << "Can not load texture. Error : " << SDL_GetError() << std::endl;
    }

    return tex;
}

void Screen::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void Screen::clear()
{
    SDL_RenderClear(renderer);
}

void Screen::render(Entity& p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.position().x;
    dst.y = p_entity.position().y;
    dst.w = p_entity.getCurrentFrame().w;
    dst.h = p_entity.getCurrentFrame().h;

    SDL_SetTextureAlphaMod(p_entity.getTex(), p_entity.getOpacity());
    SDL_SetTextureBlendMode(p_entity.getTex(), SDL_BLENDMODE_BLEND);

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void Screen::display()
{
    SDL_RenderPresent(renderer);
}