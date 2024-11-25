#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL.h>

class Obstacle {
public:
    Obstacle(int x, int y, int w, int h);
    void update();
    void render(SDL_Renderer* renderer);
    const SDL_Rect& getRect() const; // Devuelve una referencia constante

private:
    SDL_Rect rect; // Posici�n y tama�o del obst�culo
    float speed;     // Velocidad del obst�culo (si se mueve)
};

#endif
