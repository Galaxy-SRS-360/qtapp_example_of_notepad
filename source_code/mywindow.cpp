#include "mywindow.h"
#include "ui_mywindow.h"
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>

MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MyWindow::~MyWindow()
{
    delete ui;
}

void MyWindow::on_actionAdd_New_triggered()
{
    file_path="";
    ui->textEdit->setText("");
}


void MyWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"open the file");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}


void MyWindow::on_actionSave_triggered()
{
    // QString file_name = QFileDialog::getSaveFileName(this,"open the file")
    QFile file(file_path);

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();

}


void MyWindow::on_actionSave_As_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"open the file");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();

}


void MyWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MyWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MyWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MyWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MyWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}
/*
 * QString  about_text ;
 * about_text ="Auther : me\n;
 * about_txt += "Date : 30/06/2024\n";
 * about+= "(c) Notepad (R)\n";
 *QNessageBox::about(this,"About Notepad",about_text);
 */

