#include "NetworkDeviceMonitor.h"

// Qt
#include <QDebug>
#include <QMap>
#include <QVariant>

// qzeroconf
#include <qzeroconf.h>

class NetworkDeviceMonitorPrivate
{
public:
    NetworkDeviceMonitorPrivate(NetworkDeviceMonitor* parent) :
        _parent(parent),
        _browsers(),
        _running(false)
    {
    }

    ~NetworkDeviceMonitorPrivate()
    {
        this->stop();
    }

    // 开始监视具体实现
    void start()
    {
        // 如果正在监视，则直接返回，什么都不做
        if (_running)
        {
            return;
        }

        // 将监视标志设置true，代表正在监视
        _running = true;

        // 开起所有监视器
        for (auto it = _browsers.cbegin(); it != _browsers.cend(); ++it)
        {
            // NOTE: 不用判断it.key()的合法性，在加入时已经判断
            // NOTE: 不用判断it.value()是否是空指针，在加入时确保不是空指针
            it.value()->startBrowser(it.key());
        }
    }

    // 停止监视具体实现
    void stop()
    {
        // 如果没有在监视，则直接返回，什么都不做
        if (!_running)
        {
            return;
        }

        // 停止所有监视器
        for (auto it = _browsers.cbegin(); it != _browsers.cend(); ++it)
        {
            // NOTE: 不用判断it.value()是否是空指针，在加入时确保不是空指针
            it.value()->stopBrowser();
        }

        // 将监视标志设置false，代表不在监视
        _running = false;
    }

    // 添加要监视的服务
    void addService(const QString &servicestr)
    {
        // 创建
        QZeroConf *browser = new QZeroConf(_parent);
        browser->setProperty("service", servicestr);

        // 信号连接
        QObject::connect(browser, &QZeroConf::serviceAdded, _parent, [](QZeroConfService service)
        {
            qInfo() << "serviceAdded:" << service;
        });

        QObject::connect(browser, &QZeroConf::serviceUpdated, _parent, [](QZeroConfService service)
        {
            qInfo() << "serviceUpdated:" << service;
        });

        QObject::connect(browser, &QZeroConf::serviceRemoved, _parent, [](QZeroConfService service)
        {
            qInfo() << "serviceRemoved:" << service;
        });

        QObject::connect(browser, &QZeroConf::error, _parent, [](QZeroConf::error_t error)
        {
            qWarning() << "zeroconf browser error:" << error;
        });

        // 添加到集合
        _browsers[servicestr] = browser;

        // 如果正在监视，则开启对service的监视
        if (_running)
        {
            browser->startBrowser(servicestr);
        }
    }

    void removeService(const QString &servicestr)
    {
        // NOTE: 没有判断空指针,是否需要判断running
        _browsers[servicestr]->stopBrowser();
        _browsers[servicestr]->deleteLater();
        _browsers.remove(servicestr);
    }

    NetworkDeviceMonitor* _parent;
    QMap<QString, QZeroConf *> _browsers;
    bool _running;
};

NetworkDeviceMonitor::NetworkDeviceMonitor(QObject *parent) :
    AbstractDeviceMonitor(parent),
    d(new NetworkDeviceMonitorPrivate(this))
{
}

NetworkDeviceMonitor::~NetworkDeviceMonitor()
{
}

void NetworkDeviceMonitor::start()
{
    d->start();
}

void NetworkDeviceMonitor::stop()
{
    d->stop();
}

void NetworkDeviceMonitor::setServices(const QStringList &services)
{
    // 旧服务是否出现在新服务列表里，没出现就删除
    for (auto it = d->_browsers.cbegin(); it != d->_browsers.cend(); ++it)
    {
        // 需要删除的
        if (!services.contains(it.key()))
        {
            d->removeService(it.key());
        }
    }

    this->addServices(services);
}

void NetworkDeviceMonitor::addServices(const QStringList &services)
{
    for (auto it = services.cbegin(); it != services.cend(); ++it)
    {
        // 如果服务已经存在了，则跳过
        if (d->_browsers.contains(*it))
        {
            continue;
        }

        // 服务没有存在，判断服务字符串是否合法
        // TODO: 添加判断字符串是否合法的代码

        d->addService(*it);
    }
}

void NetworkDeviceMonitor::removeServices(const QStringList &services)
{
    for (auto it = services.cbegin(); it != services.cend(); ++it)
    {
        // 如果服务已经存在了，则移除
        if (d->_browsers.contains(*it))
        {
            d->removeService(*it);
        }
    }
}

QStringList NetworkDeviceMonitor::services() const
{
    return d->_browsers.keys();
}
