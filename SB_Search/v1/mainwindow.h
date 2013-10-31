#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
#include <QString>
#include <QMainWindow>
#include <inf_str.h>
#include <QTableWidgetItem>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setUser(QString);

private slots:
    void SearchClicked();    // 搜索
    void OnItemClicked(QTableWidgetItem *);

    void on_pushButton_2_clicked();

    void on_pushButton_User_clicked();

private:
    void Search(QVector<QString>);
    QString choose_name(QString,inf_str);

    Ui::MainWindow *ui;
    QVector<inf_str> data;
    inf_str get_str();
    bool search_base(inf_str,int);
    QString document(inf_str);
    void init();
    bool search_extend(QString,int);
    bool deal(QString,QString);
    QString get_doc(QString);
    bool use[300];  //是否被检索到
    QString s_goal;
    int mark[10000];//结果表格
    void special_table(inf_str,QString s1,QString s2);
    void toPDF(QString,QString);
    bool check(QString);

    QString user;
    void sharedpro(int);
};

#endif // MAINWINDOW_H
