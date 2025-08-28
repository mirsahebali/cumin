#include <raylib.h>
#include <vector>

#include "defs.h"
#include "objects.h"

void Object::draw() {}
void Object::set_animation_duration_ms(int animation_duration_ms) {}
void Object::start_animation() {}

void Object::translate(int tx, int ty) {
  float matrix[3][3] = {{1, 0, float(tx)}, {0, 1, float(ty)}, {0, 0, 1}};

  TransformationData data{
      Transformations::Translation,
      **matrix,
  };

  this->transformations.push_back(data);
}

void Object::rotate(int angle_theta) {

  float matrix[3][3] = {{static_cast<float>(cos(angle_theta)),
                         static_cast<float>(-sin(angle_theta)), 0},
                        {static_cast<float>(sin(angle_theta)),
                         static_cast<float>(cos(angle_theta)), 0},
                        {0, 0, 1}};

  TransformationData data{
      Transformations::Rotation,
      **matrix,
  };

  this->transformations.push_back(data);
}

void Object::scale(int s_x, int s_y) {

  float matrix[3][3] = {{float(s_x), 0, 0}, {0, float(s_y), 0}, {0, 0, 1}};

  TransformationData data{
      Transformations::Scaling,
      **matrix,
  };

  this->transformations.push_back(data);
}

void Object::sheer(SheerDirection dir, int sh_factor) {
  float matrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  switch (dir) {
  case X:
    matrix[0][1] = float(sh_factor);
    break;

  case Y:
    matrix[1][0] = float(sh_factor);
    break;
  }

  TransformationData data{
      Transformations::Sheering,
      **matrix,
  };

  this->transformations.push_back(data);
}

Rect::Rect(Pos2 start_pos, int width, int height, Color color, bool is_solid) {
  this->pos = start_pos;
  this->width = width;
  this->height = height;
  this->color = color;
  this->solid = is_solid;
  this->shape = ObjectShape::Rect;
  this->transformations = std::vector<TransformationData>();
}

void Rect::draw() {
  Vector2 vec_pos = pos.to_vec2();
  int mapped_width = width * GRID_SIZE;
  int mapped_height = height * GRID_SIZE;
  if (solid) {
    DrawRectangle(vec_pos.x, vec_pos.y, mapped_width, mapped_height, color);
  } else {
    DrawRectangleLines(vec_pos.x, vec_pos.y, mapped_width, mapped_height,
                       color);
  }
}
void Rect::set_animation_duration_ms(int animation_duration_ms) {
  this->animation_duration_ms = animation_duration_ms;
};
void Rect::start_animation() {};

Circle::Circle(Pos2 start_pos, int radius, Color color, bool solid) {
  this->pos = start_pos;
  this->radius = radius;
  this->color = color;
  this->solid = solid;
  this->shape = ObjectShape::Circle;
  this->transformations = std::vector<TransformationData>();
}

void Circle::draw() {
  if (solid) {
    DrawCircle(pos.x, pos.y, radius, color);
  } else {
    DrawCircleLines(pos.x, pos.y, radius, color);
  }
}
void Circle::set_animation_duration_ms(int animation_duration_ms) {}
void Circle::start_animation() {}

Triangle::Triangle(Pos2 v1, Pos2 v2, Pos2 v3, Color color, bool solid) {
  this->pos = v1;
  this->v1 = v1;
  this->v2 = v2;
  this->v3 = v3;
  this->color = color;
  this->solid = solid;
  this->shape = ObjectShape::Triangle;
  this->transformations = std::vector<TransformationData>();
}

void Triangle::draw() {

  if (solid) {
    DrawTriangle(v1.to_vec2(), v2.to_vec2(), v3.to_vec2(), color);
  } else {
    DrawTriangleLines(v1.to_vec2(), v2.to_vec2(), v3.to_vec2(), color);
  }
}
void Triangle::set_animation_duration_ms(int animation_duration_ms) {}
void Triangle::start_animation() {}

Line::Line(Pos2 start_pos, Pos2 end_pos, Color color, bool solid) {
  this->pos = start_pos;
  this->end_pos = end_pos;
  this->color = color;
  this->solid = solid;
  this->shape = ObjectShape::Line;
  this->transformations = std::vector<TransformationData>();
}

void Line::draw() { DrawLine(pos.x, pos.y, end_pos.x, end_pos.y, color); }
void Line::set_animation_duration_ms(int animation_duration_ms) {}
void Line::start_animation() {}

Point::Point(Pos2 start_pos) {
  this->pos = start_pos;
  this->solid = true;
  this->shape = ObjectShape::Point;
  this->transformations = std::vector<TransformationData>();
}

void Point::draw() {
  DrawPixel(pos.x, pos.y, color);
  DrawCircleLines(pos.x, pos.y, 5, color);
}
void Point::set_animation_duration_ms(int animation_duration_ms) {}
void Point::start_animation() {}
