#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpression reg_exp("[0-9]{1,5}");
    ui->sizeEdit->setValidator(new QRegularExpressionValidator(reg_exp, this));
    ui->searchEdit->setValidator(new QRegularExpressionValidator(reg_exp, this));
    connect(ui->sizeEdit, SIGNAL(textEdited(QString)), this, SLOT(SizeEdit_changet()));
    connect(ui->searchEdit, SIGNAL(textEdited(QString)), this, SLOT(SearchEdit_changet()));
    connect(ui->createButton, SIGNAL(clicked()), this, SLOT(CreateButton_clicked()));
    connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(SearchButton_clicked()));
    algoritm = new SearchAlgoritms(0, 0);
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
    ui->showMassButton->setEnabled(true);
    ui->searchEdit->setEnabled(true);
    algoritm->delete_mass();
    algoritm->setSize(ui->sizeEdit->text().toInt());
    algoritm->create_mass();
    algoritm->init_mass();
}

void MainWindow::SearchButton_clicked(){
    int p=-1;
    QString str = ui->comboBox->currentText();
    if(str == "Послідовний пошук"){
        algoritm->setValue(ui->searchEdit->text().toInt());
        p = algoritm->pos_search();
        ui->statusbar->showMessage("Відбувся послідовний пошук. Pos = "+QString::number(p));
    }
    if(str == "Метод Фібоначі"){
        algoritm->setValue(ui->searchEdit->text().toInt());
        p = algoritm->fibonachii_search();
        ui->statusbar->showMessage("Відбувся пошук Фібоначі. Pos = "+QString::number(p));
    }
    if(str == "Інтерполяційний метод"){
        algoritm->setValue(ui->searchEdit->text().toInt());
        p = algoritm->interpolar_search();
        ui->statusbar->showMessage("Відбувся інтерполяційний пошук. Pos = "+QString::number(p));
    }
    if(str == "Метод хеш-функції"){
        algoritm->setValue(ui->searchEdit->text().toInt());
        //p = algoritm->pos_search();
        p = 99;
        ui->statusbar->showMessage("Відбувся пошук хеш-функцією. Pos = "+QString::number(p));
    }

    if(p==-1){
         ui->indexEdit->setText("Елемент відсутній");
    }
    else {
        ui->indexEdit->setText(QString::number(p));
    }
}

void MainWindow::SearchEdit_changet(){
    ui->statusbar->clearMessage();
    ui->searchEdit->setStyleSheet("background : white;");
    ui->searchButton->setEnabled(!ui->searchEdit->text().isEmpty() && ui->searchEdit->text().toInt() != 0);
    if(ui->searchEdit->text().toInt() == 0 && !ui->searchEdit->text().isEmpty()){
        ui->statusbar->showMessage("Введіть значення,  більше 0.");
        ui->searchEdit->setStyleSheet("background : red;");
        ui->searchEdit->clear();
    }
}
