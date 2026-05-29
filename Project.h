/**
 * @file    Project.h
 * @author  黄佳兴
 * @version 0.1
 * @date    2026-05-29
 *
 * @copyright Copyright (c) 2026 维拓启创 Inc. All rights reserved
 */
#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>

QT_USE_NAMESPACE

class ProjectPrivate;

/**
 * @brief Project 表示软件当前打开的项目
 */
class Project : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool modified READ isModified WRITE setModified NOTIFY modifiedChanged)

public:
    explicit Project(QObject *parent = Q_NULLPTR);
    virtual ~Project();

    /** 项目文件路径 */
    QString filePath() const;

    /** 设置项目文件路径 */
    void setFilePath(const QString &filePath);

    /** 项目名称 */
    QString name() const;

    /** 设置项目名称 */
    void setName(const QString &name);

    /** 项目是否被修改 */
    bool isModified() const;

    /** 设置项目是否被修改 */
    void setModified(bool modified);

Q_SIGNALS:
    void filePathChanged(const QString &filePath);
    void nameChanged(const QString &name);
    void modifiedChanged(bool modified);

private:
    Q_DISABLE_COPY(Project)
    QScopedPointer<ProjectPrivate> d;
};

#endif // PROJECT_H
