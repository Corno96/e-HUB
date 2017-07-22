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
#include <QVector>

#include "game.h"

class Platform
{
private:
    QString name;
    QString exe_path, lib_path;
    QVector<Game> games;
    QString ext;

public:
    // Constructors
    //Platform();
    Platform(QString name = "", QString exe_path = "", QString lib_path = "");
    QStringList cmd_str;

    // Getter-Setter
    QString getName() const;                    // name
    void setName(const QString &value);
    QString getExe_path() const;                // exe_path
    void setExe_path(const QString &value);
    QString getLib_path() const;                // lib_path
    void setLib_path(const QString &value);
    QString getExt() const;
    void setExt(const QString &value);

    // Methods
    void save() const;              // write to json
    void load(const QString &path); // read from json
    void print() const;             // print to qDebug()
    void loadCmdStr();              // load command structure in cmd_str

    QJsonObject toJsonObject() const;   // convert to jsonObject

    void addGame(Game g);           // add game to games
    void removeGame(QString name);  // remove game from games
    void launchGame(const Game &g) const;   // launch game with emulator
};

#endif // PLATFORM_H
