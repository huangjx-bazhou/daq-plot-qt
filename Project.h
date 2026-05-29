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
#include <QJsonObject>
#include "Experiment.h"

QT_USE_NAMESPACE

class ProjectPrivate;

/**
 * @brief Project 表示软件当前打开的项目
 */
class Project : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool modified READ isModified WRITE setModified NOTIFY modifiedChanged)

public:
    explicit Project(QObject *parent = Q_NULLPTR);
    virtual ~Project();

    /** 项目名称 */
    QString name() const;

    /** 设置项目名称 */
    void setName(const QString &name);

    /** 项目是否被修改 */
    bool isModified() const;

    /** 设置项目是否被修改 */
    void setModified(bool modified);

    /** 项目中的实验数量 */
    int experimentCount() const;

    /** 项目中的实验列表 */
    QList<ExperimentSharedPointer> experiments() const;

    /** 添加一个实验 */
    void addExperiment(const ExperimentSharedPointer &experiment);

    /** 移除一个实验 */
    bool removeExperiment(const ExperimentSharedPointer &experiment);

    /** 清空实验 */
    void clearExperiments();

    /** 转换为Json对象 */
    QJsonObject toJson() const;

    /** 从Json对象加载 */
    bool fromJson(const QJsonObject &json);

    /** 保存项目文件，filePath为空时使用当前项目路径 */
    bool save(const QString &filePath = QString());

    /** 加载项目文件 */
    bool load(const QString &filePath);

Q_SIGNALS:
    void filePathChanged(const QString &filePath);
    void nameChanged(const QString &name);
    void modifiedChanged(bool modified);
    void experimentAdded(const ExperimentSharedPointer &experiment);
    void experimentRemoved(const ExperimentSharedPointer &experiment);

private:
    Q_DISABLE_COPY(Project)
    QScopedPointer<ProjectPrivate> d;
};

#endif // PROJECT_H
