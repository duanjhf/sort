#cmake最低版本要求
cmake_minimum_required(VERSION 2.6)
#项目名称
project(sort)
#message
message(STATUS "Project: sort")

#debug编译模式
set(CMAKE_BUILD_TYPE DEBUG)
#编译选项
set(CMAKE_C_FLAGS "-g -Wall")

#头文件路径
include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/unitTest
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#添加子目录
add_subdirectory(src)
add_subdirectory(unitTest)

#查找./目录下的所有源文件，赋值给SRC_FILES
aux_source_directory(. SRC_FILES)

#生成可执行文件sort
add_executable(sort ${SRC_FILES})

#链接库
target_link_libraries(sort libsort libsorttest)

