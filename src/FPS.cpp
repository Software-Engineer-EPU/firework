/*
 * FPS.cpp
 *
 * Created by Viacheslav Borisenko
 *
 * Copyright (c) 2019 spectrobyte http://spectrobyte.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "FPS.hpp"

using namespace std;

void FPS::Draw()
{
  _window.draw(_label);
  _window.draw(_fps);
}

void FPS::SetElapsedTime(float time)
{
  std::string fpsString = std::to_string(static_cast<int>(1.0f / time));
  _fps.setString(fpsString);
}

FPS::FPS(sf::RenderWindow& window, const std::string& font, unsigned int fontSize, float positionX, float positionY) : _window(window)
{
  _font.loadFromFile(font);

  _label.setFont(_font);
  _label.setString("FPS:");
  _label.setCharacterSize(fontSize);
  _label.setFillColor(sf::Color(0xaa, 0xaa, 0xaa));
  _label.setPosition(positionX, positionY);

  _fps.setFont(_font);
  _fps.setString("");
  _fps.setCharacterSize(fontSize);
  _fps.setFillColor(sf::Color(0xaa, 0xaa, 0xaa));
  _fps.setPosition(positionX + 60.0f, positionY);
}