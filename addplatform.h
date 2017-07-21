#ifndef ADDPLATFORM_H
#define ADDPLATFORM_H

#include <QDialog>
#include "ui_addplatform.h"

class AddPlatformDialog : public QDialog, public Ui::Dialog{
    Q_OBJECT

public:
    AddPlatformDialog(QWidget *parent);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
};

#endif // ADDPLATFORM_H
