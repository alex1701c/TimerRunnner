add_subdirectory(core)

set(timerrunner_SRCS main.cpp timerrunner.cpp)

qt5_add_dbus_adaptor(timerrunner_SRCS "/usr/share/dbus-1/interfaces/kf5_org.kde.krunner1.xml" timerrunner.h TimerRunner)

add_executable(timerrunner ${timerrunner_SRCS})
target_link_libraries(timerrunner
    Qt5::DBus
    Qt5::Widgets
    KF5::Runner
    KF5::Notifications
    KF5::CoreAddons
)
target_link_libraries(timerrunner core_static)

set(CMAKE_BINARY_DIR "../bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

install(FILES timerrunner.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/kservices5/)
install(FILES krunner_timer.notifyrc DESTINATION ${KDE_INSTALL_KNOTIFY5RCDIR})
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    install(TARGETS timerrunner DESTINATION ~/.config/autostart-scripts/)
endif()
