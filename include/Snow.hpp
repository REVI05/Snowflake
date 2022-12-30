#pragma once

#include <Entity.hpp>

class Snow : public Entity
{
public:
    float speed;
    int swing;
    float swingspeed;
    int swingdir;
    int swinginde;

    Snow(Vector2f p_pos, SDL_Texture* p_tex, int w, int h, unsigned char p_opacity, float p_speed, int p_swing, float p_swingspeed, int p_swingdir, int p_swinginde)
        : Entity(p_pos, p_tex, w, h, p_opacity), speed(p_speed), swing(p_swing), swingspeed(p_swingspeed), swingdir(p_swingdir), swinginde(p_swinginde)
    {}
    Snow(Entity p_entity, float p_speed, int p_swing,int p_swingspeed, int p_swingdir, int p_swinginde)
        :Entity(p_entity), speed(p_speed), swing(p_swing), swingspeed(p_swingspeed * p_swing), swingdir(p_swingdir), swinginde(p_swinginde)
    {}
};