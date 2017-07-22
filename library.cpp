#include "library.h"

#include <QDirIterator>
#include <QDebug>

Library::Library() {}

void Library::save() const {
    // create library folder if it doesn't exists
}

void Library::load() {
    // if folder doesn't exists
    if (QDir(QDir::currentPath() + "/library").exists() == false)
        return;

    QDirIterator it(QDir::currentPath() + "/library/");

    // iterate through library folder
    while (it.hasNext()) {
        QString path = it.next();

        // if file is a json platform
        if (path.toStdString().find(".json") != std::string::npos) {
            // create platform and add to library
            Platform* temp = new Platform();

            temp->load(path);

            library.append(*temp);
        }
    }
}

void Library::print() const {
    for (int i=0;i<library.size();++i) {
        library.at(i).print();
    }
}
