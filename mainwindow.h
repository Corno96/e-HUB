#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "library.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void drawGrid(QVector<QString> vec, Library *library = 0);
    Ui::MainWindow* getUI();
    int getColumns();

    enum Pages{PLATFORM, GAME};

private slots:
    // ADD PLATFORM PAGE
    void on_add_platform_button_clicked();
    void on_browse_exe_button_clicked();
    void on_browse_lib_button_clicked();
    void on_switch_add_platform_button_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int columns;
};

#endif // MAINWINDOW_H
