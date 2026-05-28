#include "DeviceMonitorFactory.h"
#include "NetworkDeviceMonitor.h"
#include "SerialPortDeviceMonitor.h"

AbstractDeviceMonitor *DeviceMonitorFactory::create(DeviceCommunication communication, QObject *parent)
{
    switch (communication)
    {
    case NETWORK:
        return new NetworkDeviceMonitor(parent);

    case SERIALPORT:
        return new SerialPortDeviceMonitor(parent);

    default:
        return Q_NULLPTR;
    }
}
