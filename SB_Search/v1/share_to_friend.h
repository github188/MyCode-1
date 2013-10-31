#ifndef SHARE_TO_FRIEND_H
#define SHARE_TO_FRIEND_H

#include <QDialog>
#include <QString>
#include<QVector>
#include<QTableWidgetItem>

namespace Ui {
    class Share_to_Friend;
}

class Share_to_Friend : public QDialog
{
    Q_OBJECT

public:
    explicit Share_to_Friend(QWidget *parent = 0);
    ~Share_to_Friend();
    void get_inf(QString,QString,QString);
    void work();

private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::Share_to_Friend *ui;
    QString user,id,name;
    QVector<QString> s;
};

#endif // SHARE_TO_FRIEND_H
