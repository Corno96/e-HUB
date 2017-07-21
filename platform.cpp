#include "platform.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

Platform::Platform() {
    this->name = "";
    this->exe_path = "";
    this->lib_path = "";
}

Platform::Platform(QString name, QString exe_path, QString lib_path) {
    this->name = name;
    this->exe_path = exe_path;
    this->lib_path = lib_path;
}

QString Platform::getName() const
{
    return name;
}

void Platform::setName(const QString &value)
{
    name = value;
}

QString Platform::getExe_path() const
{
    return exe_path;
}

void Platform::setExe_path(const QString &value)
{
    exe_path = value;
}

QString Platform::getLib_path() const
{
    return lib_path;
}

void Platform::setLib_path(const QString &value)
{
    lib_path = value;
}

void Platform::Write() const {
    QString lib = name+".json";
    QFile file(lib);
    file.open(QFile::WriteOnly);

    QJsonObject obj = toJsonObject();
    QJsonDocument doc = QJsonDocument(obj);

    file.write(doc.toJson());
    file.close();
}

void Platform::Read() {
    // read all file
    QString lib = name+".json";
    QFile file(lib);

    file.open(QFile::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(QString(file.readAll()).toUtf8());
    file.close();

    QJsonObject obj = doc.object();

    name = obj.value(QString("name")).toString();
    //path = obj.value(QString("path")).toString();

    //qDebug() << name << " -> " << path;
}

QJsonObject Platform::toJsonObject() const {
    QJsonValue n = QJsonValue(name);
    QJsonValue exe = QJsonValue(exe_path);
    QJsonValue lib = QJsonValue(lib_path);

    QJsonObject obj;
    obj.insert(QString("name"), n);
    obj.insert(QString("exe_path"), exe);
    obj.insert(QString("lib_path"), lib);

    return obj;
}
