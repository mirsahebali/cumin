#include "render.h"
#include "app.h"
#include "colors.h"
#include "utils.h"

#include <raylib.h>

#define HEADER_FONT_SIZE 25.0

void draw_switch_scene_button(AppState *state) {
  int height = state->window_height;
  int total_text_width = calc_total_screen_text_width();

  int start_x = (state->window_width / 2) - (total_text_width / 2);
  DrawRectangle(start_x - 10, height - 40, total_text_width + 60, 40, CYAN);

  int prev_text_size = 0;
  for (int screen_int = Screens::Translation; screen_int != Screens::End;
       screen_int++) {

    Screens screen = static_cast<Screens>(screen_int);

    const char *text = screen_name(screen);

    int text_size = MeasureText(text, TABS_TEXT_FONT_SIZE);

    int x_pos = start_x + prev_text_size;

    prev_text_size = prev_text_size + text_size + 10;

    Rectangle text_container = Rectangle{
        .x = float(x_pos - 5),
        .y = float(height - 35),
        .width = float(text_size + 10),
        .height = float(30),
    };

    bool is_mouse_hover = is_mouse_above_rect(text_container);

    if (is_mouse_hover) {
      DrawRectangleRec(text_container, LIGHTGREEN);
    }

    if (is_mouse_hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      state->current_transformation = screen;
      DrawRectangleRec(text_container, RED);
    }

    if (state->current_transformation == Screens(screen_int)) {
      DrawRectangleRec(text_container, LIGHTBLUE);
    }
    DrawText(screen_name(screen), x_pos, height - 30, TABS_TEXT_FONT_SIZE,
             DARKGREEN);
  }
}

void draw_graph(int screen_width, int screen_height) {
  int rows = screen_height / GRID_SIZE;
  int cols = screen_width / GRID_SIZE;

  // INFO: Draw rows
  for (int i = 0; i <= rows; i++) {
    DrawLine(0, i * GRID_SIZE, screen_width, i * GRID_SIZE, GRAY);
  }

  // INFO: Draw cols
  for (int i = 0; i <= cols; i++) {
    DrawLine(i * GRID_SIZE, 0, i * GRID_SIZE, screen_height, GRAY);
  }
}

void draw_x_y_axis(int screen_width, int screen_height) {

  int rows = screen_height / GRID_SIZE;
  int cols = screen_width / GRID_SIZE;

  // end x axis right before one grid
  int x_end = GRID_SIZE + ((cols - 2) * GRID_SIZE);
  // y of the x axis should be at the middle column line
  int x_axis_y_pos = (rows / 2) * GRID_SIZE;

  // draw x axis
  DrawLineEx((Vector2){GRID_SIZE, float(x_axis_y_pos)},
             (Vector2){float(x_end), float(x_axis_y_pos)}, 5.0, YELLOW);
  int y_end = GRID_SIZE + ((rows - 2) * GRID_SIZE);
  int y_axis_x_pos = (cols / 2) * GRID_SIZE;
  // draw y axis
  DrawLineEx((Vector2){float(y_axis_x_pos), GRID_SIZE},
             (Vector2){float(y_axis_x_pos), float(y_end)}, 5.0, YELLOW);
}

void draw_main_title(int screen_width, int screen_height) {
  const char *text = "2D TRANSFORMATIONS";
  int text_size = MeasureText(text, HEADER_FONT_SIZE);
  DrawText(text, (screen_width / 2) - (text_size / 2), 20.0, HEADER_FONT_SIZE,
           BLUE);
}
