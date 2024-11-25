#include "Obstacle.h"

Obstacle::Obstacle(int x, int y, int w, int h)
    : rect{ x, y, w, h }, speed(1) {
}

void Obstacle::update() {
    // Movimiento simple del obstáculo (por ejemplo, de izquierda a derecha)
    rect.x -= speed;
    if (rect.x + rect.w < 0) { // Si sale de la pantalla, reiniciarlo
        rect.x = 800; // La pantalla tiene 800px de ancho
    }
}

void Obstacle::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Color rojo
    SDL_RenderFillRect(renderer, &rect);
}

const SDL_Rect& Obstacle::getRect() const {
    return rect; // Devuelve una referencia constante al rectángulo
}
