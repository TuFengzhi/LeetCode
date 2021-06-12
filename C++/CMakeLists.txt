cmake_minimum_required(VERSION 3.10.0)
project(leetcode VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  GoogleTest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(GoogleTest)

# Add the source in project root directory
aux_source_directory(. DIRSRCS)

# Add header file include directories
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(leetcode ${DIRSRCS})

target_link_libraries(leetcode gtest_main)

include(GoogleTest)
