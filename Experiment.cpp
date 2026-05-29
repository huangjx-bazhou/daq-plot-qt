#include "Experiment.h"

#include <QJsonValue>

class ExperimentPrivate
{
public:
    ExperimentPrivate() :
        id(),
        name()
    {
    }

    QString id;
    QString name;
};

Experiment::Experiment(QObject *parent) :
    QObject(parent),
    d(new ExperimentPrivate)
{
}

Experiment::~Experiment()
{
}

QString Experiment::id() const
{
    return d->id;
}

void Experiment::setId(const QString &id)
{
    if (d->id == id)
    {
        return;
    }

    d->id = id;
    Q_EMIT idChanged(d->id);
}

QString Experiment::name() const
{
    return d->name;
}

void Experiment::setName(const QString &name)
{
    if (d->name == name)
    {
        return;
    }

    d->name = name;
    Q_EMIT nameChanged(d->name);
}

QJsonObject Experiment::toJson() const
{
    QJsonObject json;
    json.insert("id", d->id);
    json.insert("name", d->name);

    return json;
}

bool Experiment::fromJson(const QJsonObject &json)
{
    if (json.isEmpty())
    {
        return false;
    }

    this->setId(json.value("id").toString());
    this->setName(json.value("name").toString());

    return true;
}
