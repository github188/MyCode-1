#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>
#include "logindialog.h"

int main(int argc, char *argv[])
{

    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QApplication a(argc, argv);
    MainWindow* w;
    w=NULL;
    //w.show();
    LoginDialog ld;
    ld.get_pMW(w);
    ld.show();

    return a.exec();
}
