# Firework

fireworks simulation

## Requirements

- C++ 11;
- cmake 3.11;
- SFML

## Building

- ### Binaries
[bin](bin)

- ### Windows.
 using Developer Command Prompt for VS 2017:
```console
git clone https://github.com/jcoder39/firework.git
cd firework
git submodule update --init --recursive
git submodule update --remote
```
add #define _HAS_AUTO_PTR_ETC 1 to external\SFML\src\SFML\Audio\AudioDevice.cpp before any includings.
```console
mkdir build
cd build
cmake -DSFML_USE_STATIC_STD_LIBS=TRUE -DBUILD_SHARED_LIBS=FALSE -G "NMake Makefiles" ..
nmake
.\firework.exe
```

- ### Linux:
```console
git clone https://github.com/jcoder39/firework.git
cd firework
git submodule update --init --recursive
git submodule update --remote
mkdir build
cd build
cmake ..
make
./firework
```

## License

[The MIT License (MIT)](LICENSE)
