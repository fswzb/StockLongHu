#include "classtabfive.h"
#include "ui_classtabfive.h"

ClassTabFive::ClassTabFive(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassTabFive)
{
    ui->setupUi(this);

    qDebug()<<"路径"<<QFileInfo("testHistoryStock.html").absoluteFilePath();

    //webview开启falsh和javascript支持
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled,true);
    ui->webView->load("file:///" +  QFileInfo("testHistoryStock.html").absoluteFilePath() );
}

ClassTabFive::~ClassTabFive()
{
    delete ui;
}
