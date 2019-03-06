cmake_minimum_required(VERSION 3.11)
project(firework)

set(CMAKE_CXX_STANDARD 11)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /MT")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /O2 /MT")
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(SFML_STATIC_LIBRARIES TRUE)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(firework ${SOURCE_FILES})

target_include_directories(firework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(firework sfml-graphics)

add_subdirectory(external)