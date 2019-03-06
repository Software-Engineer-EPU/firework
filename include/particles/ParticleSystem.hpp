
/*
 * ParticleSystem.hpp
 *
 * Created by Viacheslav Borisenko
 *
 * Copyright (c) 2019 spectrobyte http://spectrobyte.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#ifndef FIREWORK_PARTICLESYSTEM_HPP
#define FIREWORK_PARTICLESYSTEM_HPP

#include <vector>
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Particle.hpp"

class ParticleSystem : public sf::Drawable
{
public:
  explicit ParticleSystem(const sf::Vector2f& gravity);

  void Update(float dt);

  void Emit(const std::vector<std::shared_ptr<Particle>>& particles);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void Clear();
private:
  sf::Vector2f _gravity;
  std::vector<std::shared_ptr<Particle>> _particles;

  void cleanUp();
};

#endif //FIREWORK_PARTICLESYSTEM_HPP
