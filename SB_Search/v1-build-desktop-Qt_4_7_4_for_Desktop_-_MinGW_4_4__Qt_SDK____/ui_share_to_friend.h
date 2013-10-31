/********************************************************************************
** Form generated from reading UI file 'share_to_friend.ui'
**
** Created: Mon Feb 13 17:47:14 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHARE_TO_FRIEND_H
#define UI_SHARE_TO_FRIEND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Share_to_Friend
{
public:
    QTableWidget *tableWidget;

    void setupUi(QDialog *Share_to_Friend)
    {
        if (Share_to_Friend->objectName().isEmpty())
            Share_to_Friend->setObjectName(QString::fromUtf8("Share_to_Friend"));
        Share_to_Friend->resize(400, 300);
        tableWidget = new QTableWidget(Share_to_Friend);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(Share_to_Friend);

        QMetaObject::connectSlotsByName(Share_to_Friend);
    } // setupUi

    void retranslateUi(QDialog *Share_to_Friend)
    {
        Share_to_Friend->setWindowTitle(QApplication::translate("Share_to_Friend", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Share_to_Friend: public Ui_Share_to_Friend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHARE_TO_FRIEND_H
