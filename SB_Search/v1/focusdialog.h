#ifndef FOCUSDIALOG_H
#define FOCUSDIALOG_H

#include <QDialog>
#include<QVector>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QFile>
#include<QTextStream>
#include<QString>

namespace Ui {
    class FocusDialog;
}

class FocusDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FocusDialog(QWidget *parent = 0);
    ~FocusDialog();
    void setUser(QString);

private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::FocusDialog *ui;
    QString user;
    QVector<QString> data;
};

#endif // FOCUSDIALOG_H
