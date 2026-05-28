cmake_minimum_required(VERSION 3.19)

project(DAQPlot VERSION 1.0.0 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(DAQPlot
    WIN32 MANUAL_FINALIZATION
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
    AbstractDevice.h
    AbstractDevice.cpp
    AbstractDeviceMonitor.cpp
    AbstractDeviceMonitor.h
    NetworkDeviceMonitor.cpp
    NetworkDeviceMonitor.h
)

target_link_libraries(DAQPlot PRIVATE Qt::Core Qt::Widgets)

install(TARGETS DAQPlot
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET DAQPlot
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
