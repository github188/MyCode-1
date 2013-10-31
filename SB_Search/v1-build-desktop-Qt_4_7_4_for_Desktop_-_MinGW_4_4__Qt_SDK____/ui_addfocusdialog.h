/********************************************************************************
** Form generated from reading UI file 'addfocusdialog.ui'
**
** Created: Mon Feb 13 17:47:15 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFOCUSDIALOG_H
#define UI_ADDFOCUSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFocusDialog
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QDialog *AddFocusDialog)
    {
        if (AddFocusDialog->objectName().isEmpty())
            AddFocusDialog->setObjectName(QString::fromUtf8("AddFocusDialog"));
        AddFocusDialog->resize(366, 300);
        lineEdit = new QLineEdit(AddFocusDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 10, 191, 20));
        label = new QLabel(AddFocusDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 54, 16));
        pushButton = new QPushButton(AddFocusDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 10, 75, 23));
        tableWidget = new QTableWidget(AddFocusDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 40, 331, 241));

        retranslateUi(AddFocusDialog);

        QMetaObject::connectSlotsByName(AddFocusDialog);
    } // setupUi

    void retranslateUi(QDialog *AddFocusDialog)
    {
        AddFocusDialog->setWindowTitle(QApplication::translate("AddFocusDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddFocusDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AddFocusDialog", "\346\237\245\346\211\276", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddFocusDialog: public Ui_AddFocusDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFOCUSDIALOG_H
