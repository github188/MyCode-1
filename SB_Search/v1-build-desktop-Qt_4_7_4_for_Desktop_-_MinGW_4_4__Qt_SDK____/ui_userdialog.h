/********************************************************************************
** Form generated from reading UI file 'userdialog.ui'
**
** Created: Mon Feb 13 17:47:14 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDIALOG_H
#define UI_USERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QLabel *label_8;
    QTableWidget *tableWidget;
    QLabel *label_9;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName(QString::fromUtf8("UserDialog"));
        UserDialog->resize(333, 460);
        groupBox = new QGroupBox(UserDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 301, 151));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 54, 12));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 20, 54, 12));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 40, 41, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 40, 171, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 60, 54, 12));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 80, 131, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 100, 131, 16));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 120, 75, 23));
        label_8 = new QLabel(UserDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 170, 54, 12));
        tableWidget = new QTableWidget(UserDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 190, 301, 101));
        label_9 = new QLabel(UserDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 310, 54, 12));
        tableWidget_2 = new QTableWidget(UserDialog);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 330, 301, 91));
        pushButton_2 = new QPushButton(UserDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 300, 75, 23));
        pushButton_3 = new QPushButton(UserDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 430, 75, 23));
        pushButton_4 = new QPushButton(UserDialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(200, 430, 75, 23));

        retranslateUi(UserDialog);

        QMetaObject::connectSlotsByName(UserDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDialog)
    {
        UserDialog->setWindowTitle(QApplication::translate("UserDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("UserDialog", "\346\210\221\347\232\204\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("UserDialog", "\351\202\256\347\256\261\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_5->setText(QApplication::translate("UserDialog", "\345\275\223\345\211\215\346\235\203\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        label_7->setText(QString());
        pushButton->setText(QApplication::translate("UserDialog", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("UserDialog", "\346\210\221\347\232\204\346\224\266\350\227\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("UserDialog", "\346\216\250\350\215\220\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("UserDialog", "\345\205\263\346\263\250\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("UserDialog", "\345\242\236\345\212\240\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("UserDialog", "\346\235\203\351\231\220\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserDialog: public Ui_UserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDIALOG_H
