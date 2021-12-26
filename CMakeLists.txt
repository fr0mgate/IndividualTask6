cmake_minimum_required(VERSION 3.21)
project(IndividualTask6)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("${PROJECT_SOURCE_DIR}/IndividualTask6_my-string" "${PROJECT_SOURCE_DIR}/IndividualTask6_my-string/IndividualTask6_my-string_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/IndividualTask6_std-string" "${PROJECT_SOURCE_DIR}/IndividualTask6_std-string/IndividualTask6_std-string_output")
