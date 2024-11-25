#ifndef GAME_H
#define GAME_H

#include <SDL.h>

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

    void init();
    void handleEvents();
    void update();
    void render();
    void clean();
};

#endif
