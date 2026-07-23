cmake_minimum_required(VERSION 3.14)
project(TradingEngine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable testing
enable_testing()

# Compiler warnings
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# FetchContent for dependencies
include(FetchContent)

# spdlog for logging
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.12.0
)
FetchContent_MakeAvailable(spdlog)

# Google Test
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Includes
include_directories(include)

# Find source files
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
# Remove main.cpp from core library to avoid multiple definition of main in tests
list(REMOVE_ITEM SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Core library
add_library(CoreLib ${SRC_FILES})
target_link_libraries(CoreLib PRIVATE spdlog::spdlog)
target_include_directories(CoreLib PUBLIC include)

# Executable
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE CoreLib spdlog::spdlog)

# Tests
add_executable(TradingEngineTests tests/core_tests.cpp)
target_link_libraries(TradingEngineTests PRIVATE CoreLib gtest_main gmock spdlog::spdlog)

include(GoogleTest)
gtest_discover_tests(TradingEngineTests)
