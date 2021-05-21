#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpression reg_exp("[0-9]{1,5}");
    ui->sizeEdit->setValidator(new QRegularExpressionValidator(reg_exp, this));
    connect(ui->sizeEdit, SIGNAL(textEdited(QString)), this, SLOT(SizeEdit_changet()));
    //connect(ui->createButton, SIGNAL(clicked()), this, SLOT(accept()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SizeEdit_changet(){
    ui->statusbar->clearMessage();
    ui->sizeEdit->setStyleSheet("background : white;");
    ui->createButton->setEnabled(!ui->sizeEdit->text().isEmpty() && ui->sizeEdit->text().toInt()<=20000);
    if(ui->sizeEdit->text().toInt()>20000){
        ui->statusbar->showMessage("Введіть значення, менше 20000.");
        ui->sizeEdit->setStyleSheet("background : red;");
    }
}
