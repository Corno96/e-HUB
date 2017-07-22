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
    // ADD PLATFORM PAGE
    void on_add_platform_button_clicked();
    void on_browse_exe_button_clicked();
    void on_browse_lib_button_clicked();
    void on_switch_add_platform_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
