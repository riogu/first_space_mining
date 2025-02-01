#include "constants.hpp"
#include "main_functions.hpp"
#include "objects/celestial_body.hpp"
#include "objects/n_body_simulation.hpp"
#include "raylib.h"
#include <memory>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
    SetTraceLogLevel(LOG_DEBUG);

    std::vector<std::shared_ptr<CelestialBody>> allBodies;

    auto first_simulation = first_simulation_test(allBodies);
    first_simulation->awake();

    InitWindow(screenWidth, screenHeight, "THIS... is a BUCKET.");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        ClearBackground(BLACK);
        BeginDrawing();

        // TraceLog(LOG_DEBUG, TextFormat("this is the other guy"));
        float frametime = GetFrameTime();

        first_simulation->update(frametime);

        update_screen(first_simulation);

        EndDrawing();
    }

    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void update_screen(const std::unique_ptr<NBodySimulation> &simulation) {
    // remember to delcare stuff as const when you have no intention of changing it
    // (only accessing information)
    for (const auto &body : simulation->bodies) {
        body->draw();
    }
}
// earth mass = 5.972 × 10^24 kg
// grav constant = 6.6743 × 10^-11 m3 kg-1 s-2
std::unique_ptr<NBodySimulation>
first_simulation_test(std::vector<std::shared_ptr<CelestialBody>> &allBodies) {
    // NOTE: not using all bodies atm
    std::shared_ptr body_smol = std::make_shared<CelestialBody>(
        30, 600000, (Vector2){0, 110}, (Vector2){screenWidth / 4, screenHeight / 2}, BLUE);
    std::shared_ptr body_beeg =
        std::make_shared<CelestialBody>(100, 9000000, (Vector2){0, 0}, screenCenter, RED);
    std::vector<std::shared_ptr<CelestialBody>> new_vec;
    // new_vec.reserve(2);
    new_vec.push_back(body_smol);
    new_vec.push_back(body_beeg);
    std::unique_ptr<NBodySimulation> first_sim = std::make_unique<NBodySimulation>(new_vec);
    return first_sim;
}
