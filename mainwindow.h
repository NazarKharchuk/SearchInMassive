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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    SearchAlgoritms * algoritm;
    Ui::MainWindow *ui;
private slots:
    void SizeEdit_changet();
    void SearchEdit_changet();
    void CreateButton_clicked();
    void SearchButton_clicked();
    void on_showMassButton_clicked();
    void on_saveButton_clicked();
};
#endif // MAINWINDOW_H
