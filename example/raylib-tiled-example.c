#include "raylib.h"

#define RAYLIB_TILED_IMPLEMENTATION
#include "raylib-tiled.h"

int main() {

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    Vector2 position = {0, 0};

    InitWindow(screenWidth, screenHeight, "raylib-tiled example");
    SetTargetFPS(60);

    Map map = LoadMap("resources/desert.json");
    if (!IsMapValid(map)) {
        TraceLog(LOG_ERROR, "Failed to load Map");
        return 1;
    }

    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_LEFT)) {
            position.x += 2;
        }
        if (IsKeyDown(KEY_UP)) {
            position.y += 2;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            position.x -= 2;
        }
        if (IsKeyDown(KEY_DOWN)) {
            position.y -= 2;
        }
        if (IsMouseButtonDown(0)) {
            Vector2 delta = GetMouseDelta();
            position.x += delta.x;
            position.y += delta.y;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawMap(map, (int)position.x, (int)position.y, RAYWHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadMap(map);             // Unload the Tiled map

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
