#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_5->hide();
    ui->massiveTable->hide();
    //layout()->setSizeConstraint(QLayout::SetFixedSize);
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
    ui->label_5->setVisible(false);
    ui->massiveTable->setVisible(false);
    ui->showMassButton->setEnabled(true);
    ui->showMassButton->setFocus();
    ui->searchButton->setEnabled(false);
    ui->checkBox->setEnabled(true);
    ui->searchEdit->setEnabled(true);
    ui->saveButton->setEnabled(false);
    ui->searchEdit->clear();
    ui->comboBox->setEnabled(true);
    ui->indexEdit->clear();
    ui->statusbar->clearMessage();
    algoritm->delete_mass();
    algoritm->setSize(ui->sizeEdit->text().toInt());
    algoritm->create_mass();
    algoritm->init_mass();
}

void MainWindow::SearchButton_clicked(){
    if(!ui->indexEdit->text().isEmpty()){
        ui->massiveTable->item(ui->indexEdit->text().toInt(), 0)->setBackground(Qt::white);
    }
    ui->saveButton->setEnabled(true);
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
        p = algoritm->hash_function_search();
        ui->statusbar->showMessage("Відбувся пошук хеш-функцією. Pos = "+QString::number(p));
    }

    if(p==-1){
         ui->indexEdit->setText("Елемент відсутній");
    }
    else {
        ui->indexEdit->setText(QString::number(p));
        ui->massiveTable->item(p, 0)->setBackground(Qt::yellow);

    }
}

void MainWindow::SearchEdit_changet(){
    ui->statusbar->clearMessage();
    ui->searchEdit->setStyleSheet("background : white;");
    ui->searchButton->setEnabled(!ui->searchEdit->text().isEmpty() && ui->searchEdit->text().toInt() != 0);
    ui->saveButton->setEnabled(false);
    if(ui->searchEdit->text().toInt() == 0 && !ui->searchEdit->text().isEmpty()){
        ui->statusbar->showMessage("Введіть значення,  більше 0.");
        ui->searchEdit->setStyleSheet("background : red;");
        ui->searchEdit->clear();
    }
}

void MainWindow::on_showMassButton_clicked()
{
    ui->massiveTable->setRowCount(algoritm->getSize());
    ui->massiveTable->setColumnCount(1);
    QStringList horizontal_names;
    for (int i=0;i<ui->massiveTable->rowCount();i++){
        for (int j=0;j<ui->massiveTable->columnCount();j++){
            horizontal_names << QString::number(i);
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(algoritm->getElement(i)));
            ui->massiveTable->setItem(i, j, newItem);
        }
    }
    ui->massiveTable->setVerticalHeaderLabels(horizontal_names);
    ui->massiveTable->setHorizontalHeaderLabels(QStringList() << "Елемент");
}


void MainWindow::on_saveButton_clicked()
{
    QFile out_file("C:\\ReposQt\\SearchInMassive\\search result.txt");
    if (out_file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&out_file);
        out << "Елемент: (" + ui->searchEdit->text() + ")";
        if(ui->indexEdit->text() == "Елемент відсутній"){
              out << " відсутній у масиві:\n";
        }
        else{
              out << " розташований за індексом: (" + ui->indexEdit->text() + ") у масиві:\n";
        }
        for (int i=0;i<algoritm->getSize()-1;i++){
            out<<algoritm->getElement(i) << ",  ";
        }
        out<<algoritm->getElement(algoritm->getSize()-1) << ";\n";
        out_file.close();
        ui->statusbar->showMessage("Збережено.");
    }
    else {

        qWarning("Could not open file");
    }
}

