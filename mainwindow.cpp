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
    connect(ui->createButton, SIGNAL(clicked()), this, SLOT(CreateButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SizeEdit_changet(){
    ui->statusbar->clearMessage();
    ui->sizeEdit->setStyleSheet("background : white;");
    ui->createButton->setEnabled(!ui->sizeEdit->text().isEmpty() && ui->sizeEdit->text().toInt()<=20000 && ui->sizeEdit->text().toInt() != 0);
    if(ui->sizeEdit->text().toInt()>20000){
        ui->statusbar->showMessage("Введіть значення, менше 20000.");
        ui->sizeEdit->setStyleSheet("background : red;");
    }
    if(ui->sizeEdit->text().toInt() == 0 && !ui->sizeEdit->text().isEmpty()){
        ui->statusbar->showMessage("Введіть значення,  більше 0.");
        ui->sizeEdit->setStyleSheet("background : red;");
        ui->sizeEdit->clear();
    }
}

void MainWindow::CreateButton_clicked(){
    ui->searchButton->setEnabled(true);
    ui->showMassButton->setEnabled(true);
}
