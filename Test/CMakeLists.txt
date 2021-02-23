cmake_minimum_required(VERSION 3.12)

#set(CMAKE_CXX_STANDARD 11)
enable_testing()
set(CMAKE_AUTOMOC ON)

#Sets current dir as working dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
# 'googletest' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories( "../app")
include_directories( Test)
#include("../QT_helloworld/imageInfo.h" )
find_package(Qt6 COMPONENTS Core Qml Quick REQUIRED)
set( proj_HEADER
        ../app/include/imageInfo.h
        )
add_executable(InfoImage imageInfoTests.cpp ../app/src/imageInfo.cpp ../app/src/urlreader.cpp ../app/src/randomgenerator.cpp ${proj_HEADER})
#set_target_properties(InfoImage  PROPERTIES AUTOMOC TRUE)

#add_library(InfoImage SHARED "../QT_helloworld/imageInfo.h" "../QT_helloworld/imageInfo.cpp" )

target_link_libraries(InfoImage PUBLIC gtest gmock gtest_main  Qt6::Core Qt6::Qml)
#target_include_directories(InfoImage "../QT_helloworld")
#"../QT_helloworld/imageInfo.cpp"
