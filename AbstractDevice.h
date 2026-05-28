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

    /**
     * @brief 设备类型
     */
    enum Type
    {
        NIRS,         ///<- 近红外光谱成像设备
        UNKNOWN_TYPE  ///<- 未知设备
    };

    /**
     * @brief 通讯类型
     */
    enum Communication
    {
        NETWORK,               ///<- 网络
        SERIALPORT,            ///<- 串口
        BLUETOOTH,             ///<- 蓝牙
        UNKNOWN_COMMUNICATION  ///<- 未知
    };

    /**
     * @brief 协议类型
     */
    enum Protocol
    {
        PROTOCOL1,        ///<- 协议1
        PROTOCOL2,        ///<- 协议2
        PROTOCOL3,        ///<- 协议3
        UNKNOWN_PROTOCOL  ///<- 未知协议
    };

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

#endif // ABSTRACTDEVICE_H
