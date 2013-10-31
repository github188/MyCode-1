/********************************************************************************
** Form generated from reading UI file 'changeinformationdialog.ui'
**
** Created: Mon Feb 13 17:47:14 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINFORMATIONDIALOG_H
#define UI_CHANGEINFORMATIONDIALOG_H

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

class Ui_ChangeInformationDialog
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QDialog *ChangeInformationDialog)
    {
        if (ChangeInformationDialog->objectName().isEmpty())
            ChangeInformationDialog->setObjectName(QString::fromUtf8("ChangeInformationDialog"));
        ChangeInformationDialog->resize(400, 142);
        label = new QLabel(ChangeInformationDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 54, 12));
        lineEdit = new QLineEdit(ChangeInformationDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 10, 251, 20));
        label_2 = new QLabel(ChangeInformationDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(13, 40, 71, 20));
        lineEdit_2 = new QLineEdit(ChangeInformationDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 40, 251, 20));
        label_3 = new QLabel(ChangeInformationDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 70, 54, 12));
        lineEdit_3 = new QLineEdit(ChangeInformationDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 70, 251, 20));
        label_4 = new QLabel(ChangeInformationDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 110, 111, 16));
        pushButton = new QPushButton(ChangeInformationDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 110, 75, 23));

        retranslateUi(ChangeInformationDialog);

        QMetaObject::connectSlotsByName(ChangeInformationDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangeInformationDialog)
    {
        ChangeInformationDialog->setWindowTitle(QApplication::translate("ChangeInformationDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChangeInformationDialog", "\346\226\260\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ChangeInformationDialog", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ChangeInformationDialog", "E-mail\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        pushButton->setText(QApplication::translate("ChangeInformationDialog", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChangeInformationDialog: public Ui_ChangeInformationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFORMATIONDIALOG_H
