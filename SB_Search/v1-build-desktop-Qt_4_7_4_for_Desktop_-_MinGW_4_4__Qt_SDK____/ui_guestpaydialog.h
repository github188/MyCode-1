/********************************************************************************
** Form generated from reading UI file 'guestpaydialog.ui'
**
** Created: Mon Feb 13 17:59:33 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESTPAYDIALOG_H
#define UI_GUESTPAYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_GuestPayDialog
{
public:
    QLabel *label;
    QWebView *webView;

    void setupUi(QDialog *GuestPayDialog)
    {
        if (GuestPayDialog->objectName().isEmpty())
            GuestPayDialog->setObjectName(QString::fromUtf8("GuestPayDialog"));
        GuestPayDialog->resize(606, 406);
        label = new QLabel(GuestPayDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 181, 16));
        webView = new QWebView(GuestPayDialog);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setGeometry(QRect(0, 20, 581, 371));
        webView->setUrl(QUrl("about:blank"));

        retranslateUi(GuestPayDialog);

        QMetaObject::connectSlotsByName(GuestPayDialog);
    } // setupUi

    void retranslateUi(QDialog *GuestPayDialog)
    {
        GuestPayDialog->setWindowTitle(QApplication::translate("GuestPayDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GuestPayDialog", "\350\257\267\350\264\255\344\271\260\350\257\245\346\226\207\347\214\256\345\257\237\347\234\213\346\235\203\351\231\220", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GuestPayDialog: public Ui_GuestPayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESTPAYDIALOG_H
