#include "Project.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>

class ProjectPrivate
{
public:
    ProjectPrivate() :
        filePath(),
        name(),
        modified(false),
        experiments()
    {
    }

    QString filePath;
    QString name;
    bool modified;
    QList<ExperimentSharedPointer> experiments;
};

Project::Project(QObject *parent) :
    QObject(parent),
    d(new ProjectPrivate)
{
}

Project::~Project()
{
}

QString Project::name() const
{
    return d->name;
}

void Project::setName(const QString &name)
{
    if (d->name == name)
    {
        return;
    }

    d->name = name;
    Q_EMIT nameChanged(d->name);
}

bool Project::isModified() const
{
    return d->modified;
}

void Project::setModified(bool modified)
{
    if (d->modified == modified)
    {
        return;
    }

    d->modified = modified;
    Q_EMIT modifiedChanged(d->modified);
}

int Project::experimentCount() const
{
    return d->experiments.size();
}

QList<ExperimentSharedPointer> Project::experiments() const
{
    return d->experiments;
}

void Project::addExperiment(const ExperimentSharedPointer &experiment)
{
    if (experiment.isNull() || d->experiments.contains(experiment))
    {
        return;
    }

    d->experiments.append(experiment);
    Q_EMIT experimentAdded(experiment);
    setModified(true);
}

bool Project::removeExperiment(const ExperimentSharedPointer &experiment)
{
    const int index = d->experiments.indexOf(experiment);
    if (index < 0)
    {
        return false;
    }

    const ExperimentSharedPointer removedExperiment = d->experiments.takeAt(index);
    Q_EMIT experimentRemoved(removedExperiment);
    setModified(true);

    return true;
}

void Project::clearExperiments()
{
    if (d->experiments.isEmpty())
    {
        return;
    }

    d->experiments.clear();
    setModified(true);
}

QJsonObject Project::toJson() const
{
    QJsonObject json;
    json.insert("name", d->name);

    QJsonArray experimentArray;
    for (const ExperimentSharedPointer &experiment : d->experiments)
    {
        if (experiment.isNull())
        {
            continue;
        }

        experimentArray.append(experiment->toJson());
    }
    json.insert("experiments", experimentArray);

    return json;
}

bool Project::fromJson(const QJsonObject &json)
{
    if (json.isEmpty())
    {
        return false;
    }

    this->setName(json.value("name").toString());

    const QJsonArray experimentArray = json.value("experiments").toArray();
    for (const QJsonValue &value : experimentArray)
    {
        if (!value.isObject())
        {
            continue;
        }

        ExperimentSharedPointer experiment(new Experiment);
        if (!experiment->fromJson(value.toObject()))
        {
            continue;
        }

        this->addExperiment(experiment);
    }

    this->setModified(false);

    return true;
}

bool Project::save(const QString &filePath)
{
    const QString targetPath = filePath.isEmpty() ? d->filePath : filePath;
    if (targetPath.isEmpty())
    {
        return false;
    }

    QFile file(targetPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        return false;
    }

    const QJsonDocument document(this->toJson());
    if (file.write(document.toJson(QJsonDocument::Indented)) < 0)
    {
        file.close();
        return false;
    }

    file.close();
    this->setModified(false);

    return true;
}

bool Project::load(const QString &filePath)
{
    if (filePath.isEmpty())
    {
        return false;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    QJsonParseError parseError;
    const QJsonDocument document = QJsonDocument::fromJson(file.readAll(), &parseError);
    file.close();

    if (parseError.error != QJsonParseError::NoError || !document.isObject())
    {
        return false;
    }

    if (!this->fromJson(document.object()))
    {
        return false;
    }

    this->setModified(false);

    return true;
}
