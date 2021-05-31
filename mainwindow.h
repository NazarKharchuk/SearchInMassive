#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QRegularExpressionValidator>
#include "searchalgoritms.h"
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/***************************************************
*   Клас, що відповідає за графічний інтерфейс     *
***************************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);      //   Конструктор класу MainWindow
    ~MainWindow();                              //   Деструктор класу MainWindow

private:
    SearchAlgoritms * algoritm;
    Ui::MainWindow *ui;
private slots:
    void SizeEdit_changet();                    //   Слот, що реагує на зміну значення в полі для розміру
    void SearchEdit_changet();                  //   Слот, що реагує на зміну значення в полі для елемента, який шукатимемо
    void CreateButton_clicked();                //   Слот, що реагує на нажаття кнопки створення масиву
    void SearchButton_clicked();                //   Слот, що реагує на нажаття кнопки пошуку елемента
    void on_showMassButton_clicked();           //   Слот, що реагує на нажаття кнопки відображення масиву
    void on_saveButton_clicked();               //   Слот, що реагує на нажаття кнопки збереження результатів
};
#endif // MAINWINDOW_H
