cmake_minimum_required(VERSION 3.16)
project(my.gd-companion)

find_package(Geode REQUIRED)

add_geode_library(${PROJECT_NAME} 
    GDCompanion.cpp 
)
