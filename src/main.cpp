#include <iostream>
#include <vector>
#include <random>

#include <Screen.hpp>
#include <Snow.hpp>
#include <Vector2f.hpp>

int main(int argc, char** argv)
{
    if(SDL_Init(SDL_INIT_VIDEO))
        std::cout << "SDL init failed. Error : " << SDL_GetError() << std::endl;

    Screen screen("SnowFlake", 1600, 800);

    SDL_Event event;

    SDL_Texture* snow = screen.loadTexture("res/gfx/snow.png");

    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> dis(0, 1);

    std::vector<Snow> entities;

    for(int i = 0; i < 50; i++)
    {
        Vector2f pos(dis(gen) * 1600, -1 * dis(gen) * 1000);
        Snow tempentity(pos, snow, 8, 8, (dis(gen) + 0.1) / 5 + 0.2);
        entities.push_back(tempentity);
    }

    bool gamerunning = true;

    Uint64 prevTicks = SDL_GetTicks64();
    Uint64 currentTicks;
    int frameTime;
    float t = 0;

    const float timeTick = 1000.0f / 144.0f;

    while(gamerunning)
    {
        currentTicks = SDL_GetTicks64();

        frameTime = currentTicks - prevTicks;

        t += frameTime;

        prevTicks = currentTicks;

        if(t >= timeTick)
        {
            const float alpha = t / timeTick;

            t -= timeTick;
        

            while(SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_QUIT:
                    {
                        gamerunning = false;
                        break;
                    }
                }
            }

            screen.clear();

            for(int i = 0; i < (int)entities.size(); i++)
            {
                screen.render(entities[i]);
                entities[i].position().y += entities[i].speed;

                if(entities[i].position().y > 800)
                {
                    entities.erase(entities.begin() + i);
                    i--;

                    Vector2f pos(dis(gen) * 1600, -1 * dis(gen) * 1000);
                    Snow tempentity(pos, snow, 8, 8, (dis(gen) + 0.1) / 5 + 0.2);
                    entities.push_back(tempentity);
                }
            }

            std::cout << alpha << std::endl;

            screen.display();
        }
    }

    screen.clean();
    SDL_Quit();

    return 0;
}