#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <QString>
#include<QFile>
#include<QTextStream>
#include<QSet>
#include<QVector>
#include<QTableWidget>
#include<QTableWidgetItem>
#include"focusdialog.h"
#include"addprodialog.h"

namespace Ui {
    class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog(QWidget *parent = 0);
    ~UserDialog();
    void setUser(QString);

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_2_itemClicked(QTableWidgetItem *item);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::UserDialog *ui;
    QString user,pwd,email;
    int right;
    QSet<QString> set;
    QVector<QString> data;

    bool check(QString);
};

#endif // USERDIALOG_H
