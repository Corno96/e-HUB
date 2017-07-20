#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>
#include <QUrl>

#include "platform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_platform_triggered()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::Directory);
    QUrl dir = QFileDialog::getExistingDirectoryUrl(this, tr("Open Directory"),
                                                    QUrl(),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    qDebug() << dir.fileName() << "; " << dir.path();

    Platform p = Platform("Playstation 1", dir);
    p.Write();
    p.Read();
}
