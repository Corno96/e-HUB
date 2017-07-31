#ifndef PLATFORM_H
#define PLATFORM_H

#include <QUrl>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QProcess>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QVector>

#include "game.h"

class Platform
{
private:
    QString name;
    QString exe_path, lib_path;
    QVector<Game> games;
    QString cmd_str;

    // constants
    static const QString EXE_PATH;
    static const QString GAME_PATH;

public:
    // Constructors
    //Platform();
    Platform(QString name = "", QString exe_path = "", QString lib_path = "", QString cmd_str = "");

    // Getter-Setter
    QString getName() const;                    // name
    void setName(const QString &value);
    QString getExe_path() const;                // exe_path
    void setExe_path(const QString &value);
    QString getLib_path() const;                // lib_path
    void setLib_path(const QString &value);
    QString getCmd_str() const;                 // cmd_str
    void setCmd_str(const QString &value);
    QVector<Game> getGames() const;             // games
    void setGames(const QVector<Game> &value);

    // Methods
    void save() const;              // write to json
    void load(const QString &path); // read from json
    void print() const;             // print to qDebug()
    void loadCmdStr();              // load command structure in cmd_str

    QJsonObject toJsonObject() const;   // convert to jsonObject
    QString getExeName() const;     // returns the executable file name

    void addGame(Game g);           // add game to games
    Game* getGame(int i);           // get game at i position
    void removeGame(QString name);  // remove game from games
    void launchGame(const Game &g) const;   // launch game with emulator
};

#endif // PLATFORM_H
