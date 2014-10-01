#ifndef WEBVIEWWINDOW_H
#define WEBVIEWWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QUrl>
#include <QList>
#include <tool.h>

#include <QWebView>
#include <QPushButton>



namespace Ui {
class WebViewWindow;
}

class WebViewWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WebViewWindow(QWidget *parent = 0);
    ~WebViewWindow();
    QWebView * webView;
    QList<QPushButton*> buttonGroup;
    int currentIndex = 4;  //当前激活按钮对应的index
    QUrl currentUrl; //当前网页url
    QString currentStockCode; //当前股票代码
    QString currentStockName; //当前股票名称
    void initWindowUI(QString stockCode,QString stockName);  //设置窗口显示等
    void checkButton(int index); //按钮切换网页

/*
index
0 云财经
1 东方财富
2 搜狐财经
3 网易财经
4 证券之星
5 新浪行情


*/




    
private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::WebViewWindow *ui;
};

#endif // WEBVIEWWINDOW_H
