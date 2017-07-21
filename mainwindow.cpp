#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QListWidgetItem>
#include <QDebug>
#include <QUrl>


#include "platform.h"
#include "addplatform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->add_platform->setStyleSheet("background-image: url(:/images/hydro.png)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_platform_triggered()
{
    AddPlatformDialog* d = new AddPlatformDialog(this);
    d->show();







    //Platform p = Platform(dir.fileName(), dir.path());
    //p.Read();
}

void MainWindow::on_add_platform_clicked()
{
    AddPlatformDialog* d = new AddPlatformDialog(this);
    d->show();
}
