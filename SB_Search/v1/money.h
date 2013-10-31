#ifndef MONEY_H
#define MONEY_H

#include <QDialog>
#include<QString>
#include<QVector>
#include"inf_str.h"

namespace Ui {
    class Money;
}

class Money : public QDialog
{
    Q_OBJECT

public:
    explicit Money(QWidget *parent = 0);
    ~Money();
    void get_inf(QVector<inf_str>);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Money *ui;
    QVector< inf_str > data;
};

#endif // MONEY_H
