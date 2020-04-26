set(core_SRCS timer.cpp utilities.cpp)

add_library(core_static STATIC ${core_SRCS})
target_link_libraries(core_static Qt5::Core KF5::Notifications)
