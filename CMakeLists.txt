# cmake_minimum_required(VERSION 3.4.1)
# ADD_SUBDIRECTORY(./src/Debuger)
# ADD_SUBDIRECTORY(./src/Tool)
# ADD_LIBRARY (SZLRTOOL Debuger Tool)

ADD_LIBRARY (SZLRTOOL ./src/Tool/tool.cpp ./src/Tool/clock.cpp ./src/Debuger/debug.cpp ./src/Debuger/output.cpp ./src/Debuger/showdebug.cpp)
