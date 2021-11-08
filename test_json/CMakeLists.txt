#cmake最低版本需求，不加入此行会受到警告信息
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# 添加c++11标准支持
set( CMAKE_CXX_FLAGS "-std=c++11" ) 

#项目名称
PROJECT(TEST_JSON)

#把当前目录(.)下所有源代码文件和头文件加入变量SRC_LIST
AUX_SOURCE_DIRECTORY(. SRC_LIST)

#生成应用程序 TEST_JSON
ADD_EXECUTABLE(test_json ${SRC_LIST})

#
target_link_libraries(test_json jsoncpp)