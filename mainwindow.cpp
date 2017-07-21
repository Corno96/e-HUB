#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QListWidgetItem>
#include <QDebug>
#include <QUrl>

#include <QVector>

#include "library.h"

enum pages{ADD_PLATFORM, BLANK};



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load the library
    Library library;

    library.load();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_switch_add_platform_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(ADD_PLATFORM);
}


void MainWindow::on_add_platform_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(BLANK);
}

void MainWindow::on_add_platform_button_clicked()
{
    // get from user exe_path, lib_path and create platform(write to file)
    Platform p = Platform(ui->name->text(), ui->exe_path->text(), ui->lib_path->text());

    p.print();

    p.save();

    ui->stackedWidget->setCurrentIndex(BLANK);
}


void MainWindow::on_browse_exe_button_clicked()
{
    QUrl dir = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home", tr("Executables (*.exe)"));
    ui->exe_path->setText(dir.path());
}

void MainWindow::on_browse_lib_button_clicked()
{
    QUrl dir = QFileDialog::getExistingDirectoryUrl(this, tr("Open Directory"),
                                                    QUrl(QString("/home")),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    ui->lib_path->setText(dir.path());
}
