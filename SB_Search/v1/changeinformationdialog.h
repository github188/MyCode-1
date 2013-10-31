#ifndef CHANGEINFORMATIONDIALOG_H
#define CHANGEINFORMATIONDIALOG_H

#include <QDialog>
#include <QString>
#include "userdialog.h"

namespace Ui {
    class ChangeInformationDialog;
}

class ChangeInformationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeInformationDialog(QWidget *parent = 0);
    ~ChangeInformationDialog();
    void get_right(int,QString,UserDialog*);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChangeInformationDialog *ui;
    int right;
    QString user;
    UserDialog* u;
};

#endif // CHANGEINFORMATIONDIALOG_H
