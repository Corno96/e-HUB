#include "platform.h"

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

QString Platform::getExt() const
{
    return ext;
}

void Platform::setExt(const QString &value)
{
    ext = value;
}

void Platform::save() const {
    // open file
    QString lib = QDir::currentPath() + "/library/" + name +".json";
    QFile file(lib);
    file.open(QFile::WriteOnly);

    // convert class to jsonObject
    QJsonObject obj = toJsonObject();
    QJsonDocument doc = QJsonDocument(obj);

    // write to file
    file.write(doc.toJson());
    file.close();
}

// read from json
void Platform::load(const QString &path) {
    // read all file
    //QString lib = QDir::currentPath() + "/library/" + name +".json";
    QFile file(path);

    // read all file
    file.open(QFile::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(QString(file.readAll()).toUtf8());
    file.close();

    QJsonObject obj = doc.object();

    // save data to class
    name = obj.value(QString("name")).toString();
    exe_path = obj.value(QString("exe_path")).toString();
    lib_path = obj.value(QString("lib_path")).toString();

    // add game to games
}

void Platform::print() const {
    qDebug() << name << exe_path << lib_path;
}

void Platform::LoadCmdStr() {
    // read file cmd_str
    // get info for this platform (by name)
    // save it to cmd_str
}

// convert to jsonObject
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

void Platform::addGame(Game g) {
    games.append(g);
}

void Platform::removeGame(QString name) {
    for (int i=0;i<games.size();++i) {
        if (games.at(i).getName() == name) {
            games.remove(i);
            return;
        }
    }

    qDebug() << "Couldn't remove game " << name;
}

void Platform::launchGame(const Game &g) const {
    QProcess *process = new QProcess();

    qDebug() <<  g.getPath();

    process->start(exe_path + " -loadbin " + "\"" + g.getPath() + "\"" + " -nogui");
}
