set(timerrunner_SRCS main.cpp timer.cpp timerrunner.cpp)

qt5_add_dbus_adaptor(timerrunner_SRCS "/usr/share/dbus-1/interfaces/kf5_org.kde.krunner1.xml" timerrunner.h TimerRunner)

add_executable(timerrunner ${timerrunner_SRCS})
target_link_libraries(timerrunner
    Qt5::DBus
    KF5::Runner
    KF5::Notifications
)

set(CMAKE_BINARY_DIR "../bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

install(FILES timerrunner.desktop DESTINATION ~/.local/share/kservices5/)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    install(TARGETS timerrunner DESTINATION ~/.config/autostart-scripts/)
endif()
