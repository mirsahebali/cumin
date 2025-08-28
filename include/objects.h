#pragma once

#include "app.h"
#include <math.h>
#include <raylib.h>
#include <vector>

typedef enum class ObjectShape {
  Rect,
  Circle,
  Triangle,
  Line,
  Point,
  End
} Objects;

typedef enum SheerDirection { X, Y } SheerDirection;

typedef struct TransformationData {
  Transformations transformation;
  float matrix[3][3];
} TransformationData;

class Object {
public:
  Vector2 pos;
  Color color;
  bool solid;
  ObjectShape shape;
  std::vector<TransformationData> transformations;

  virtual void draw();
  virtual void set_animation_duration_ms(int animation_duration_ms);
  virtual void start_animation();

  void translate(int tx, int ty);
  void rotate(int angle_theta);
  void scale(int s_x, int s_y);
  void sheer(SheerDirection dir, int sh_factor);
  // TODO: we'll tackle this a bit later
  void reflect(int x, int y);
};

class Rect : public virtual Object {
public:
  int width;
  int height;

  void draw() override;
  void set_animation_duration_ms(int animation_duration_ms) override;
  void start_animation() override;

  Rect(Vector2 start_pos, int width, int height, Color color, bool solid);

private:
  int animation_duration_ms;
  int animation_elapsed = 0;
};

class Circle : public virtual Object {
public:
  int radius;

  void draw() override;
  void set_animation_duration_ms(int animation_duration_ms) override;
  void start_animation() override;

  Circle(Vector2 start_pos, int radius, Color color, bool solid);

private:
  int animation_duration_ms;
  int animation_elapsed = 0;
};

class Triangle : public virtual Object {
public:
  Vector2 v1, v2, v3;

  void draw() override;
  void set_animation_duration_ms(int animation_duration_ms) override;
  void start_animation() override;

  Triangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color, bool solid);

private:
  int animation_duration_ms;
  int animation_elapsed = 0;
};

class Line : public virtual Object {
public:
  Vector2 end_pos;

  void draw() override;
  void set_animation_duration_ms(int animation_duration_ms) override;
  void start_animation() override;

  Line(Vector2 start_pos, Vector2 end_pos, Color color, bool solid);

private:
  int animation_duration_ms;
  int animation_elapsed = 0;
};

class Point : public virtual Object {
public:
  void draw() override;
  void set_animation_duration_ms(int animation_duration_ms) override;
  void start_animation() override;

  Point(Vector2 start_pos);

private:
  int animation_duration_ms;
  int animation_elapsed = 0;
};
