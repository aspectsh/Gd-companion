cmake_minimum_required(VERSION 3.16)
project(my.gd-companion)

list(APPEND CMAKE_PREFIX_PATH $ENV{GEODE_SDK})
set(Geode_DIR $ENV{GEODE_SDK})

find_package(Geode REQUIRED)

add_geode_library(${PROJECT_NAME} 
    GDCompanion.cpp 
)

