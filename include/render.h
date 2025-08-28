#pragma once
#include "app.h"

// setting each graph grid to be 10 pixel(Multiple of 40s is optimal)
#define GRID_SIZE 40
#define TABS_TEXT_FONT_SIZE 20

void draw_main_title(int screen_width, int screen_height);
void draw_graph(int screen_width, int screen_height);
void draw_switch_scene_button(AppState *state);
void draw_x_y_axis(int screen_width, int screen_height);

void draw_origin_marking(AppState *state);
