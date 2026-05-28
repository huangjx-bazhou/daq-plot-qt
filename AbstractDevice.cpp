#include "AbstractDevice.h"

class AbstractDevicePrivate
{
public:
    AbstractDevicePrivate() :
        id(),
        name(),
        type(AbstractDevice::UNKNOWN_TYPE),
        communication(AbstractDevice::UNKNOWN_COMMUNICATION),
        protocol(AbstractDevice::UNKNOWN_PROTOCOL)
    {
    }

    QString id;
    QString name;
    int type;
    int communication;
    int protocol;
};

AbstractDevice::AbstractDevice(QObject *parent) :
    QObject(parent),
    d(new AbstractDevicePrivate)
{
}

AbstractDevice::~AbstractDevice()
{
}

int AbstractDevice::type() const
{
    return d->type;
}

int AbstractDevice::communication() const
{
    return d->communication;
}

int AbstractDevice::protocol() const
{
    return d->protocol;
}

QString AbstractDevice::id() const
{
    return d->id;
}

QString AbstractDevice::name() const
{
    return d->name;
}
