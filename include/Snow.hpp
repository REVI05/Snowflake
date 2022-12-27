#pragma once

#include <Entity.hpp>

class Snow : public Entity
{
public:
    float speed;
    int swing;
    float swingspeed;
    int swinginde;
    int swingdir;

    Snow(Vector2f p_pos, SDL_Texture* p_tex, int w, int h, unsigned char p_opacity, float p_speed, int p_swing, float p_swingspeed, int p_swingdir)
        : Entity(p_pos, p_tex, w, h, p_opacity), speed(p_speed), swing(p_swing), swingspeed(p_swingspeed * p_swing), swinginde(1), swingdir(p_swingdir)
    {}
    Snow(Entity p_entity, float p_speed, int p_swing,int p_swingspeed, int p_swingdir)
        :Entity(p_entity), speed(p_speed), swing(p_swing), swingspeed(p_swingspeed * p_swing), swinginde(1), swingdir(p_swingdir)
    {}
};