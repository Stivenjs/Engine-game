#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

class Player {
public:
    Player(int x, int y, int w, int h);
    void update();
    void render(SDL_Renderer* renderer);
    const SDL_Rect& getRect() const; // Devuelve una referencia constante

private:
    SDL_Rect rect; // Posición y tamaño del jugador
    int speed;     // Velocidad del jugador
};

#endif
