cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.1.0)

# Add the source in project root directory
aux_source_directory(. DIRSRCS)

# Add header file include directories
include_directories("${PROJECT_SOURCE_DIR}")

# Target
add_executable(leetcode ${DIRSRCS})

target_link_libraries(leetcode)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
