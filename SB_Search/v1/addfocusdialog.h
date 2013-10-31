#ifndef ADDFOCUSDIALOG_H
#define ADDFOCUSDIALOG_H

#include <QDialog>
#include<QVector>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QFile>
#include<QTextStream>
#include<QString>
#include"focusdialog.h"

namespace Ui {
    class AddFocusDialog;
}

class AddFocusDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddFocusDialog(QWidget *parent = 0);
    ~AddFocusDialog();
    void setUser(QString,FocusDialog*);

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::AddFocusDialog *ui;
    QString user;
    FocusDialog* pFD;
    QVector<QString> vec;

};

#endif // ADDFOCUSDIALOG_H
