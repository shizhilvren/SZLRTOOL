cmake_minimum_required(VERSION 3.4.1)
project(FZUFplace)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_FLAGS "-std=c99 -O3 -Wall ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-std=c++14 -O3 -Wall ${CMAKE_CXX_FLAGS}")
# 附带内存检查 g++工具
# set(CMAKE_CXX_FLAGS "-g -fsanitize=address -fno-omit-frame-pointer ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-g -fno-omit-frame-pointer ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-pg ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-fopenmp ${CMAKE_CXX_FLAGS}")

SET(CMAKE_EXE_LINKER_FLAGS "")

# find_package(jsoncpp REQUIRED)
# link_directories(${PROJECT_SOURCE_DIR}/lib)


#引入头文件
include_directories(${PROJECT_SOURCE_DIR}/src/Debuger)
include_directories(${PROJECT_SOURCE_DIR}/src/Tool)
file(GLOB SRC_LIST "src/*.cpp")

#编译
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/Debuger)
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/Tool)

#链接
add_executable(FZUFplace ${SRC_LIST})

TARGET_LINK_LIBRARIES(FZUFplace Debuger)
TARGET_LINK_LIBRARIES(FZUFplace Tool)
target_link_libraries(FZUFplace ${JSONCPP_LIBRARIES})
