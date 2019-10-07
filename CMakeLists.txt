cmake_minimum_required(VERSION 3.14)
project(GA C)

set(CMAKE_C_STANDARD 99)

add_executable(GA main.c constan.h initialize.h "individual_ calculator.h" Kieu_du_lieu.h adjust.h print.h parents_seletion.h crossover.h crossover.h mutation.h survivor_seletion.h calculator.h)