#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Entity.hpp>
#include <Vector2f.hpp>

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, int p_w, int p_h, unsigned char p_opacity)
    :pos(p_pos), tex(p_tex), opacity(p_opacity)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = p_w;
    currentFrame.h = p_h;
}

Vector2f& Entity::position()
{
    return pos;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

unsigned char Entity::getOpacity()
{
    return opacity;
}