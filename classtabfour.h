#ifndef CLASSTABFOUR_H
#define CLASSTABFOUR_H

#include <QWidget>
#include <tool.h>
#include <QList>
#include <QLabel>
#include <QStringList>
#include <QPushButton>
#include <QHash>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QProgressDialog>

#include <beanandservice.h>


class BeanYinYeBu;
class ResultStock;

namespace Ui {
class ClassTabFour;
}

bool sortCmp(const ResultStock* stock1, const ResultStock* stock2);

class ClassTabFour : public QWidget
{
    Q_OBJECT
    
public:
    explicit ClassTabFour(QWidget *parent = 0);
    ~ClassTabFour();

    QNetworkReply *reply1; //用来下载营业部最近n天的股票数据
    QNetworkReply *reply2; //用来接收 上传结果后 服务器返回结果
    QNetworkAccessManager manager;
    QProgressDialog uploadProgressDialog;
    int uploadStockCount = 0; //上传保存的股票数

    QLabel *labelResult;
    QList<BeanYinYeBu> listMyYinYeBu;
    BeanYinYeBu* currentYinyebu; //当前网络下载的营业部



    QList<ResultStock*> listResultStock;  //营业部股票筛选结果的list
    void insertResultStock( ResultStock* pResultStock );

    void startSortListResultStock();

    int nDays = 0;
    void initUI();       //初始化界面
    void updateTableWidget();  //更新表格数据
    void addResultText(QString text);
    void startAnalysis();
    void downloadYinyebuStockNdays(BeanYinYeBu yinyebu,int days);

private slots:
    void checkHistory(QString url);
    void cancelZhuiZong(QString url);
    //上传选股结果 ，完成
    void uploadStockFinished();
    //点击分析结果的股票链接 实现跳转
    void activeStockURL(const QString& link);
    //按钮:开始分析
    void on_pushButton_2_clicked();
    void downloadYinyebuStockDataFinished();
    //按钮： 清空结果
    void on_pushButton_3_clicked();
    //按钮: 保存结果
    void on_pushButton_clicked();

private:
    Ui::ClassTabFour *ui;
};


class StockData {

public:
    QString stockName;
    QString stockLink; //股票链接，形如 http://data.10jqka.com.cn/market/longhu/cjmx/603609/
    QString stockYinyebu; //营业部名
    QString buyDate; //营业部买入该股票的日期
    QString buyVol; //营业部参与该股的成交量
    QString buyMoney; //成交额
};



#endif // CLASSTABFOUR_H



