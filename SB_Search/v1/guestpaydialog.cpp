#include "guestpaydialog.h"
#include "ui_guestpaydialog.h"
#include<QUrl>
#include <QtWebKit/QWebView>
#include<QDesktopServices>

GuestPayDialog::GuestPayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuestPayDialog)
{
    ui->setupUi(this);
    QUrl qr("https://auth.alipay.com/login/index.htm?goto=");

    ui->webView->setUrl(qr);
    QDesktopServices::openUrl(qr);
}

GuestPayDialog::~GuestPayDialog()
{
    delete ui;
}

void GuestPayDialog::setUser(QString s)
{
    user=s;
}
