
/*
 * Shell.cpp
 *
 * Created by Viacheslav Borisenko
 *
 * Copyright (c) 2019 spectrobyte http://spectrobyte.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "Shell.hpp"

using namespace sf;
using namespace std;

const std::array<Color, 6> Shell::_colors =
        {
                Color(199, 248, 29),
                Color(106, 248, 29),
                Color(29, 248, 142),
                Color(29, 235, 248),
                Color(246, 69, 248),
                Color(179, 69, 248)
        };

std::vector<std::shared_ptr<Particle>> Shell::GetExhaustParticles()
{
  std::vector<std::shared_ptr<Particle>> particles;

  for(int i = 0; i < 10; i++) {
    float angle = Chaos::Instance()->GetRandom(0.0f, static_cast<float>(2.0f * M_PI));

    particles.emplace_back(new Particle(Vertex(_position, Color(242, 125, 13)), Vector2f(cos(angle), sin(angle)), 50.0f, 0.0f, 0.0f, 100.0f));
  }

  return particles;
}

std::vector<std::shared_ptr<Particle>> Shell::GetExplosionParticles()
{
  std::vector<std::shared_ptr<Particle>> particles;
  auto step = 360.0f / 50.0f;
  for(int i = 0; i < 50; i++) {
    auto angle = i * step;
    auto radians = angle * M_PI / 180.0f;

    particles.emplace_back(new Particle(Vertex(_position, _color), Vector2f(cos(radians), sin(radians)), 50.0f, 50.0f, Chaos::Instance()->GetRandom(0.2f, 1.0f), 500.0f));
  }

  return particles;
}

std::vector<std::shared_ptr<Particle>> Shell::GetBigExplosionParticles()
{
  std::vector<std::shared_ptr<Particle>> particles;
  auto step = 360.0f / 50.0f;
  for(int i = 0; i < 50; i++) {
    auto angle = i * step;
    auto radians = angle * M_PI / 180.0f;

    particles.emplace_back(new Particle(Vertex(_position, _color), Vector2f(cos(radians), sin(radians)), 50.0f, 10.0f, Chaos::Instance()->GetRandom(0.5f, 1.0f), 2000.0f));
  }

  return particles;
}

void Shell::Update(float dt)
{
  _position += _direction * _speed * dt;

  auto distance = getDistance();
  if(distance > _distance) {
    _arrived = true;
  }
  _distance = distance;
}

bool Shell::Arrived() const
{
  return _arrived;
}

sf::Vector2f Shell::GetPosition()
{
  return _position;
}

int Shell::GetWave()
{ return _wave; }

void Shell::SetWave(int val)
{ _wave = val; }

Shell::Figure Shell::GetFigure()
{ return _figure; }

sf::Color Shell::GetColor()
{ return _color; }

float Shell::getDistance() const
{
  float dx = _destination.x - _position.x;
  float dy = _destination.y - _position.y;

  return std::sqrt(dx * dx + dy * dy);
}

Shell::Shell(const Figure& figure, const sf::Color& color, const sf::Vector2f& position,
             const sf::Vector2f& destination, float speed, int wave) :
        _figure(figure), _color(color), _position(position), _destination(destination), _speed(speed), _arrived(false),
        _wave(wave)
{
  float dx = _destination.x - _position.x;
  float dy = _destination.y - _position.y;

  float length = std::sqrt(dx * dx + dy * dy);
  _distance = length;
  length = 1.0f / length;
  _direction.x = dx * length;
  _direction.y = dy * length;
}

Shell::Shell(const Figure& figure, const sf::Color& color, const sf::Vector2f& position, float angle, float distance,
             float speed, int wave) :
        _figure(figure), _color(color), _position(position), _distance(distance), _speed(speed), _arrived(false),
        _wave(wave)
{
  auto radians = angle * M_PI / 180.0f;
  _direction.x = static_cast<float>(cos(radians));
  _direction.y = static_cast<float>(sin(radians));
  _destination = _position + _distance * _direction;
}

Shell::Shell() : _figure(Figure::CIRCLE), _color(sf::Color::White), _position(Vector2f(0, 0)),
                 _destination(Vector2f(0, 0)), _distance(0),
                 _speed(0), _arrived(false), _wave(0)
{}