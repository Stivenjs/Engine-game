#include "Game.h"
#include "Player.h"
#include "Obstacle.h"
#include <vector>
#include <iostream>
Player player(400, 500, 50, 50); // Inicializar al jugador
std::vector<Obstacle> obstacles;

Game::Game() : window(nullptr), renderer(nullptr), isRunning(true) {}

Game::~Game() {
    clean();
}

void Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    window = SDL_CreateWindow(
        "Engine Game",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Error al crear la ventana: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Error al crear el renderizador: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    // Inicializar jugador y obstáculos
    player = Player(100, 100, 50, 50); // Posición inicial y tamaño
    obstacles.push_back(Obstacle(600, 200, 50, 50)); // Agregar un obstáculo
    obstacles.push_back(Obstacle(400, 300, 50, 50)); // Agregar otro obstáculo
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void Game::update() {
    player.update();
    for (auto& obstacle : obstacles) {
        obstacle.update();

        // Colisión entre jugador y obstáculo
        if (SDL_HasIntersection(&player.getRect(), &obstacle.getRect())) {
            std::cout << "¡Colisión! Fin del juego.\n";
            isRunning = false;
        }
    }
}

void Game::render() {
    // Establecer el color de fondo: (213, 216, 220) - Gris claro
    SDL_SetRenderDrawColor(renderer, 213, 216, 220, 255);
    SDL_RenderClear(renderer);

    // Renderizar jugador y obstáculos, u otros elementos
    player.render(renderer);
    for (auto& obstacle : obstacles) {
        obstacle.render(renderer);
    }

    // Mostrar lo renderizado
    SDL_RenderPresent(renderer);
}


void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::run() {
    init();
    while (isRunning) {
        handleEvents();
        update();
        render();
    }
}