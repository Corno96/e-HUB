#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAdd_platform_triggered();

    void on_add_platform_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
