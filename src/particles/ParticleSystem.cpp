
/*
 * ParticleSystem.cpp
 *
 * Created by Viacheslav Borisenko
 *
 * Copyright (c) 2019 spectrobyte http://spectrobyte.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "particles/ParticleSystem.hpp"

using namespace std;

void ParticleSystem::Emit(const std::vector<std::shared_ptr<Particle>>& particles)
{
  std::move(particles.begin(), particles.end(), std::back_inserter(_particles));
}

void ParticleSystem::cleanUp()
{
  _buffer.clear();
  _particles.erase(remove_if(_particles.begin(), _particles.end(),
          [](const shared_ptr<Particle>& particle) { return particle->_ttl < 0.0f; }), _particles.end());
}

void ParticleSystem::Update(float dt)
{
  cleanUp();

  auto step = dt * 1000.0f;
  for(auto& particle : _particles) {
    particle->_ttl -= step;
    auto fall = particle->_mass * _gravity;
    particle->_vertex.position += (particle->_direction + fall) * particle->_acceleration * dt;
    particle->_acceleration -= particle->_resistance * dt;
    _buffer.push_back(particle->_vertex);
  }
}

void ParticleSystem::Clear()
{
  _buffer.clear();
  _particles.clear();
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(&_buffer[0], _buffer.size(), sf::Points, states);
}

ParticleSystem::ParticleSystem(const sf::Vector2f& gravity) : _gravity(gravity)
{
  _particles.reserve(50000);
}