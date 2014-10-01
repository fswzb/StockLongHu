#ifndef CLASSTABSIX_H
#define CLASSTABSIX_H

#include <tool.h>
#include <QWidget>
#include <QList>
#include <QWebView>
#include <QString>
#include <QPushButton>

namespace Ui {
class ClassTabSix;
}

class ClassTabSix : public QWidget
{
    Q_OBJECT
    
public:
    explicit ClassTabSix(QWidget *parent = 0);
    ~ClassTabSix();

    QList<QPushButton*> buttonGroup; //行情按钮组
    QString currentStockCode; //当前股票代码
    QString currentStockUrl; //当前股票行情网址
    void checkButton(int index); //按钮切换网页
    int currentIndex = 6; //默认激活第七个按钮

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();

private:
    Ui::ClassTabSix *ui;
};

#endif // CLASSTABSIX_H
