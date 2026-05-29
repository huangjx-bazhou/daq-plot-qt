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
#include "AbstractDevice.h"

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

    /**
     * @brief setService 设置监视服务(如:_http._tcp)，会清空旧的服务
     * @param service    要设置的服务
     */
    inline void setService(const QString &service);

    /**
     * @brief setServices 批量设置监视服务(如:_http._tcp _http._udp)，会清空旧的服务
     * @param services    要设置的服务
     */
    virtual void setServices(const QStringList &services) = 0;

    /**
     * @brief addService 添加监视服务(如:_http._tcp)，不会清空旧的服务，会追加，不会重复追加
     * @param service    要添加的服务
     */
    inline void addService(const QString &service);

    /**
     * @brief addServices 批量添加监视服务(如:_http._tcp _http._udp)，不会清空旧的服务，会追加，不会重复追加
     * @param services    要添加的服务
     */
    virtual void addServices(const QStringList &services) = 0;

    /**
     * @brief removeService 移除监视服务(如:_http._tcp)
     * @param service       要移除的服务
     */
    inline void removeService(const QString &service);

    /**
     * @brief removeServices 批量移除监视服务(如:_nirs._tcp _nirs._udp _nirs._com)
     * @param services       要移除的服务
     */
    virtual void removeServices(const QStringList &services) = 0;

    /** 当前监视服务列表 */
    virtual QStringList services() const = 0;

Q_SIGNALS:
    /** 设备增加 */
    void deviceAdded(const DeviceSharedPointer &device);

    /** 设备移除 */
    void deviceRemoved(const DeviceSharedPointer &device);

private:
    Q_DISABLE_COPY(AbstractDeviceMonitor)
};

inline void AbstractDeviceMonitor::setService(const QString &service)
{
    this->setServices(QStringList() << service);
}

inline void AbstractDeviceMonitor::addService(const QString &service)
{
    this->addServices(QStringList() << service);
}

inline void AbstractDeviceMonitor::removeService(const QString &service)
{
    this->removeServices(QStringList() << service);
}

#endif // ABSTRACTDEVICEMONITOR_H
