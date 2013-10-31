/********************************************************************************
** Form generated from reading UI file 'money.ui'
**
** Created: Mon Feb 13 17:47:14 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONEY_H
#define UI_MONEY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Money
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QDialog *Money)
    {
        if (Money->objectName().isEmpty())
            Money->setObjectName(QString::fromUtf8("Money"));
        Money->resize(272, 300);
        label = new QLabel(Money);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 20));
        label_2 = new QLabel(Money);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(113, 20, 61, 21));
        comboBox = new QComboBox(Money);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 50, 131, 22));
        label_3 = new QLabel(Money);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 50, 81, 20));
        pushButton = new QPushButton(Money);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 80, 75, 23));
        tableWidget = new QTableWidget(Money);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 111, 256, 181));

        retranslateUi(Money);

        QMetaObject::connectSlotsByName(Money);
    } // setupUi

    void retranslateUi(QDialog *Money)
    {
        Money->setWindowTitle(QApplication::translate("Money", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Money", "\345\275\223\345\211\215\346\237\245\350\257\242\346\200\273\347\273\217\350\264\271", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("Money", "\345\210\206\347\261\273\347\273\217\350\264\271\347\273\237\350\256\241", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Money", "\347\273\237\350\256\241", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Money: public Ui_Money {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONEY_H
