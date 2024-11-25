#ifndef GAME_H
#define GAME_H

#include <SDL.h>


class Game {
public:
    Game();
    ~Game();

    void init();
    void handleEvents();
    void update();
    void render();
    void clean();
    void run();
    bool isRunning;


private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif
