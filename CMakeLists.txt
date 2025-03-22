cmake_minimum_required(VERSION 3.12)
project(BoostPythonExample)

set(CMAKE_CXX_STANDARD 20)

# boost
set(BOOST_ROOT "/home/ubuntu/workspace/pkg/boost_1_85_0/arm64-v8a")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib")
set(Boost_USE_STATIC_LIBS ON)
set(Boost_DIR "${BOOST_LIBRARYDIR}/cmake/Boost-1.85.0")
set(boost_headers_DIR "${BOOST_LIBRARYDIR}/cmake/boost_headers-1.85.0")
set(boost_filesystem_DIR "${BOOST_LIBRARYDIR}/cmake/boost_filesystem-1.85.0")
set(boost_atomic_DIR "${BOOST_LIBRARYDIR}/cmake/boost_atomic-1.85.0")
set(boost_system_DIR "${BOOST_LIBRARYDIR}/cmake/boost_system-1.85.0")
set(boost_serialization_DIR "${BOOST_LIBRARYDIR}/cmake/boost_serialization-1.85.0")
set(boost_python_DIR "${BOOST_LIBRARYDIR}/cmake/boost_python-1.85.0")
set(boost_container_DIR "${BOOST_LIBRARYDIR}/cmake/boost_container-1.85.0")
set(boost_graph_DIR "${BOOST_LIBRARYDIR}/cmake/boost_graph-1.85.0")
set(Boost_COMPILER "-clang")
find_package(Boost REQUIRED COMPONENTS python)

# python
set(Python_EXECUTABLE ${PYTHON_EXECUTABLE})
find_package(Python REQUIRED COMPONENTS Development)
include_directories(${PYTHON_INCLUDE_DIRS})

file(GLOB_RECURSE SRC_FILES
        ${CMAKE_SOURCE_DIR}/src/*.h
        ${CMAKE_SOURCE_DIR}/src/*.c
        ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# 添加库目标
add_library(boostpy SHARED ${SRC_FILES})

# 包含目录
target_include_directories(boostpy PRIVATE
    ${Boost_INCLUDE_DIRS}
    ${Python_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
)

# 链接库
target_link_libraries(boostpy PRIVATE
    Boost::python
    # Python::Python
    ${PYTHON_LIBRARIES}
)

# 设置输出目录
set_target_properties(boostpy PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/boostpy
    PREFIX ""
    SUFFIX ".so"
)

# 安装规则
install(TARGETS boostpy DESTINATION boostpy)
install(DIRECTORY boostpy/ DESTINATION boostpy)