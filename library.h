#ifndef LIBRARY_H
#define LIBRARY_H

#include "platform.h"

#include <QMap>

class Library {
private:
    QVector<Platform> library;

public:
    // Constructors
    Library();

    QVector<Platform> getLibrary() const;
    void setLibrary(const QVector<Platform> &value);

    // Methods
    void save() const;
    void load();

    void print() const;
};

#endif // LIBRARY_H


