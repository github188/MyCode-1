#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void get_Text(QString);
    void get_filename(QString);

private slots:
    void toPDF();

private:
    Ui::Dialog *ui;
    QString doc_text;
    QString filename;
};

#endif // DIALOG_H
