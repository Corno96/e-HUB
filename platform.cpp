#include "platform.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

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
    QFile library(lib);
    library.open(QFile::WriteOnly);
    library.write("Ciao");
    library.close();
}

void Platform::Read() {
    // read all file
    QString lib = name+".json";
    QFile file(lib);
    file.open(QFile::ReadOnly);
    QString str = file.readAll();
    file.close();

    // save to class
    QJsonDocument library = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject obj = library.object();

    qDebug() << obj;
}
