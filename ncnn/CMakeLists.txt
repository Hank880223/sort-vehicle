cmake_minimum_required( VERSION 2.8 )
project( tracking )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp" )

aux_source_directory( ./src/ SRC_LIST )
add_executable( ${PROJECT_NAME} ${SRC_LIST} )
find_library( NCNN_LIB libncnn.a ./lib/ )

include_directories( include/ncnn )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries( tracking ${OpenCV_LIBS} )
target_link_libraries( tracking ${NCNN_LIB} )
