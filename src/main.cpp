#include "constants.hpp"
#include "main_functions.hpp"
#include "objects/n_body_simulation.hpp"
#include "raylib.h"
#include <memory>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
    SetTraceLogLevel(LOG_DEBUG);

    std::vector<std::shared_ptr<CelestialBody>> allBodies;

    auto first_simulation = four_body_simulation(allBodies);
    // first_simulation->awake();

    InitWindow(screenWidth, screenHeight, "THIS... is a BUCKET.");

    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        ClearBackground(BLACK);
        BeginDrawing();
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
    simulation->draw_bodies();
    // simulation->draw_orbits(60);
    // TODO: implementing orbits
    // simulation->bodies[0]->draw_orbit(60);
    DrawLineBezier(simulation->bodies[1]->position, simulation->bodies[0]->position, 2.0f, PURPLE);
    // DrawLineBezier(simulation->bodies[1]->position, simulation->bodies[2]->position, 2.0f, PURPLE);
    DrawLineBezier(simulation->bodies[3]->position, simulation->bodies[2]->position, 2.0f, PURPLE);
}
