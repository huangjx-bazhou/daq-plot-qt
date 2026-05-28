/**
 * @file    DeviceEnums.h
 * @author  黄佳兴
 * @version 0.1
 * @date    2026-05-28
 *
 * @copyright Copyright (c) 2026 维拓启创 Inc. All rights reserved
 */
#ifndef DEVICEENUMS_H
#define DEVICEENUMS_H

/**
 * @brief 设备类型
 */
enum DeviceType
{
    NIRS,         ///<- 近红外光谱成像设备
    UNKNOWN_TYPE  ///<- 未知设备
};

/**
 * @brief 通讯类型
 */
enum DeviceCommunication
{
    NETWORK,               ///<- 网络
    SERIALPORT,            ///<- 串口
    BLUETOOTH,             ///<- 蓝牙
    UNKNOWN_COMMUNICATION  ///<- 未知
};

/**
 * @brief 协议类型
 */
enum DeviceProtocol
{
    PROTOCOL1,        ///<- 协议1
    PROTOCOL2,        ///<- 协议2
    PROTOCOL3,        ///<- 协议3
    UNKNOWN_PROTOCOL  ///<- 未知协议
};

#endif // DEVICEENUMS_H
