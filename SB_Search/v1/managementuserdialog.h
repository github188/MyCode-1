#ifndef MANAGEMENTUSERDIALOG_H
#define MANAGEMENTUSERDIALOG_H

#include <QDialog>
#include<QVector>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QFile>
#include<QTextStream>
#include<QString>

namespace Ui {
    class ManagementUserDialog;
}

class ManagementUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManagementUserDialog(QWidget *parent = 0);
    ~ManagementUserDialog();
    void setUser(QString);

private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::ManagementUserDialog *ui;
    QString user;
    QVector<QString> uList;
    QVector<int> uRight;
};

#endif // MANAGEMENTUSERDIALOG_H
