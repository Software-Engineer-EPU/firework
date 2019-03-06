/*
 * main.cpp
 *
 * Created by Viacheslav Borisenko
 *
 * Copyright (c) 2019 spectrobyte http://spectrobyte.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "FPS.hpp"

#include "Firework.hpp"

#include "particles/Particle.hpp"
#include "particles/ParticleSystem.hpp"

using namespace std;
using namespace sf;

int main()
{
  sf::ContextSettings contextSettings;
  contextSettings.depthBits = 24;
  contextSettings.antialiasingLevel = 8;

  sf::Vector2f screenSize(1024, 768);
  sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Firework", sf::Style::Default, contextSettings);
  window.setKeyRepeatEnabled(false);
  window.setFramerateLimit(60);
  window.setVerticalSyncEnabled(true);

  sf::Texture texture;
  texture.loadFromFile("data/graphics/konig.png");

  sf::Sprite background;
  background.setTexture(texture);

  Texture binTexture;
  binTexture.loadFromFile("data/graphics/bin.png");
  binTexture.setSmooth(true);
  binTexture.setRepeated(false);

  Sprite bin;
  bin.setTexture(binTexture);
  bin.setOrigin(binTexture.getSize().x / 2.0f, binTexture.getSize().y / 2.0f);
  bin.setPosition(screenSize.x / 2, 700.0f);

  FPS fps(window, "data/fonts/arial.ttf", 24, 20.0f, screenSize.y - 40.0f);

  Firework firework;

  sf::Clock clock;
  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed ||
         (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
        window.close();
      }

      if(event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
          Vector2f position(event.mouseButton.x, event.mouseButton.y);
          if(bin.getGlobalBounds().contains(position)) {
            bin.setScale(0.9f, 0.9f);
          } else {
            firework.Shot(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
          }
        }
      }

      if(event.type == sf::Event::MouseButtonReleased) {
        if(event.mouseButton.button == sf::Mouse::Left) {
          Vector2f position(event.mouseButton.x, event.mouseButton.y);
          bin.setScale(1.0f, 1.0f);
          if(bin.getGlobalBounds().contains(position)) {
            firework.Clear();
          }
        }
      }
    }

    window.clear();

    sf::Time elapsed = clock.restart();
    float dt = elapsed.asSeconds();

    // drawing
    window.draw(background);

    firework.Update(dt);
    window.draw(firework);

    window.draw(bin);

    fps.SetElapsedTime(dt);
    fps.Draw();

    window.display();
  }

  return 0;
}