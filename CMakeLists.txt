cmake_minimum_required(VERSION 3.20)
project(Task2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task2 main.cpp Film.cpp Film.h FeatureFilm.cpp FeatureFilm.h CartoonFilm.cpp CartoonFilm.h DocumentaryFilm.cpp DocumentaryFilm.h Random.cpp Random.h Container.cpp Container.h)
