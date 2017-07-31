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
#include "platform_button.h"

Library l = Library();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    columns = 2;

    // load library
    //Library l = Library();

    QVector<QString> names = {"PS1", "Gamecube", "wow", "figo", "wowowo"};

    drawGrid(names, &l);

    /*
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
        layout->setAlignment(Qt::AlignLeft);
        widget->setLayout(layout);

        ui->platforms->layout()->addWidget(widget);
        widget->show();
    }
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawGrid(QVector<QString> vec, Library* library)
{
    QHBoxLayout* layout = new QHBoxLayout;
    QWidget* widget = new QWidget(this);

    for (auto widget: ui->platforms->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly))
      delete widget;

    for (int i=0;i<=(vec.size()/columns);++i){

        for (int k=0;k<columns;++k) {
            if (i*columns + k >= vec.size())
                break;

            Platform* p = library->getPlatform(vec[i*columns+k]);

            qDebug() << "Dopo : " << p;

            if (p != nullptr)
                p->print();

            // create button and add it to layout
            PButton* button = new PButton(this, this, p);
            QObject::connect(button, SIGNAL(clicked(bool)), button, SLOT(choosePlatform()));
            button->setText(vec[i*columns+k]);

            layout->addWidget(button);
        }

        // set widget layout and add it to main layout
        //layout->setAlignment(Qt::AlignLeft);
        widget->setLayout(layout);

        ui->platforms->layout()->addWidget(widget);
        widget->show();

        widget = new QWidget(this);
        layout = new QHBoxLayout;
    }
}

Ui::MainWindow* MainWindow::getUI() {
    return ui;
}

int MainWindow::getColumns() {
    return columns;
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

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QVector<QString> names = {"PS1", "bella", "wow", "figo", "wowowo"};

    columns = arg1.toInt();

    drawGrid(names, &l);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(PLATFORM);
}
