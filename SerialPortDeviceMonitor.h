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

    /**
     * @brief setServices 批量设置监视服务(如:_http._tcp _http._udp)，会清空旧的服务
     * @param services    要设置的服务
     */
    virtual void setServices(const QStringList &services) Q_DECL_OVERRIDE;

    /**
     * @brief addServices 批量添加监视服务(如:_http._tcp _http._udp)，不会清空旧的服务，会追加，不会重复追加
     * @param services    要添加的服务
     */
    virtual void addServices(const QStringList &services) Q_DECL_OVERRIDE;

    /**
     * @brief removeServices 批量移除监视服务(如:_http._tcp _http._udp)
     * @param services       要移除的服务
     */
    virtual void removeServices(const QStringList &services) Q_DECL_OVERRIDE;

    /** 当前监视服务列表 */
    virtual QStringList services() const Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(SerialPortDeviceMonitor)
};

#endif // SERIALPORTDEVICEMONITOR_H
