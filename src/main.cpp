#include "main_functions.hpp"
#include <memory>
#include <includes_header.hpp>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
    SetTraceLogLevel(LOG_DEBUG);

    std::vector<std::shared_ptr<CelestialBody>> allBodies;

    // auto first_simulation = orbiting_simulation(allBodies);
    auto first_simulation = three_body_simulation(allBodies);
    first_simulation->awake();

    InitWindow(screenWidth, screenHeight, "THIS... is a BUCKET.");

    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        ClearBackground(BLACK);
        BeginDrawing();
        int this_is_code = 3213123;
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
