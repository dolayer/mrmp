add_library(graph INTERFACE)
add_library(mrmp::graph ALIAS graph)
target_include_directories(graph INTERFACE ./)
target_link_libraries(graph INTERFACE geometry)