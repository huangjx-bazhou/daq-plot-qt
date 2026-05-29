/**
 * @file    AbstractDevice.h
 * @author  黄佳兴
 * @version 0.1
 * @date    2026-05-27
 *
 * @copyright Copyright (c) 2026 维拓启创 Inc. All rights reserved
 */
#ifndef ABSTRACTDEVICE_H
#define ABSTRACTDEVICE_H

#include <QObject>
#include <QSharedPointer>

QT_USE_NAMESPACE

class AbstractDevicePrivate;

/**
 * @brief 抽象设备，所有设备的基类
 */
class AbstractDevice : public QObject
{
    Q_OBJECT
public:
    explicit AbstractDevice(QObject *parent = Q_NULLPTR);
    virtual ~AbstractDevice();

    /** 设备类型 */
    int type() const;

    /** 通讯类型 */
    int communication() const;

    /** 协议类型 */
    int protocol() const;

    /** 设备id */
    QString id() const;

    /** 设备名称 */
    QString name() const;

private:
    Q_DISABLE_COPY(AbstractDevice)
    QScopedPointer<AbstractDevicePrivate> d;
};

using DeviceSharedPointer = QSharedPointer<AbstractDevice>;

#endif // ABSTRACTDEVICE_H
