/**
 * @file    DeviceMonitorFactory.h
 * @author  黄佳兴
 * @version 0.1
 * @date    2026-05-28
 *
 * @copyright Copyright (c) 2026 维拓启创 Inc. All rights reserved
 */
#ifndef DEVICEMONITORFACTORY_H
#define DEVICEMONITORFACTORY_H

#include "AbstractDeviceMonitor.h"
#include "DeviceEnums.h"

QT_USE_NAMESPACE

/**
 * @brief 设备监视器工厂
 */
namespace DeviceMonitorFactory
{
    /**
     * @brief 按通讯类型创建监视器
     */
    AbstractDeviceMonitor *create(DeviceCommunication communication, QObject *parent = Q_NULLPTR);
}

#endif // DEVICEMONITORFACTORY_H
