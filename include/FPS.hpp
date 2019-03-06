/*
 * FPS.hpp
 *
 * Created by Viacheslav Borisenko
 *
 * Copyright (c) 2019 spectrobyte http://spectrobyte.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#ifndef FIREWORK_FPS_HPP
#define FIREWORK_FPS_HPP

#include <memory>
#include "SFML/Graphics.hpp"

class FPS
{
public:
  FPS(sf::RenderWindow& window, const std::string& font, unsigned int fontSize, float positionX, float positionY);

  void SetElapsedTime(float);
  void Draw();

private:
  sf::RenderWindow& _window;
  sf::Font _font;
  sf::Text _label;
  sf::Text _fps;
};

#endif //FIREWORK_FPS_HPP
