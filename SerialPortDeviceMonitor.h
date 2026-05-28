/**
 * @file    SerialPortDeviceMonitor.h
 * @author  黄佳兴
 * @version 0.1
 * @date    2026-05-28
 *
 * @copyright Copyright (c) 2026 维拓启创 Inc. All rights reserved
 */
#ifndef SERIALPORTDEVICEMONITOR_H
#define SERIALPORTDEVICEMONITOR_H

#include "AbstractDeviceMonitor.h"

QT_USE_NAMESPACE

class SerialPortDeviceMonitorPrivate;

/**
 * @brief 串口设备监视器
 */
class SerialPortDeviceMonitor : public AbstractDeviceMonitor
{
    Q_OBJECT
public:
    explicit SerialPortDeviceMonitor(QObject *parent = Q_NULLPTR);
    virtual ~SerialPortDeviceMonitor();

    /** 开始监视 */
    virtual void start() Q_DECL_OVERRIDE;

    /** 停止监视 */
    virtual void stop() Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(SerialPortDeviceMonitor)
};

#endif // SERIALPORTDEVICEMONITOR_H
