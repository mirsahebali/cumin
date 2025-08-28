#pragma once

#include <raylib.h>
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
  Reflection,
  Sheering,
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
