#include "classtabsix.h"
#include "ui_classtabsix.h"

ClassTabSix::ClassTabSix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassTabSix)
{
    ui->setupUi(this);

    //行情按钮组
    buttonGroup.append(ui->pushButton_1);
    buttonGroup.append(ui->pushButton_2);
    buttonGroup.append(ui->pushButton_3);
    buttonGroup.append(ui->pushButton_4);
    buttonGroup.append(ui->pushButton_5);
    buttonGroup.append(ui->pushButton_6);
    buttonGroup.append(ui->pushButton_7);


    //获取屏幕分辨率
    int destopWidth = Data::GetInstance().destopWidth ;
    int destopHeight = Data::GetInstance().destopHeight ;
    ui->webView->setGeometry(120,20,destopWidth-150,destopHeight-130 );

    //webview开启falsh和javascript支持
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled,true);


}

ClassTabSix::~ClassTabSix()
{
    delete ui;
}

void ClassTabSix::checkButton(int index)
{
    buttonGroup.at(currentIndex)->setChecked(false);
    buttonGroup.at(index)->setChecked(true);
    currentIndex = index;

    QString url;
    //qDebug()<<url;

    switch (index) {
    case 0:
        url = "http://yunvs.com/"+currentStockCode;
        break;
    case 1:
        if( currentStockCode.at(0) == '6'  )
            url = "http://quote.eastmoney.com/sh"+currentStockCode+".html";
        else
            url = "http://quote.eastmoney.com/sz"+currentStockCode+".html";
        break;
    case 2:
        url="http://q.stock.sohu.com/cn/"+currentStockCode+"/index.shtml";
        break;
    case 3:
        if( currentStockCode.at(0) == '6')
            url = "http://quotes.money.163.com/0"+currentStockCode+".html";
        else
            url = "http://quotes.money.163.com/1"+currentStockCode+".html";
        break;
    case 4:
        url = "http://stock.quote.stockstar.com/"+currentStockCode+".shtml";
        break;
    case 5:
        if( currentStockCode.at(0) == '6' )
            url = "http://finance.sina.com.cn/realstock/company/sh"+currentStockCode+"/nc.shtml";
        else
            url = "http://finance.sina.com.cn/realstock/company/sz"+currentStockCode+"/nc.shtml";
        break;
    case 6:
        url = "http://data.10jqka.com.cn/market/longhu/cjmx/"+currentStockCode;
        break;
    default:
        break;
    }

    ui->webView->load(url);

}

void ClassTabSix::on_pushButton_1_clicked()
{
    checkButton(0);
}

void ClassTabSix::on_pushButton_2_clicked()
{
    checkButton(1);
}

void ClassTabSix::on_pushButton_3_clicked()
{
    checkButton(2);
}

void ClassTabSix::on_pushButton_4_clicked()
{
    checkButton(3);
}

void ClassTabSix::on_pushButton_5_clicked()
{
    checkButton(4);
}

void ClassTabSix::on_pushButton_6_clicked()
{
    checkButton(5);
}

void ClassTabSix::on_pushButton_7_clicked()
{
    checkButton(6);
}
