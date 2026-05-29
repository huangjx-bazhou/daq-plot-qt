/**
 * @file    Experiment.h
 * @author  黄佳兴
 * @version 0.1
 * @date    2026-05-29
 *
 * @copyright Copyright (c) 2026 维拓启创 Inc. All rights reserved
 */
#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <QObject>
#include <QJsonObject>
#include <QSharedPointer>

QT_USE_NAMESPACE

class ExperimentPrivate;

/**
 * @brief Experiment 表示项目中的一个实验
 */
class Experiment : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit Experiment(QObject *parent = Q_NULLPTR);
    virtual ~Experiment();

    /** 实验id */
    QString id() const;

    /** 设置实验id */
    void setId(const QString &id);

    /** 实验名称 */
    QString name() const;

    /** 设置实验名称 */
    void setName(const QString &name);

    /** 转换为Json对象 */
    QJsonObject toJson() const;

    /** 从Json对象加载 */
    bool fromJson(const QJsonObject &json);

Q_SIGNALS:
    void idChanged(const QString &id);
    void nameChanged(const QString &name);

private:
    Q_DISABLE_COPY(Experiment)
    QScopedPointer<ExperimentPrivate> d;
};

using ExperimentSharedPointer = QSharedPointer<Experiment>;

#endif // EXPERIMENT_H
