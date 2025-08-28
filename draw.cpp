#include "draw.h"

#include "utils.h"

#include "string.h"
#include <cstdio>
#include <raylib.h>
#include <stdlib.h>

#define HOLLOW_RECT_THICKNESS 1

// Cumin specific rectangle drawing function.
// Here signed size of width and height determines the drawing direction of
// rectangle
// Eg size = (-3, 2)
void draw_rectangle(Vector2 start_pos, Vector2 size, bool is_filled,
                    Color color) {

  Vector2 end_pos_l1, end_pos_l2, end_pos_l3, end_pos_l4;

  unsigned int size_x = abs(size.x);
  unsigned int size_y = abs(size.y);

  // setting end value of l1... moves in x direction
  if (size.x < 0) {
    end_pos_l1.x = start_pos.x - size_x;
  } else {
    end_pos_l1.x = start_pos.x + size_x;
  }
  end_pos_l1.y = start_pos.y;
  DrawLineEx(start_pos, end_pos_l1, HOLLOW_RECT_THICKNESS, color);

  // setting end value of l2... moves in y direction
  Vector2 start_pos_l2 = end_pos_l1;
  if (size.y < 0) {
    end_pos_l2.y = start_pos_l2.y + size_y;
  } else {
    end_pos_l2.y = start_pos_l2.y - size_y;
  }
  end_pos_l2.x = start_pos_l2.x;
  DrawLineEx(start_pos_l2, end_pos_l2, HOLLOW_RECT_THICKNESS, color);

  // setting end value of l3... moves in x direction
  Vector2 start_pos_l3 = end_pos_l2;
  if (size.x < 0) {
    end_pos_l3.x = start_pos_l3.x + size_x;
  } else {
    end_pos_l3.x = start_pos_l3.x - size_x;
  }
  end_pos_l3.y = start_pos_l3.y;
  DrawLineEx(start_pos_l3, end_pos_l3, HOLLOW_RECT_THICKNESS, color);

  // setting end value of l4... moves in y direction
  Vector2 start_pos_l4 = end_pos_l3;
  if (size.y < 0) {
    end_pos_l4.y = start_pos_l4.y - size_y;
  } else {
    end_pos_l4.y = start_pos_l4.y + size_y;
  }
  end_pos_l4.x = start_pos_l4.x;
  DrawLineEx(start_pos_l4, end_pos_l4, HOLLOW_RECT_THICKNESS, color);

  if (!is_filled) {
    return;
  }

  if (size.y < 0) {
    for (int y = start_pos.y + size_y; y > start_pos.y; y--) {
      DrawLineEx(Vector2{start_pos.x, static_cast<float>(y)},
                 Vector2{start_pos.x + size.x, static_cast<float>(y)}, 1,
                 color);
    }
    return;
  }
  for (int y = start_pos.y - size_y; y < start_pos.y; y++) {
    DrawLineEx(Vector2{start_pos.x, static_cast<float>(y)},
               Vector2{start_pos.x + size.x, static_cast<float>(y)}, 1, color);
  }
}

void draw_mouse_hover_coordinates() {

  Vector2 mouse_pos = GetMousePosition();
  Pos2 graph_pos = map_pixel_to_graph_coordinate(mouse_pos);

  char pos_text[20];

  std::sprintf(pos_text, "( %d , %d )", graph_pos.x, graph_pos.y);

  DrawText(pos_text, mouse_pos.x + 10, mouse_pos.y - 20, 20, WHITE);
}
