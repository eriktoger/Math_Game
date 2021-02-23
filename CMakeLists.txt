cmake_minimum_required(VERSION 3.12)
project(Math_Game)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wno-dev)
set(CMAKE_PREFIX_PATH "erik/home/Qt/6.0.1/gcc_64/lib/cmake/Qt6")
add_subdirectory(app)
add_subdirectory(Test)