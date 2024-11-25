#include "Player.h"

Player::Player(int x, int y, int w, int h)
    : rect{ x, y, w, h }, speed(1) {
}

void Player::update() {
    // Ejemplo de movimiento del jugador
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    if (state[SDL_SCANCODE_UP]) rect.y -= speed;
    if (state[SDL_SCANCODE_DOWN]) rect.y += speed;
    if (state[SDL_SCANCODE_LEFT]) rect.x -= speed;
    if (state[SDL_SCANCODE_RIGHT]) rect.x += speed;
}

void Player::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Color verde
    SDL_RenderFillRect(renderer, &rect);
}

const SDL_Rect& Player::getRect() const {
    return rect; // Devuelve una referencia constante al rectángulo
}
