#ifndef GUESTPAYDIALOG_H
#define GUESTPAYDIALOG_H

#include <QDialog>
#include<QString>

namespace Ui {
    class GuestPayDialog;
}

class GuestPayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GuestPayDialog(QWidget *parent = 0);
    ~GuestPayDialog();
    void setUser(QString);

private:
    Ui::GuestPayDialog *ui;
    QString user;
};

#endif // GUESTPAYDIALOG_H
