#ifndef CLASSTABTWO_H
#define CLASSTABTWO_H

#include <QTextCodec>
#include <beanandservice.h>
#include <QWidget>
#include <QLabel>
#include <QStringList>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <tool.h>
#include <ui_classtabtwo.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <gumbo/gumbo.h>
using namespace std;
class Data;


namespace Ui {
class ClassTabTwo;
}

class ClassTabTwo : public QWidget
{
    Q_OBJECT
    
public:
    explicit ClassTabTwo(QWidget *parent = 0);
    ~ClassTabTwo();
    void initUI();
    QLabel *labelYinYeBuHuoYue;
    QNetworkReply *reply1, *reply2, *reply3,*reply4;
    QNetworkAccessManager manager;


    QString currentUrl;
    QString currentPage = "1";
    //下载营业部操作历史(json)  例如:http://data.10jqka.com.cn/interface/market/yybzjsl/HTZQGFYXGSSZYTLRCSWZXZQYY/6
    void startDownloadYinYeBuHistory(QString urlString);
    //下载营业部的详细信息页面(html) 例如 http://data.10jqka.com.cn/market/yybzjsl/HTZQGFYXGSSZYTLRCSWZXZQYY#refCountId=data_51872c8f_707
    void startDownloadYinYeBuPage(QString urlString);
    //当日活跃营业部
    void startDownloadYinYeBuDay();
    //当月活跃营业部
    void startDownloadYinYeBuMonth();


private slots:
    void openYinYeBuURL(QString url);
    void downloadYinYeBuHistoryFinished();
    void downloadYinYeBuDayFinished();
    void downloadYinYeBuMonthFinished();
    void downloadYinYeBuPageFinished();

    void on_pushButton_1_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();


    void on_comboBox_activated(const QString &arg1);

private:
    Ui::ClassTabTwo *ui;
};

#endif // CLASSTABTWO_H



