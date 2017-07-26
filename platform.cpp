#include "platform.h"

Platform::Platform(QString name, QString exe_path, QString lib_path, QString cmd_str) {
    this->name = name;
    this->exe_path = exe_path;
    this->lib_path = lib_path;
    this->cmd_str = cmd_str;
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

QString Platform::getCmd_str() const
{
    return cmd_str;
}

void Platform::setCmd_str(const QString &value)
{
    cmd_str = value;
}

QVector<Game> Platform::getGames() const
{
    return games;
}

void Platform::setGames(const QVector<Game> &value)
{
    games = value;
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
    QJsonArray array = obj.value(QString("games")).toArray();

    for (int i=0;i<array.size();++i) {
        QString name, game_path;
        QJsonObject o = array[i].toObject();
        name = o.value(QString("name")).toString();
        game_path = o.value(QString("game_path")).toString();

        Game temp = Game(name, game_path);

        games.push_back(temp);
    }

    // load cmd_str
    loadCmdStr();
}

void Platform::print() const {
    qDebug() << "name: " << name << "; executable: " << exe_path << "; library: " << lib_path;

    for (int i=0;i<games.size();++i) {
        games[i].print();
    }
}

void Platform::loadCmdStr() {
    // read file cmd_str
    QFile file(QDir::currentPath() + "/cmd_str.json");
    file.open(QFile::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(QString(file.readAll()).toUtf8());
    file.close();

    QJsonObject obj = doc.object();

    // get info for this platform (by name)
    QJsonValue val = obj.value(getExeName());

    // check if exists
    if (val == QJsonValue::Undefined) {
        qDebug() << "No command structure for platform " << getExeName();
        return;
    }

    // save it to cmd_str
    cmd_str = val.toString();
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

    QJsonArray games_array;

    // vector of json objects
    for (int i=0;i<games.size();++i) {
        games_array.push_back(games.at(i).toJsonObject());
    }

    obj.insert(QString("games"), games_array);

    return obj;
}

QString Platform::getExeName() const {
    QUrl url = QUrl(exe_path);

    return url.fileName();
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

QString Quotes(QString str) {
    str.insert(0,'"');
    str.append('"');

    return str;
}

const QString Platform::EXE_PATH = "EXE_PATH";
const QString Platform::GAME_PATH = "GAME_PATH";

void Platform::launchGame(const Game &g) const {
    QProcess *process = new QProcess();

    QString command = "";

    QStringList list = cmd_str.split(QString(";"));

    for (int i=0;i<list.size();++i) {
        QString temp = list.at(i);
        if (temp == EXE_PATH)
            command += Quotes(exe_path) + " ";
        else if (temp == GAME_PATH)
            command += Quotes(g.getGame_path()) + " ";
        else
            command += list.at(i) + " ";
    }

    qDebug() << command;

    process->start(command);
}
