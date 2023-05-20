cmake_minimum_required(VERSION 3.16.3)
project(edd_pr_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(edd_pr_3
        codi-pr-3/ArbreBinari.cpp codi-pr-3/ArbreBinari.h
        codi-pr-3/NodeBinari.cpp codi-pr-3/NodeBinari.h
        codi-pr-3/main.cpp
        codi-pr-3/Movie.cpp codi-pr-3/Movie.h
        codi-pr-3/CercadorMoviesAB.cpp codi-pr-3/CercadorMoviesAB.h
        codi-pr-3/MinHeap.cpp codi-pr-3/MinHeap.h
        codi-pr-3/NodeHeap.cpp codi-pr-3/NodeHeap.h codi-pr-3/CercadorMoviesHeap.cpp codi-pr-3/CercadorMoviesHeap.h)


