#pragma once

#include "defs.h"
#include <cstdlib>
#include <raylib.h>

class Pos2 {
public:
  int x;
  int y;

  Vector2 to_vec2() {
    Vector2 vec_pos{0, 0};
    if (x >= 0) {
      vec_pos.x = (GetScreenWidth() / 2.0) + (GRID_SIZE * x);
    }
    if (x < 0) {
      vec_pos.x = (GetScreenWidth() / 2.0) - (GRID_SIZE * abs(x));
    }

    if (y >= 0) {
      vec_pos.y = (GetScreenHeight() / 2.0) - (GRID_SIZE * y);
    }
    if (y < 0) {
      vec_pos.y = (GetScreenHeight() / 2.0) + (GRID_SIZE * y);
    }
    return vec_pos;
  }
};

typedef enum class PreDefBackgrounds {
  Black,
  White,
  Grey,
} PreDefBackgrounds;

typedef enum GraphLinesColor { Black, White } GraphLinesColor;

typedef enum Transformations {
  Translation,
  Rotation,
  Scaling,
  Sheering,
  Reflection,
  End,
} Screens,
    Transformations;

class AppState {
public:
  PreDefBackgrounds background;
  GraphLinesColor graph_color;

  Screens current_transformation;
  int window_width;
  int window_height;

  AppState(PreDefBackgrounds bg, GraphLinesColor glc, Screens ct, int width,
           int height) {
    background = bg;
    current_transformation = ct;
    window_width = width;
    window_height = height;
    graph_color = glc;
  }

  void switch_background() {
    this->background = PreDefBackgrounds((int(this->background) + 1) % 3);
  }
};
