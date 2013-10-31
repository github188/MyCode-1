/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Nov 27 16:28:08 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineNum;
    QLabel *label_3;
    QLineEdit *lineName;
    QLabel *label_4;
    QLineEdit *linetyp;
    QLabel *label_5;
    QLineEdit *lineSource;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineLeader;
    QLineEdit *lineStart_Time;
    QLabel *label_9;
    QLineEdit *lineCompany;
    QLineEdit *lineMoney;
    QLabel *label_10;
    QLineEdit *lineshxy;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_14;
    QLineEdit *lineyfcg;
    QLineEdit *lineyyqj;
    QLineEdit *linejjxy;
    QLabel *yfcg;
    QLineEdit *lineState;
    QLineEdit *lineyyqk;
    QLabel *label_17;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(644, 531);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 51, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 450, 75, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 20, 51, 16));
        lineNum = new QLineEdit(centralWidget);
        lineNum->setObjectName(QString::fromUtf8("lineNum"));
        lineNum->setGeometry(QRect(60, 30, 113, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 51, 16));
        lineName = new QLineEdit(centralWidget);
        lineName->setObjectName(QString::fromUtf8("lineName"));
        lineName->setGeometry(QRect(60, 60, 113, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 90, 51, 16));
        linetyp = new QLineEdit(centralWidget);
        linetyp->setObjectName(QString::fromUtf8("linetyp"));
        linetyp->setGeometry(QRect(60, 120, 113, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 120, 51, 16));
        lineSource = new QLineEdit(centralWidget);
        lineSource->setObjectName(QString::fromUtf8("lineSource"));
        lineSource->setGeometry(QRect(60, 90, 113, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 240, 51, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 150, 51, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 210, 51, 16));
        lineLeader = new QLineEdit(centralWidget);
        lineLeader->setObjectName(QString::fromUtf8("lineLeader"));
        lineLeader->setGeometry(QRect(60, 180, 113, 20));
        lineStart_Time = new QLineEdit(centralWidget);
        lineStart_Time->setObjectName(QString::fromUtf8("lineStart_Time"));
        lineStart_Time->setGeometry(QRect(60, 240, 113, 20));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 180, 61, 20));
        lineCompany = new QLineEdit(centralWidget);
        lineCompany->setObjectName(QString::fromUtf8("lineCompany"));
        lineCompany->setGeometry(QRect(60, 150, 113, 20));
        lineMoney = new QLineEdit(centralWidget);
        lineMoney->setObjectName(QString::fromUtf8("lineMoney"));
        lineMoney->setGeometry(QRect(60, 210, 113, 20));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 360, 51, 16));
        lineshxy = new QLineEdit(centralWidget);
        lineshxy->setObjectName(QString::fromUtf8("lineshxy"));
        lineshxy->setGeometry(QRect(60, 390, 113, 20));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 270, 51, 16));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 330, 51, 16));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 390, 51, 16));
        lineyfcg = new QLineEdit(centralWidget);
        lineyfcg->setObjectName(QString::fromUtf8("lineyfcg"));
        lineyfcg->setGeometry(QRect(60, 300, 113, 20));
        lineyyqj = new QLineEdit(centralWidget);
        lineyyqj->setObjectName(QString::fromUtf8("lineyyqj"));
        lineyyqj->setGeometry(QRect(60, 420, 113, 20));
        linejjxy = new QLineEdit(centralWidget);
        linejjxy->setObjectName(QString::fromUtf8("linejjxy"));
        linejjxy->setGeometry(QRect(60, 360, 113, 20));
        yfcg = new QLabel(centralWidget);
        yfcg->setObjectName(QString::fromUtf8("yfcg"));
        yfcg->setGeometry(QRect(10, 300, 51, 16));
        lineState = new QLineEdit(centralWidget);
        lineState->setObjectName(QString::fromUtf8("lineState"));
        lineState->setGeometry(QRect(60, 270, 113, 20));
        lineyyqk = new QLineEdit(centralWidget);
        lineyyqk->setObjectName(QString::fromUtf8("lineyyqk"));
        lineyyqk->setGeometry(QRect(60, 330, 113, 20));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 420, 51, 16));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(240, 40, 381, 431));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 644, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "v1", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Search", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        lineName->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256\346\235\245\346\272\220", 0, QApplication::UnicodeUTF8));
        linetyp->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\347\253\213\351\242\230\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\346\211\277\346\213\205\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\273\217\350\264\271", 0, QApplication::UnicodeUTF8));
        lineLeader->setText(QString());
        lineStart_Time->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256\350\264\237\350\264\243\344\272\272", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\347\273\217\346\265\216\346\225\210\347\233\212", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "\345\256\236\346\226\275\346\203\205\345\206\265", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "\345\272\224\347\224\250\346\203\205\345\206\265", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "\347\244\276\344\274\232\346\225\210\347\233\212", 0, QApplication::UnicodeUTF8));
        lineyfcg->setText(QString());
        lineyyqj->setText(QString());
        linejjxy->setText(QString());
        yfcg->setText(QApplication::translate("MainWindow", "\347\240\224\345\217\221\346\210\220\346\236\234", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "\345\272\224\347\224\250\345\211\215\346\231\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
