#ifndef LIBRARY_H
#define LIBRARY_H

#include <QVector>
#include "platform.h"

class Library {
private:
    QVector<Platform> *library;

public:
    // Constructors
    Library();

    // Getter-Setter
    const QVector<Platform>* getLibrary() const;
    void setLibrary(QVector<Platform> *value);

    // Methods
    void save() const;
    void load();

    void print() const;
};

#endif // LIBRARY_H


