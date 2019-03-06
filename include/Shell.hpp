
/*
 * Shell.hpp
 *
 * Created by Viacheslav Borisenko
 *
 * Copyright (c) 2019 spectrobyte http://spectrobyte.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#ifndef FIREWORK_SHELL_HPP
#define FIREWORK_SHELL_HPP

#define _USE_MATH_DEFINES

#include <math.h>
#include <array>
#include <memory>
#include <SFML/Graphics.hpp>
#include "particles/Particle.hpp"
#include "Chaos.hpp"

class Shell
{
public:
  enum class Figure { CIRCLE, STAR };
  static const std::array<sf::Color, 6> _colors;

  Shell();

  Shell(const Figure& figure, const sf::Color& color, const sf::Vector2f& position, const sf::Vector2f& destination, float speed, int wave);

  /*
   * @angle in degrees
   */
  Shell(const Figure& figure, const sf::Color& color, const sf::Vector2f& position, float angle, float distance, float speed, int wave);

  void Update(float dt);

  bool Arrived() const;

  std::vector<std::shared_ptr<Particle>> GetExhaustParticles();

  std::vector<std::shared_ptr<Particle>> GetExplosionParticles();

  std::vector<std::shared_ptr<Particle>> GetBigExplosionParticles();

  sf::Vector2f GetPosition();

  int GetWave();

  void SetWave(int val);

  Figure GetFigure();

  sf::Color GetColor();

private:
  sf::Vector2f _position;
  sf::Vector2f _destination;
  sf::Vector2f _direction;
  Figure _figure;
  sf::Color _color;
  float _speed;
  float _distance;
  bool _arrived;
  int _wave;

  float getDistance() const;
};

#endif //FIREWORK_SHELL_HPP
