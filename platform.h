#ifndef PLATFORM_H
#define PLATFORM_H

#include <QUrl>
#include <QFile>

class Platform
{
private:
    QString name;
    QUrl path;

public:
    Platform();
    Platform(QString name, QUrl path);

    void setName(QString name);
    QString getName() const;
    void setPath(QUrl path);
    QUrl getPath() const;

    void Write() const;
    void Read();
};

#endif // PLATFORM_H
