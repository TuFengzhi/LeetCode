cmake_minimum_required(VERSION 3.0.0)
project(algorithm VERSION 0.1.0)

# Add the source in project root directory
aux_source_directory(. DIRSRCS)

# Add header file include directories
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/algorithm_utils/include")
include_directories("${PROJECT_SOURCE_DIR}/compensation_algorithm/include")
include_directories("${PROJECT_SOURCE_DIR}/echo_cancellation_algorithm/include")
include_directories("${PROJECT_SOURCE_DIR}/interface/include")
include_directories("${PROJECT_SOURCE_DIR}/multiple_microphone_source_separation_algorithm/include")
include_directories("${PROJECT_SOURCE_DIR}/noise_canceling_algorithm/include")
include_directories("${PROJECT_SOURCE_DIR}/unittest/include")

add_compile_definitions(_INCUS_GENERAL_EDITION)
add_compile_definitions(_INCUS_MODULE_TEST_ENABLED)
add_compile_definitions(_INCUS_ALGORITHM_MAIN)
add_compile_definitions(_INCUS_UNIT_TEST_ENABLED)

aux_source_directory("${PROJECT_SOURCE_DIR}/algorithm_utils" algorithm_utils)
aux_source_directory("${PROJECT_SOURCE_DIR}/compensation_algorithm" algorithm_utils)
aux_source_directory("${PROJECT_SOURCE_DIR}/echo_cancellation_algorithm" echo_cancellation_algorithm)
aux_source_directory("${PROJECT_SOURCE_DIR}/interface" interface)
aux_source_directory("${PROJECT_SOURCE_DIR}/multiple_microphone_source_separation_algorithm" multiple_microphone_source_separation_algorithm)
aux_source_directory("${PROJECT_SOURCE_DIR}/noise_canceling_algorithm" noise_canceling_algorithm)
aux_source_directory("${PROJECT_SOURCE_DIR}/unittest" unittest)

# Target
add_executable(algorithm ${DIRSRCS} ${algorithm_utils} ${compensation_algorithm} ${echo_cancellation_algorithm} ${interface} ${multiple_microphone_source_separation_algorithm} ${noise_canceling_algorithm} ${unittest})

target_link_libraries(algorithm)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
