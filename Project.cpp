#include "Project.h"

class ProjectPrivate
{
public:
    ProjectPrivate() :
        filePath(),
        name(),
        modified(false)
    {
    }

    QString filePath;
    QString name;
    bool modified;
};

Project::Project(QObject *parent) :
    QObject(parent),
    d(new ProjectPrivate)
{
}

Project::~Project()
{
}

QString Project::filePath() const
{
    return d->filePath;
}

void Project::setFilePath(const QString &filePath)
{
    if (d->filePath == filePath)
    {
        return;
    }

    d->filePath = filePath;
    Q_EMIT filePathChanged(d->filePath);
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
