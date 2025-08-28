#include <raylib.h>
#include <vector>

#include "objects.h"

Rect::Rect(Vector2 start_pos, int width, int height, Color color,
           bool is_solid) {
  this->pos = start_pos;
  this->width = width;
  this->height = height;
  this->color = color;
  this->solid = is_solid;
  this->shape = ObjectShape::Rect;
  this->transformations = std::vector<Transformations>();
}

void Rect::draw() {}
void Rect::set_animation_duration_ms(int animation_duration_ms) {};
void Rect::start_animation() {};

void Rect::translate(Vector2){};
void Rect::rotate(int angle_theta) {};
void Rect::scale(int s_x, int s_y) {};
void Rect::reflect(int x, int y) {};
void Rect::sheer(SheerDirection dir, int sh_x) {};

Circle::Circle(Vector2 start_pos, int radius, Color color, bool solid) {
  this->pos = start_pos;
  this->radius = radius;
  this->color = color;
  this->solid = solid;
  this->shape = ObjectShape::Circle;
  this->transformations = std::vector<Transformations>();
}

void Circle::draw() {}
void Circle::set_animation_duration_ms(int animation_duration_ms) {}
void Circle::start_animation() {}

void Circle::translate(Vector2) {}
void Circle::rotate(int angle_theta) {}
void Circle::scale(int s_x, int s_y) {}
void Circle::reflect(int x, int y) {}
void Circle::sheer(SheerDirection dir, int sh_x) {}

Triangle::Triangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color,
                   bool solid) {
  this->pos = v1;
  this->v1 = v1;
  this->v2 = v2;
  this->v3 = v3;
  this->color = color;
  this->solid = solid;
  this->shape = ObjectShape::Triangle;
  this->transformations = std::vector<Transformations>();
}

void Triangle::draw() {}
void Triangle::set_animation_duration_ms(int animation_duration_ms) {}
void Triangle::start_animation() {}

void Triangle::translate(Vector2) {}
void Triangle::rotate(int angle_theta) {}
void Triangle::scale(int s_x, int s_y) {}
void Triangle::reflect(int x, int y) {}
void Triangle::sheer(SheerDirection dir, int sh_x) {}

Line::Line(Vector2 start_pos, Vector2 end_pos, Color color, bool solid) {
  this->pos = start_pos;
  this->end_pos = end_pos;
  this->color = color;
  this->solid = solid;
  this->shape = ObjectShape::Line;
  this->transformations = std::vector<Transformations>();
}

void Line::draw() {}
void Line::set_animation_duration_ms(int animation_duration_ms) {}
void Line::start_animation() {}

void Line::translate(Vector2) {}
void Line::rotate(int angle_theta) {}
void Line::scale(int s_x, int s_y) {}
void Line::reflect(int x, int y) {}
void Line::sheer(SheerDirection dir, int sh_x) {}

Point::Point(Vector2 start_pos) {
  this->pos = start_pos;
  this->solid = true;
  this->shape = ObjectShape::Point;
  this->transformations = std::vector<Transformations>();
}

void Point::draw() {}
void Point::set_animation_duration_ms(int animation_duration_ms) {}
void Point::start_animation() {}

void Point::translate(Vector2) {}
void Point::rotate(int angle_theta) {}
void Point::scale(int s_x, int s_y) {}
void Point::reflect(int x, int y) {}
void Point::sheer(SheerDirection dir, int sh_x) {}
