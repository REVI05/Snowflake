#pragma once

#include <Entity.hpp>

class Snow : public Entity
{
public:
    float speed;

    Snow(Vector2f p_pos, SDL_Texture* p_tex, int w, int h, float p_speed)
        : Entity(p_pos, p_tex, w, h), speed(p_speed)
    {}
    Snow(Entity p_entity, float p_speed)
        :Entity(p_entity), speed(p_speed)
    {}
};