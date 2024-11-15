cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD_11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)



project(SimpleXpdf VERSION 1.0 LANGUAGES CXX)

find_package(Qt5 COMPONENTS Widgets REQUIRED Network)


add_executable(${CMAKE_PROJECT_NAME}
        main.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_BINARY_DIR}/goo")


target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets Qt5::Network)
