#include "dialog.h"
#include "ui_dialog.h"
#include<QPrinter>
#include<QTextDocument>
#include<QFileDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(toPDF()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::get_Text(QString s)
{
    doc_text=s;
    ui->textEdit->setPlainText(s);
}
/*
void Dialog::toPDF()
{
    QPrinter p;
    QTextDocument doc;
    QString ans;ans.clear();
    for (int i=0;i<doc_text.length();i++)
        if (doc_text[i]!='\n')
        {
            ans+=doc_text[i];
        } else ans+="<br>";

    doc.setHtml(ans);
    p.setPageSize(QPrinter::A4);
    p.setOutputFormat(QPrinter::PdfFormat);
    p.setOutputFileName(filename);
    doc.print(&p);
}
*/

void Dialog::toPDF()
{
    QFileDialog *filedialog;
    filedialog=new QFileDialog();
    QString us="../"+filename;
    filename=filedialog->getSaveFileName(0,"Save File",us,"Portable Document Format (*.pdf)");

    QPrinter p;
    QTextDocument doc;
    QString ans;ans.clear();
    for (int i=0;i<doc_text.length();i++)
        if (doc_text[i]!='\n')
        {
            ans+=doc_text[i];
        } else ans+="<br>";

    doc.setHtml(ans);
    p.setPageSize(QPrinter::A4);
    p.setOutputFormat(QPrinter::PdfFormat);
    p.setOutputFileName(filename);
    doc.print(&p);
}

void Dialog::get_filename(QString s)
{
    filename=s;
    filename+=".pdf";
}
