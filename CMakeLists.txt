#最小cmake版本要求 
cmake_minimum_required(VERSION 2.8) 


#工程名 
PROJECT(test_log4cpp) 
#编译命令可视化 
SET(CMAKE_VERBOSE_MAKEFILE ON) 
#设置编译模式为debug 
SET(CMAKE_BUILD_TYPE DEBUG) 
#设置编译为debug时的参数，系统自动加-g 
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall ") 
#添加编译参数，c11 
add_compile_options(-std=c++11) 


#在cmake的时候输出的参数 
MESSAGE(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}") 
MESSAGE(STATUS "CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}") 
#获取环境变量参数，必须是export的参数 
#MESSAGE(STATUS "LOG4: $ENV{LOG4}") 
#设置环境变量到cmake的变量 
#SET(LOG $ENV{LOG4}) 


#初始化pkg-config 
find_package(PkgConfig) 
#寻找log4cpp模块，pc文件的名字为log4cpp.pc   
pkg_search_module(LOG4 REQUIRED log4cpp) 
#常用参数的输出 
MESSAGE(STATUS "LOG4_FOUND: ${LOG4_FOUND}") 
MESSAGE(STATUS "LOG4_VERSION: ${LOG4_VERSION}") 
MESSAGE(STATUS "LOG4_CFLAGS: ${LOG4_CFLAGS}") 
MESSAGE(STATUS "LOG4_LDFLAGS: ${LOG4_LDFLAGS}") 

#编译include位置 
include_directories(${LOG4_INCLUDE_DIRS} "/home/code/test/log4cpp_pack") 
add_compile_options(${LOG4_CFLAGS_OTHER}) 

message(STATUS "CMAKE_CXX_FLAGS_DEBUG = " ${CMAKE_CXX_FLAGS_DEBUG})

#链接目录，如果使用必须防止在ADD_EXECUTABLE之前 
link_directories("/home/code/test/log4cpp_pack/lib/build") 
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG -Wl,--copy-dt-needed-entries)

#生成目标 
ADD_EXECUTABLE(${PROJECT_NAME} main.cpp) 


#链接的库名 
target_link_libraries(${PROJECT_NAME} "-llog4") 
