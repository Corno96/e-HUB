#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QListWidgetItem>
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>

#include <QDebug>
#include <QUrl>
#include <QVector>
#include <QProcess>

#include "library.h"

enum pages{ADD_PLATFORM, BLANK};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // load library
    Library l = Library();

    QVector<QString> names = {"ciao", "bella", "wow", "figo", "wowowo"};
    int columns = 2;

    QHBoxLayout* layout = new QHBoxLayout;
    QWidget* widget = new QWidget(this);

    for (int i=0;i<names.size();++i) {
        QPushButton* button = new QPushButton(this);
        button->setText(names[i]);

        layout->addWidget(button);
        if (i==0)
        {

        }
        else if (i%columns == 0) {
            widget->setLayout(layout);

            ui->platforms->layout()->addWidget(widget);
            widget->show();

            widget = new QWidget(this);
            layout = new QHBoxLayout;
        }
    }

    if (layout->count() != 0) {
        widget->setLayout(layout);

        ui->platforms->layout()->addWidget(widget);
        widget->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_switch_add_platform_button_clicked()
{
    //ui->stackedWidget->setCurrentIndex(ADD_PLATFORM);
}

void MainWindow::on_add_platform_button_clicked()
{
    /*
    // get from user exe_path, lib_path and create platform(write to file)
    Platform p = Platform(ui->name->text(), ui->exe_path->text(), ui->lib_path->text());

    p.save();

    // add button for new platform
    QPushButton* p_button = new QPushButton();
    p_button->setText(p.getName());

    ui->left_panel->layout()->addWidget(p_button);

    ui->stackedWidget->setCurrentIndex(BLANK);
    */
}


void MainWindow::on_browse_exe_button_clicked()
{
    /*
    QUrl dir = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home", tr("Executables (*.exe)"));
    ui->exe_path->setText(dir.path());
    */
}

void MainWindow::on_browse_lib_button_clicked()
{
    /*
    QUrl dir = QFileDialog::getExistingDirectoryUrl(this, tr("Open Directory"),
                                                    QUrl(QString("/home")),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    ui->lib_path->setText(dir.path());
    */
}
