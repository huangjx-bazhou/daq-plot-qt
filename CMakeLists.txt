cmake_minimum_required(VERSION 3.19)

project(DAQPlot VERSION 1.0.0 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)
find_package(QtZeroConf REQUIRED)

qt_standard_project_setup()

qt_add_executable(DAQPlot
    WIN32 MANUAL_FINALIZATION
    AbstractDevice.h
    AbstractDevice.cpp
    AbstractDeviceMonitor.cpp
    AbstractDeviceMonitor.h
    DeviceEnums.h
    DeviceMonitorFactory.cpp
    DeviceMonitorFactory.h
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
    NetworkDeviceMonitor.cpp
    NetworkDeviceMonitor.h
    SerialPortDeviceMonitor.cpp
    SerialPortDeviceMonitor.h
)

target_link_libraries(DAQPlot PRIVATE Qt::Core Qt::Widgets QtZeroConf)

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
