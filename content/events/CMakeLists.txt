add_library(events
  updatefov.cpp
 die.cpp
 hit.cpp
 thrust.cpp
 swing.cpp
 throw.cpp
  )

target_include_directories(events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(events PUBLIC engine)
