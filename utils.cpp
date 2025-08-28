#include "utils.h"
#include "app.h"
#include <raylib.h>

Color map_predef_to_color(PreDefBackgrounds bg) {
  switch (bg) {
  case PreDefBackgrounds::Black:
    return BLACK;
  case PreDefBackgrounds::White:
    return RAYWHITE;
  case PreDefBackgrounds::Grey:
    return GRAY;
  }
  return BLANK;
}

const char *screen_name(Screens screen) {
  switch (screen) {
  case Screens::Translation:
    return "Translation";
  case Screens::Rotation:
    return "Rotation";
  case Screens::Scaling:
    return "Scaling";
  case Screens::Reflection:
    return "Reflection";
  case Screens::Sheering:
    return "Sheering";
  default:
    return "";
  }
}

int calc_total_screen_tabs_text_width() {
  int total_width = 0;

  for (int i = Screens::Translation; i != Screens::End; i++) {

    Screens screen = static_cast<Screens>(i);

    int width = MeasureText(screen_name(screen), TABS_TEXT_FONT_SIZE);

    total_width += width;
  }

  return total_width;
}

bool is_mouse_above_rect(Rectangle rect) {
  Vector2 mouse_pos = GetMousePosition();

  int x = rect.x;
  int y = rect.y;
  int end_x = rect.x + rect.width;
  int end_y = rect.y + rect.height;

  if (mouse_pos.x > end_x || mouse_pos.x < x || mouse_pos.y > end_y ||
      mouse_pos.y < y) {
    return false;
  }

  return true;
}

Pos2 map_pixel_to_graph_coordinate(Vector2 pos) { return Pos2{0, 0}; }
