/**
 * @file    AbstractDeviceMonitor.h
 * @author  黄佳兴
 * @version 0.1
 * @date    2026-05-19
 *
 * @copyright Copyright (c) 2026 维拓启创 Inc. All rights reserved
 */
#ifndef ABSTRACTDEVICEMONITOR_H
#define ABSTRACTDEVICEMONITOR_H

#include <QObject>

QT_USE_NAMESPACE

class AbstractDeviceMonitorPrivate;

/**
 * @brief 抽象设备监视器
 */
class AbstractDeviceMonitor : public QObject
{
    Q_OBJECT
public:
    explicit AbstractDeviceMonitor(QObject *parent = Q_NULLPTR);
    virtual ~AbstractDeviceMonitor();

    /** 开始监视 */
    virtual void start() = 0;

    /** 停止监视 */
    virtual void stop() = 0;

private:
    Q_DISABLE_COPY(AbstractDeviceMonitor)
};

#endif // ABSTRACTDEVICEMONITOR_H
