add_library(geometry INTERFACE)
add_library(mrmp::geometry ALIAS geometry)
target_include_directories(geometry INTERFACE ./)
