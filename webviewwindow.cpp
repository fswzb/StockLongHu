#include "webviewwindow.h"
#include "ui_webviewwindow.h"

WebViewWindow::WebViewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WebViewWindow)
{
    ui->setupUi(this);
    //管理按钮组
    buttonGroup.append(ui->pushButton_1);
    buttonGroup.append(ui->pushButton_2);
    buttonGroup.append(ui->pushButton_3);
    buttonGroup.append(ui->pushButton_4);
    buttonGroup.append(ui->pushButton_5);
    buttonGroup.append(ui->pushButton_6);
}

WebViewWindow::~WebViewWindow()
{
    delete ui;
}

void WebViewWindow::initWindowUI(QString stockCode,QString stockName)
{
    //默认最大化
    setWindowState(Qt::WindowMaximized);
    setCentralWidget(ui->centralwidget);
    //获取屏幕分辨率
    int destopWidth =  Data::GetInstance().destopWidth ;
    int destopHeight = Data::GetInstance().destopHeight ;
    //初始化webview
    webView = new QWebView(this);
    webView->setGeometry(110,20,destopWidth-150,destopHeight-80 );
    webView->show();
    //设置当前股票
    currentStockCode = stockCode;
    currentStockName = stockName;

    checkButton(currentIndex);

}

void WebViewWindow::checkButton(int index)
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
        if( currentStockCode.at(0) == '6' || currentStockCode.at(0)== '0' )
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
        if( currentStockCode.at(0) == '6' || currentStockCode.at(0)== '0' )
            url = "http://finance.sina.com.cn/realstock/company/sh"+currentStockCode+"/nc.shtml";
        else
            url = "http://finance.sina.com.cn/realstock/company/sz"+currentStockCode+"/nc.shtml";
        break;
    default:
        break;
    }


    qDebug()<<url;
    currentUrl.setUrl( url );
    webView->load( currentUrl );

}



void WebViewWindow::on_pushButton_1_clicked()
{

    checkButton(0);
}



void WebViewWindow::on_pushButton_2_clicked()
{
    checkButton(1);
}


void WebViewWindow::on_pushButton_3_clicked()
{
    checkButton(2);
}


void WebViewWindow::on_pushButton_4_clicked()
{
    checkButton(3);
}

void WebViewWindow::on_pushButton_5_clicked()
{
    checkButton(4);
}

void WebViewWindow::on_pushButton_6_clicked()
{
    checkButton(5);
}
