#头文件路径
include_directories(
	${PROJECT_SOURCE_DIR}/include
)

#查找./目录下的所有源文件，赋值给SRC_FILES
aux_source_directory(. SRC_FILES)

#设置库路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
#生成共享库
add_library(libsort SHARED ${SRC_FILES})


#install(TARGETS libsort LIBRARY DESTINATION lib)
#set_target_properties(libsort PROPERTIES OUTPUT_NAME "sort")
