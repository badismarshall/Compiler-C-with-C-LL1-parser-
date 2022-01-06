#include "dialog.h"
#include "ui_dialog.h"
#include<iostream>
using namespace std;
extern string id;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Les Identificateurs");
    ui->textBrowser->clear();
    QString identif=QString::fromStdString(id);
    ui->textBrowser->append(identif);
}

Dialog::~Dialog()
{
    delete ui; 
}
