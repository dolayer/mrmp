add_executable(astar_test astar_test.cpp)
target_link_libraries(astar_test PRIVATE  mrmp::geometry mrmp::graph)