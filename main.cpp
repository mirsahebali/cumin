#include <math.h>
#include <raylib.h>

#include <stdbool.h>
#include <stdlib.h>

#include "app.h"
#include "objects.h"
#include "render.h"
#include "utils.h"

int main(int argc, char *argv[]) {

  SetTargetFPS(60);
  SetConfigFlags(FLAG_FULLSCREEN_MODE);

  InitWindow(1920, 1080, "Cumin");

  int current_monitor = GetCurrentMonitor();
  int screen_width = GetScreenWidth();
  int screen_height = GetScreenHeight();

  Camera2D camera = {};
  camera.target =
      Vector2{.x = float(screen_width / 2.0), .y = float(screen_height / 2.0)};
  camera.offset =
      Vector2{.x = float(screen_width / 2.0), .y = float(screen_height / 2.0)};
  camera.rotation = 0;
  camera.zoom = 1.0f;

  Rect rect1(Pos2{0, 0}, 3, 3, BLUE, true);

  AppState *app_state =
      new AppState(PreDefBackgrounds::Black, GraphLinesColor::White,
                   Screens::Translation, screen_width, screen_height);

  while (!WindowShouldClose()) {

    // handle user input events
    if ((IsKeyDown(KEY_LEFT_SHIFT) || (IsKeyDown(KEY_RIGHT_SHIFT))) &&
        IsKeyPressed(KEY_TAB)) {
      app_state->switch_background();
    }

    // Camera zoom controls
    // Uses log scaling to provide consistent zoom speed
    camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove() * 0.1f));

    if (camera.zoom > 3.0f)
      camera.zoom = 3.0f;
    else if (camera.zoom < 0.1f)
      camera.zoom = 0.1f;

    BeginDrawing();
    ClearBackground(map_predef_to_color(app_state->background));

    BeginMode2D(camera);

    rect1.draw();

    draw_graph(app_state->window_width, app_state->window_height);
    draw_x_y_axis(app_state->window_width, app_state->window_height);
    draw_origin_marking(app_state);

    EndMode2D();

    draw_main_title(app_state->window_width, app_state->window_height);

    draw_switch_scene_button(app_state);

    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
