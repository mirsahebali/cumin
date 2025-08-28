#pragma once

#include "app.h"
#include "raylib.h"

Color map_predef_to_color(PreDefBackgrounds bg);

const char *screen_name(Screens screen);

int calc_total_screen_text_width();

bool is_mouse_above_rect(Rectangle rect);
