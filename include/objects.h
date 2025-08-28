#pragma once

#include "app.h"
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

class Object {
public:
  Vector2 pos;
  Color color;
  bool solid;
  ObjectShape shape;
  std::vector<Transformations> transformations;

  virtual void draw();
  virtual void set_animation_duration_ms(int animation_duration_ms);
  virtual void start_animation();

  virtual void translate(Vector2);
  virtual void rotate(int angle_theta);
  virtual void scale(int s_x, int s_y);
  virtual void reflect(int x, int y);
  virtual void sheer(SheerDirection dir, int sh_x);

private:
  int animation_duration_ms;
};

class Rect : public virtual Object {
public:
  int width;
  int height;

  void draw() override;
  void set_animation_duration_ms(int animation_duration_ms) override;
  void start_animation() override;

  void translate(Vector2) override;
  void rotate(int angle_theta) override;
  void scale(int s_x, int s_y) override;
  void reflect(int x, int y) override;
  void sheer(SheerDirection dir, int sh_x) override;

  Rect(Vector2 start_pos, int width, int height, Color color, bool solid);
};

class Circle : public virtual Object {
public:
  int radius;

  void draw() override;
  void set_animation_duration_ms(int animation_duration_ms) override;
  void start_animation() override;

  void translate(Vector2) override;
  void rotate(int angle_theta) override;
  void scale(int s_x, int s_y) override;
  void reflect(int x, int y) override;
  void sheer(SheerDirection dir, int sh_x) override;

  Circle(Vector2 start_pos, int radius, Color color, bool solid);
};

class Triangle : public virtual Object {
public:
  Vector2 v1, v2, v3;

  void draw() override;
  void set_animation_duration_ms(int animation_duration_ms) override;
  void start_animation() override;

  void translate(Vector2) override;
  void rotate(int angle_theta) override;
  void scale(int s_x, int s_y) override;
  void reflect(int x, int y) override;
  void sheer(SheerDirection dir, int sh_x) override;

  Triangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color, bool solid);
};

class Line : public virtual Object {
public:
  Vector2 end_pos;

  void draw() override;
  void set_animation_duration_ms(int animation_duration_ms) override;
  void start_animation() override;

  void translate(Vector2) override;
  void rotate(int angle_theta) override;
  void scale(int s_x, int s_y) override;
  void reflect(int x, int y) override;
  void sheer(SheerDirection dir, int sh_x) override;

  Line(Vector2 start_pos, Vector2 end_pos, Color color, bool solid);
};

class Point : public virtual Object {
public:
  void draw() override;
  void set_animation_duration_ms(int animation_duration_ms) override;
  void start_animation() override;

  void translate(Vector2) override;
  void rotate(int angle_theta) override;
  void scale(int s_x, int s_y) override;
  void reflect(int x, int y) override;
  void sheer(SheerDirection dir, int sh_x) override;

  Point(Vector2 start_pos);
};
