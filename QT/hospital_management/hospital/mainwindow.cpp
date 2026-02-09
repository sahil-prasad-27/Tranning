#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStringList>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(addBtn()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(searchBtn()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(exitBtn()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList id;
QStringList name;
QStringList group;
QStringList disease;
void MainWindow::addBtn()
{
    QString pID=ui->lineEdit->text();
    QString pName=ui->lineEdit_2->text();
    QString pGroup=ui->comboBox->currentText();
    QString pDisease=ui->lineEdit_3->text();

    if(!pID.isEmpty()){
        id.append(pID);
        ui->lineEdit->clear();
    }else{QMessageBox::information(this,"Error",
                                   "Enter Patient ID! ");
    }
    if(!pName.isEmpty()){
        name.append(pName);
        ui->lineEdit_2->clear();

    }else{QMessageBox::information(this,"Error",
                                   "Enter Patient name! ");
    }
    if(!pGroup.isEmpty()){
        group.append(pGroup);
        ui->comboBox->clear();
    }else{QMessageBox::information(this,"Error",
                                   "Enter Patient Group! ");
    }
    if(!pDisease.isEmpty()){
        disease.append(pDisease);
        ui->lineEdit_3->clear();
    }else{QMessageBox::information(this,"Error",
                                   "Enter Patient disease! ");
    }
}

void MainWindow::searchBtn()
{
    QString pID=ui->lineEdit->text();
    for( int i=0;i<id.length();i++){
        if(pID==id[i]){
            QMessageBox::information(this,"Success", "Patient Id: "+id[i]+"\n Patient Name "+name[i]+"\n Patient Blood Group"+group[i]+"\n Patient Disease: "+disease[i]+"\n");
        }
    }
}

void MainWindow::exitBtn()
{
    close();
}
