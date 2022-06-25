cmake_minimum_required(VERSION 3.22)
project(CppMCServerManager VERSION 0.1.0 LANGUAGES CXX)

# 必须使用不低于c++17标准
set(CMAKE_CXX_STANDARD 17)

# 项目信息配置
string(TIMESTAMP COMPILE_TIME %Y%m%d-%H:%M:%S)
set(cmake_time ${COMPILE_TIME})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.h.in "${CMAKE_CURRENT_SOURCE_DIR}/src/version.h")

# 第三方库目录
add_subdirectory(external)

# 项目源码目录
add_subdirectory(src)

# 以下为一些模块的测试
add_subdirectory(test/childSession)
