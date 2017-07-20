#include "platform.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

Platform::Platform() {
    this->name = "";
    this->path = QUrl();
}

Platform::Platform(QString name, QUrl path) {
    this->name = name;
    this->path = path;
}

void Platform::setName(QString name) {
    this->name = name;
}

QString Platform::getName() const {
    return name;
}

void Platform::setPath(QUrl path) {
    this->path = path;
}

QUrl Platform::getPath() const {
    return path;
}

void Platform::Write() const {
    QString lib = name+".json";
    QFile file(lib);
    file.open(QFile::WriteOnly);

    QJsonValue val = QJsonValue(path.toString());
    QJsonObject obj = QJsonObject();
    obj.insert(QString("path"), val);

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

    qDebug() << obj.value(QString("path")).toString();
}
