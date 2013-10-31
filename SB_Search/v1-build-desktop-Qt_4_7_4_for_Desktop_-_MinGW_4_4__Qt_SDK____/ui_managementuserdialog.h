/********************************************************************************
** Form generated from reading UI file 'managementuserdialog.ui'
**
** Created: Mon Feb 13 17:47:15 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEMENTUSERDIALOG_H
#define UI_MANAGEMENTUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagementUserDialog
{
public:
    QTableWidget *tableWidget;
    QLabel *label;

    void setupUi(QDialog *ManagementUserDialog)
    {
        if (ManagementUserDialog->objectName().isEmpty())
            ManagementUserDialog->setObjectName(QString::fromUtf8("ManagementUserDialog"));
        ManagementUserDialog->resize(400, 300);
        tableWidget = new QTableWidget(ManagementUserDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 20, 401, 281));
        label = new QLabel(ManagementUserDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 371, 16));

        retranslateUi(ManagementUserDialog);

        QMetaObject::connectSlotsByName(ManagementUserDialog);
    } // setupUi

    void retranslateUi(QDialog *ManagementUserDialog)
    {
        ManagementUserDialog->setWindowTitle(QApplication::translate("ManagementUserDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ManagementUserDialog", "\345\215\225\345\207\273\347\224\250\346\210\267\346\211\200\345\234\250\350\241\214\345\257\271\345\272\224\345\261\236\346\200\247\345\210\227\345\210\231\346\224\271\345\217\230\350\257\245\345\261\236\346\200\247\357\274\214\346\230\257\346\224\271\344\270\272\345\220\246\357\274\214\345\220\246\346\224\271\344\270\272\346\230\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManagementUserDialog: public Ui_ManagementUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEMENTUSERDIALOG_H
