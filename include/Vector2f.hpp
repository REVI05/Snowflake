#pragma once

#include <iostream>

class Vector2f
{
public:
    float x, y;

    Vector2f()
        : x(0.0f), y(0.0f)
    {}

    Vector2f(float p_x,float p_y)
        : x(p_x), y(p_y)
    {}

    friend std::ofstream& operator<<(std::ofstream& outputStream, Vector2f& p_entity)
    {
        std::cout << p_entity.x << ',' << p_entity.y;

        return outputStream;
    }
};