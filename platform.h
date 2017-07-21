#ifndef PLATFORM_H
#define PLATFORM_H

#include <QUrl>
#include <QFile>
#include <QJsonObject>

class Platform
{
private:
    QString name;
    QString exe_path, lib_path;

public:
    Platform();
    Platform(QString name, QString exe_path, QString lib_path);

    QString getName() const;
    void setName(const QString &value);

    QString getExe_path() const;
    void setExe_path(const QString &value);

    QString getLib_path() const;
    void setLib_path(const QString &value);

    void Write() const;
    void Read();

    QJsonObject toJsonObject() const;
};

#endif // PLATFORM_H
