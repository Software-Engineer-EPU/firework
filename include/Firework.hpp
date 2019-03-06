
/*
 * Firework.hpp
 *
 * Created by Viacheslav Borisenko
 *
 * Copyright (c) 2019 spectrobyte http://spectrobyte.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#ifndef FIREWORK_FIREWORK_HPP
#define FIREWORK_FIREWORK_HPP

#include <vector>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Chaos.hpp"
#include "Shell.hpp"
#include "particles/ParticleSystem.hpp"

class Firework : public sf::Drawable
{
public:
  Firework();
  void Shot(const sf::Vector2f& destination);

  void Update(float dt);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void Clear();
private:
  std::vector<std::shared_ptr<Shell>> _shells;
  ParticleSystem _particleSystem;

  void cleanUp();
};

#endif //FIREWORK_FIREWORK_HPP
