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
    // Constructors
    //Platform();
    Platform(QString name = "", QString exe_path = "", QString lib_path = "");

    // Getter-Setter
    QString getName() const;                    // name
    void setName(const QString &value);
    QString getExe_path() const;                // exe_path
    void setExe_path(const QString &value);
    QString getLib_path() const;                // lib_path
    void setLib_path(const QString &value);

    // Methods
    void save() const; // write to json
    void load(const QString &path);       // read from json
    void print() const; // print to qDebug()
    QJsonObject toJsonObject() const;   // convert to jsonObject
};

#endif // PLATFORM_H
