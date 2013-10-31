#ifndef ADDPRODIALOG_H
#define ADDPRODIALOG_H

#include <QDialog>
#include <QString>
#include<QFile>
#include<QTextStream>

namespace Ui {
    class AddProDialog;
}

class AddProDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProDialog(QWidget *parent = 0);
    ~AddProDialog();
    void setUser(QString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddProDialog *ui;
    QString user;
};

#endif // ADDPRODIALOG_H
