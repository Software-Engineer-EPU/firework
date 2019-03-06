/*
 * Singleton.hpp
 *
 * Created by Viacheslav Borisenko
 *
 * Copyright (c) 2018 spectrobyte http://spectrobyte.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#ifndef SBGF_SINGLETON_HPP
#define SBGF_SINGLETON_HPP

template<typename T>
class Singleton
{
  friend T;
public:
  virtual ~Singleton() = default;

  static T* Instance()
  {
    static T t;
    return &t;
  }

private:
  Singleton() = default;
};

#endif //SBGF_SINGLETON_HPP
