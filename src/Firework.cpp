
/*
 * Firework.cpp
 *
 * Created by Viacheslav Borisenko
 *
 * Copyright (c) 2019 spectrobyte http://spectrobyte.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "Firework.hpp"

using namespace sf;
using namespace std;

void Firework::Shot(const sf::Vector2f& destination)
{
  Vector2f position(Chaos::Instance()->GetRandom(0.0f, 1024.0f), 768.0f);

  auto figure = static_cast<Shell::Figure>(Chaos::Instance()->GetRandom(0, 1));
  int color = Chaos::Instance()->GetRandom(0, Shell::_colors.size() - 1);

  Shell* shell;
  if(figure == Shell::Figure::STAR){
    shell = new Shell(figure, Shell::_colors[color], position, destination, 300.0f, 2);
  } else {
    shell = new Shell(figure, Shell::_colors[color], position, destination, 300.0f, 1);
  }

  _shells.emplace_back(shell);
}

void Firework::Update(float dt)
{
  cleanUp();

  vector<shared_ptr<Shell>> temp;

  for(auto& shell : _shells) {
    shell->Update(dt);

    _particleSystem.Emit(shell->GetExhaustParticles());

    if(shell->Arrived()) {
      _particleSystem.Emit(shell->GetExplosionParticles());

      auto wave = shell->GetWave();
      if(wave == 0){
        _particleSystem.Emit(shell->GetBigExplosionParticles());
        continue;
      }

      if(shell->GetFigure() == Shell::Figure::STAR){
        auto step = 360.0f / 5;
        for(int i = 0; i < 5; i++) {
          auto distance = Chaos::Instance()->GetRandom(80.0f, 100.0f);
          auto speed = Chaos::Instance()->GetRandom(100.0f, 150.0f);
          auto angle = i * step;
          auto s = new Shell(shell->GetFigure(), shell->GetColor(), shell->GetPosition(), angle, distance, speed, wave - 1);
          temp.emplace_back(s);
        }
      } else {
        auto step = 360.0f / 10;
        for(int i = 0; i < 10; i++) {
          auto distance = Chaos::Instance()->GetRandom(80.0f, 100.0f);
          auto speed = Chaos::Instance()->GetRandom(100.0f, 150.0f);
          auto angle = i * step;
          auto s = new Shell(shell->GetFigure(), shell->GetColor(), shell->GetPosition(), angle, distance, speed, wave - 1);
          temp.emplace_back(s);
        }
      }
    }
  }

  if(!temp.empty()){
    std::move(temp.begin(), temp.end(), std::back_inserter(_shells));
  }

  _particleSystem.Update(dt);
}

void Firework::Clear()
{
  _shells.clear();
  _particleSystem.Clear();
}

void Firework::cleanUp()
{
  _shells.erase(std::remove_if(_shells.begin(), _shells.end(),
                               [](const shared_ptr<Shell>& shell) { return shell->Arrived(); }), _shells.end());
}

void Firework::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(_particleSystem, states);
}

Firework::Firework() : _particleSystem(ParticleSystem(Vector2f(0.0f, 0.5f)))
{

}