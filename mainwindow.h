#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QWidget>
#include <QTextCodec>
#include <QMessageBox>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <beanandservice.h>
#include "classtabone.h"
#include "classtabtwo.h"
#include "classtabthree.h"
#include <tool.h>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    //初始化界面
    void initWindowUI();
    //初始化数据库
    void initDataBase();


};

#endif // MAINWINDOW_H
