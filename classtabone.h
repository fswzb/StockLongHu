#ifndef CLASSTABONE_H
#define CLASSTABONE_H

#include <QLabel>
#include <QTextCodec>
#include <QWidget>
#include <QDate>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <tool.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <gumbo/gumbo.h>
#include <QWebView>
#include <classtablemodelone.h>
#include <ui_classtabone.h>
using namespace std;

class ClassTableModelOne;
class QSortFilterProxyModel;

namespace Ui {
class ClassTabOne;
}

class ClassTabOne : public QWidget
{
    Q_OBJECT
    
public:
    Ui::ClassTabOne *ui;
    explicit ClassTabOne(QWidget *parent = 0);
    ~ClassTabOne();
    QString newDateString = ""; //最新龙虎榜日期
    QString currentLongHuBangDateString = ""; //当前龙虎榜日期
    QString currentYinYeBuDateString = ""; //当前股票的上榜日期
    QString currentYinYeBuNameString = ""; //当前营业部的名称
    QString currentYinYeBuUrlPage = ""; //当前营业部的详细页的url
    QString currentYinYeBuUrlHistory = ""; //当前营业部的历史股票的url

    QString currentStockCode;  //当前股票代码
    QString currentStockName; //当前股票名称
    QModelIndex wantIndex; //当前被点击查看的龙虎榜股票
    QLabel* labelYinYeBu;
    QNetworkReply *reply1;
    QNetworkReply *reply2;
    QNetworkReply *reply3;
    QNetworkReply *replyGetNewDate; //获得龙虎榜最新更新的日期
    QNetworkAccessManager manager;



public:
    void initTableView();//初始化
    ClassTableModelOne *tableModelOne;
    QSortFilterProxyModel *proxyModel;

    
private:
    int sumLeftLayoutWidth,sumRightLayoutWidth; //左边区域宽度，右边区域宽度
    void StartDownloadLongHuBang(); //开始下载龙虎榜数据
    void handleData(std::string htmlString);
    void StartDownloadYinYeBu(); //开始下载股票对应的营业部数据

private slots:
    //下载龙虎榜数据完毕，封装到Tool.listLongHuBang
    void DownloadLongHuFinished();
    //下载营业部数据完毕，封装到
    void DownloadYinYeBuFinished();
    //下载龙虎榜历史上榜日期
    void DownloadLongHuDateListFinished();
    //下载龙虎榜最新更新日期
    void DownloadNewDateFinished();

    void on_tableView1_clicked(const QModelIndex &index);
    void openYinYeBuURL(QString url); //打开营业部url
    void on_comboBox_activated(const QString &arg1);
    void on_pushButton_2_clicked();
    void on_tableView1_doubleClicked(const QModelIndex &index);
    void on_dateEdit_dateChanged(const QDate &date);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);
};



#endif // CLASSTABONE_H




