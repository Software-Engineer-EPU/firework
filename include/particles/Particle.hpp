
/*
 * Particle.hpp
 *
 * Created by Viacheslav Borisenko
 *
 * Copyright (c) 2019 spectrobyte http://spectrobyte.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#ifndef FIREWORK_PARTICLE_HPP
#define FIREWORK_PARTICLE_HPP

#include <SFML/Graphics.hpp>

struct Particle : public sf::Drawable
{
  sf::Vertex _vertex;
  sf::Vector2f _direction;
  float _acceleration;
  float _resistance;
  float _mass;
  float _ttl;

  Particle(const sf::Vertex& vertex, const sf::Vector2f& direction, float acceleration, float resistance, float mass, float ttl) :
  _vertex(vertex), _direction(direction), _acceleration(acceleration), _resistance(resistance), _mass(mass), _ttl(ttl) {}

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override
  {
    target.draw(&_vertex, 1, sf::Points, states);
  }
};

using ParticlePtr = std::shared_ptr<Particle>;

#endif //FIREWORK_PARTICLE_HPP
