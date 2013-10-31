#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QString>
#include <QMap>

namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    void get_pMW(MainWindow*);
    ~LoginDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginDialog *ui;
    MainWindow* pMW;
    QMap<QString,QString> data;

};

#endif // LOGINDIALOG_H
