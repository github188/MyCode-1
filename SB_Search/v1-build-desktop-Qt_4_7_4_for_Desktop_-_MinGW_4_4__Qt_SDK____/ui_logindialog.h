/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created: Mon Feb 13 17:47:14 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(332, 149);
        label = new QLabel(LoginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 54, 21));
        lineEdit = new QLineEdit(LoginDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 20, 201, 20));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 60, 41, 16));
        lineEdit_2 = new QLineEdit(LoginDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 60, 201, 20));
        pushButton = new QPushButton(LoginDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 100, 75, 23));
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 100, 121, 16));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LoginDialog", "\347\231\273\351\231\206", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
