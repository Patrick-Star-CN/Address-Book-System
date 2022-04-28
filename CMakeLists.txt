cmake_minimum_required(VERSION 3.21)
project(project_abs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(project_abs src/main.cpp include/user.h src/user.cpp include/admin.h src/admin.cpp include/list.h include/listNode.h include/userList.h include/listable.h)
