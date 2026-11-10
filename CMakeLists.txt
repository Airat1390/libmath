cmake_minimum_required(VERSION 3.22)
project(libmath LANGUAGES CXX)

add_library(libmath INTERFACE)

target_include_directories(libmath INTERFACE include/)

