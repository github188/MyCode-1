/********************************************************************************
** Form generated from reading UI file 'focusdialog.ui'
**
** Created: Mon Feb 13 17:47:15 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOCUSDIALOG_H
#define UI_FOCUSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_FocusDialog
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *FocusDialog)
    {
        if (FocusDialog->objectName().isEmpty())
            FocusDialog->setObjectName(QString::fromUtf8("FocusDialog"));
        FocusDialog->resize(400, 300);
        tableWidget = new QTableWidget(FocusDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 30, 371, 251));
        label = new QLabel(FocusDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 81, 16));
        pushButton = new QPushButton(FocusDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 0, 75, 23));

        retranslateUi(FocusDialog);

        QMetaObject::connectSlotsByName(FocusDialog);
    } // setupUi

    void retranslateUi(QDialog *FocusDialog)
    {
        FocusDialog->setWindowTitle(QApplication::translate("FocusDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FocusDialog", "\346\210\221\345\205\263\346\263\250\347\232\204\347\224\250\346\210\267\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("FocusDialog", "\346\267\273\345\212\240\345\205\263\346\263\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FocusDialog: public Ui_FocusDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOCUSDIALOG_H
