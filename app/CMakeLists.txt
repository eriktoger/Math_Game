cmake_minimum_required(VERSION 3.12)
#project(Test)
#set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH ../../../Qt/6.0.1/gcc_64/lib/cmake)
#Sets current dir as working dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#include_directories( /app)
#include_directories( /app/include)
# h-files needed in qml has to be added to the executable
set( proj_HEADER
        include/question.h
        include/imageInfo.h
        )
add_executable(Game src/main.cpp qml/main.qml src/imageInfo.cpp src/question.cpp src/randomgenerator.cpp src/urlreader.cpp qml.qrc ${proj_HEADER})

find_package(Qt6 COMPONENTS Widgets Core Qml Quick  QuickControls2 REQUIRED)
target_link_libraries(Game PUBLIC Qt6::Quick Qt6::Widgets  Qt6::Core Qt6::Qml Qt6::QuickControls2)

