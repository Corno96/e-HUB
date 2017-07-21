#include "addplatform.h"
#include <QFileDialog>

#include "platform.h"

AddPlatformDialog::AddPlatformDialog(QWidget *parent) : QDialog(parent) {

    setupUi(this);

}

void AddPlatformDialog::on_pushButton_clicked()
{
    QFileDialog dialog;
    //dialog.setFileMode(QFileDialog::Directory);
    QUrl dir = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home", tr("Executables (*.exe)"));

    this->exe_path->setText(dir.path());
}

void AddPlatformDialog::on_pushButton_2_clicked()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::Directory);
    QUrl dir = QFileDialog::getExistingDirectoryUrl(this, tr("Open Directory"),
                                                    QUrl(QString("/home")),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    this->lib_path->setText(dir.path());
}


void AddPlatformDialog::on_pushButton_3_clicked()
{
    // get from user exe_path, lib_path and create platform(write to file)
    Platform p;

    p = Platform(this->name->text(), this->exe_path->text(), this->lib_path->text());

    p.Write();

    this->hide();
}

