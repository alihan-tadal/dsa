cmake_minimum_required(VERSION 3.10)

project(data_structures)

add_subdirectory(list)
add_subdirectory(linked_list)
add_subdirectory(stack)
# ... add other data structure folders here

add_executable(data_structures example.c)

target_link_libraries(data_structures PRIVATE list linked_list stack)
