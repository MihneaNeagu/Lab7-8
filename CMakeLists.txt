cmake_minimum_required(VERSION 3.21)
project(lab78)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab78 main.cpp Repo.h Repo.cpp Transactions.cpp Transactions.h tests.cpp tests.h Operations.cpp Operations.h Service.cpp Service.h UI.cpp UI.h)
