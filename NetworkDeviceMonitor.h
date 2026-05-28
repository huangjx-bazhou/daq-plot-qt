/**
 * @file    NetworkDeviceMonitor.h
 * @author  黄佳兴
 * @version 0.1
 * @date    2026-05-28
 *
 * @copyright Copyright (c) 2026 维拓启创 Inc. All rights reserved
 */
#ifndef NETWORKDEVICEMONITOR_H
#define NETWORKDEVICEMONITOR_H

#include "AbstractDeviceMonitor.h"

QT_USE_NAMESPACE

class NetworkDeviceMonitorPrivate;

/**
 * @brief 网络设备监视器
 */
class NetworkDeviceMonitor : public AbstractDeviceMonitor
{
    Q_OBJECT
public:
    explicit NetworkDeviceMonitor(QObject *parent = Q_NULLPTR);
    virtual ~NetworkDeviceMonitor();

    /** 开始监视 */
    virtual void start() Q_DECL_OVERRIDE;

    /** 停止监视 */
    virtual void stop() Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(NetworkDeviceMonitor)
};

#endif // NETWORKDEVICEMONITOR_H
