#include "classtabtwo.h"
#include "ui_classtabtwo.h"



ClassTabTwo::ClassTabTwo(QWidget *parent) : QWidget(parent), ui(new Ui::ClassTabTwo)
{
    ui->setupUi(this);
    initUI();
}

ClassTabTwo::~ClassTabTwo()
{
    delete ui;
}

void ClassTabTwo::initUI()
{
    //左边活跃营业部的列表
    labelYinYeBuHuoYue = new QLabel(this);
    labelYinYeBuHuoYue->setStyleSheet("background-color:#fff;");
    //labelYinYeBuHuoYue->setGeometry(labelYinYeBuHuoYue->geometry().x(),labelYinYeBuHuoYue->geometry().y(),
    //                                Data::GetInstance().destopWidth/2-100,this->height()-80);
    connect(labelYinYeBuHuoYue,SIGNAL(linkActivated(QString)),this,SLOT(openYinYeBuURL(QString)));


    //动态计算界面尺寸布局
    int destopWidth = Data::GetInstance().destopWidth;
    int destopHeight = Data::GetInstance().destopHeight;

    ui->scrollArea->setWidget(labelYinYeBuHuoYue);
    ui->scrollArea->setFixedSize( destopWidth*1/2-80  , this->height()-10  );

    int y = ui->tableWidget_3->y();
    ui->tableWidget_3->setGeometry(destopWidth*1/2-50 , y, destopWidth*1/2,this->height()-20 );
    //右边营业部操作历史 表格
    ui->tableWidget_3->setColumnCount(8);
    QStringList horizontalHeaderList;
    horizontalHeaderList<<" 上榜日期 "<<" 股票简称 "<<" 上榜原因 "<<" 涨跌幅 "<<" 成交性质 "<<" 成交量/手 "<<" 成交额/万 "<<" 成交额占比 ";
    ui->tableWidget_3->setHorizontalHeaderLabels(horizontalHeaderList);
    ui->tableWidget_3->verticalHeader()->hide(); //隐藏垂直表头
    ui->tableWidget_3->resizeColumnsToContents(); //紧凑列宽
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows); //选择一整行

    //ui->tableWidget_2->resizeColumnsToContents(); //紧凑列宽
    //ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows); //选择一整行


    //先下载好当日活跃营业部
    startDownloadYinYeBuDay();

}


//下载营业部操作历史数据
void ClassTabTwo::startDownloadYinYeBuHistory(QString urlString)
{
    //1. urlString的格式
    //(urlString) "http://data.10jqka.com.cn/market/longhu/y_HTZQGFYXGSSHSCNLYYB/"
    //传进来的可能是上面两种  存入数据库的为urlString

    //2. urlHistory的格式
    //"http://data.10jqka.com.cn/interface/market/yybzjsl/GTJAZQGFYXGSSHFSLZQYYB/ + 页数"

    //3. urlPage的格式
    //"http://data.10jqka.com.cn/market/longhu/y_yybzjsl/GTJAZQGFYXGSSHFSLZQYYB/"


    qDebug()<<"urlString(传进来):"<<urlString;
    int p = urlString.indexOf("#refC");  if( p != -1 ) urlString = urlString.mid(0 , p  );
    qDebug()<<"urlString(最终):"<<urlString;


    //urlPage后面不用加数据,tempUrlHistory是不带页数的urlHistory，用来存入数据库
    QString urlHistory,urlPage,tempUrlHistory;


    if( urlString.indexOf("longhu/y_")!= -1 )
       urlHistory = urlString.replace("longhu/y_","yybzjsl/");
    else
       urlHistory = urlString;



    urlHistory.insert( urlHistory.indexOf(".cn/")+4,"interface/" );
    tempUrlHistory = urlHistory;
    //加入页数
    urlHistory += currentPage;



    //营业部详细页面的URL
    int pos = urlString.indexOf("/longhu/y_");
    urlPage = urlString.replace(pos,10,"/yybzjsl/");



    //处理好这两个url后，同步到单例类中,用户可能会假如自选
    qDebug()<<"urlHistory:" << urlHistory ;
    qDebug()<<"urlPage:" << urlPage ;
    Data::GetInstance().tabOne->currentYinYeBuUrlHistory = tempUrlHistory;
    Data::GetInstance().tabOne->currentYinYeBuUrlPage = urlPage;

    QUrl url1;
    url1.setUrl(urlHistory);
    reply1 = manager.get( QNetworkRequest( url1 ) );
    connect(reply1, SIGNAL(finished()),this, SLOT(downloadYinYeBuHistoryFinished()));
    Data::GetInstance().eventLoop.exec();


    //如果currentPage为1，说明是第一次加载此营业部，所以 标题，总页数之类的需要 从网络下载获取
    //如果
    if( currentPage != "1") return;

    QUrl url4;
    url4.setUrl(urlPage);
    reply4 = manager.get( QNetworkRequest( url4 ) );
    connect(reply4, SIGNAL(finished()),this, SLOT(downloadYinYeBuPageFinished()));
    Data::GetInstance().eventLoop.exec();
    outQString("开始下载营业部历史股票数据 ClassTabTwo::startDownloadYinYeBuHistory():\r\n" + urlString);
}

void ClassTabTwo::startDownloadYinYeBuDay()
{
    ui->pushButton_1->setChecked(true);
    ui->pushButton_2->setChecked(false);


    QUrl url("http://data.10jqka.com.cn/interface/market/longhuyyb/buy/desc/1");
    reply2 = manager.get( QNetworkRequest(url) );
    connect(reply2, SIGNAL(finished()),this, SLOT(downloadYinYeBuDayFinished()));
    if( !Data::GetInstance().eventLoop.isRunning() ) Data::GetInstance().eventLoop.exec();
    outQString("开始下载当日活跃营业部数据 ClassTabTwo::startDownloadYinYeBuDay()：\r\n" + url.url());


}

void ClassTabTwo::startDownloadYinYeBuMonth()
{
    ui->pushButton_1->setChecked(false);
    ui->pushButton_2->setChecked(true);


    QUrl url("http://data.10jqka.com.cn/interface/market/longhuyyb/buy/desc/1/20");
    reply3 = manager.get( QNetworkRequest(url) );
    connect(reply3, SIGNAL(finished()),this, SLOT(downloadYinYeBuMonthFinished()) );
    if( !Data::GetInstance().eventLoop.isRunning() ) Data::GetInstance().eventLoop.exec();
    outQString("开始下载当月活跃营业部数据 ClassTabTwo::startDownloadYinYeBuMonth()：\r\n" + url.url());


}

//打开某个营业部，开始下载该营业部的所有相关数据
//由用户点击  tab2左边的链接  或 tab1里右边的链接 触发
void ClassTabTwo::openYinYeBuURL(QString url)
{
    outQString("ClassTabTwo::openYinYeBuURL()  打开营业部连接 " + url);
    currentPage = "1";
    currentUrl = url;
    startDownloadYinYeBuHistory(url);

}

//完成下载营业部操作历史数据
void ClassTabTwo::downloadYinYeBuHistoryFinished()
{

    //停止堵塞
    Data::GetInstance().eventLoop.quit();
    //获取网页源码
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QString all = codec->toUnicode(reply1->readAll());

    //封装成json解析文档和json对象
    QJsonParseError json_error;
    QByteArray allByte = all.toUtf8();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(allByte,&json_error);
    QJsonObject jsonObj = jsonDoc.object();
    //拿到_data属性，循环获取
    QString htmlQString = jsonObj.take("data").toString();
    std::string htmlString = htmlQString.toStdString();

    MyParse *parser = new MyParse;
    parser->parseHtml( htmlString.c_str() );
    //获取<tr>节点列表
    QList<GumboNode*> trNodeList = parser->getNodeListByTag(GUMBO_TAG_TR);
    QList<GumboNode*> tdNodeList;
    GumboNode* textNode,*aNode;
    //输出源码
    //outQString(htmlQString);
    //处理每一个<tr>
    //qDebug()<<"trNodeList size:"<<trNodeList.size();
    int row = 0, col = 0;
    ui->tableWidget_3->setRowCount( trNodeList.size()-2 );
    for(int i=2; i<trNodeList.size(); i++) {

        //<<"上榜日期"<<"股票简称"<<"上榜原因"<<"涨跌幅"<<"成交性质"<<"成交量"<<"成交额"<<"成交额占比";
        tdNodeList = parser->getNodeListByTag( trNodeList.at(i), GUMBO_TAG_TD );
        //qDebug()<<"tdNodeList size:"<<tdNodeList.size();
        //第1个td:  上榜日期
        textNode = parser->getChildAt( tdNodeList.at(0) , 0 );
        ui->tableWidget_3->setItem( row , 0 , new QTableWidgetItem( StringToQString(string(textNode->v.text.text)) )  );
        //outString( string(textNode->v.text.text) );
        //第2个td:  股票简称
        aNode = parser->getNodeByTag( tdNodeList.at(1) , GUMBO_TAG_A );
        textNode = parser->getChildAt( aNode, 0  );
        ui->tableWidget_3->setItem( row , 1 , new QTableWidgetItem( StringToQString(string(textNode->v.text.text)) )  );
        ui->tableWidget_3->item( row , 1 )->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //outString( string(textNode->v.text.text) );
        //第3个td: 上榜原因
        textNode = parser->getChildAt( tdNodeList.at(2) , 0 );
        ui->tableWidget_3->setItem( row , 2 , new QTableWidgetItem( StringToQString(string(textNode->v.text.text)) )  );
        //outString( string(textNode->v.text.text) );
        //第4个td: 涨跌幅
        textNode = parser->getChildAt( tdNodeList.at(3) , 0 );
        ui->tableWidget_3->setItem( row , 3 , new QTableWidgetItem( StringToQString(string(textNode->v.text.text)) )  );
        //outString( string(textNode->v.text.text) );
        //第5个td: 成交性质
        textNode = parser->getChildAt( tdNodeList.at(4) , 0 );
        QString s = StringToQString(string(textNode->v.text.text));
        ui->tableWidget_3->setItem( row , 4 , new QTableWidgetItem( s )  );
        ui->tableWidget_3->item( row , 4 )->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        if( s == "买入" )   ui->tableWidget_3->item( row , 4 )->setTextColor(QColor(255,0,0));
        else ui->tableWidget_3->item( row , 4 )->setTextColor(QColor(0,255,0));

        //outString( string(textNode->v.text.text) );
        //第6个td: 成交量
        textNode = parser->getChildAt( tdNodeList.at(5) , 0 );
        ui->tableWidget_3->setItem( row , 5 , new QTableWidgetItem( StringToQString(string(textNode->v.text.text)) )  );
        ui->tableWidget_3->item( row , 5 )->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        //outString( string(textNode->v.text.text) );
        //第7个td: 成交额
        textNode = parser->getChildAt( tdNodeList.at(6) , 0 );
        ui->tableWidget_3->setItem( row , 6 , new QTableWidgetItem( StringToQString(string(textNode->v.text.text)) )  );
        ui->tableWidget_3->item( row , 6 )->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        //outString( string(textNode->v.text.text) );
        //第8个td: 成交额占比
        textNode = parser->getChildAt( tdNodeList.at(7) , 0 );
        ui->tableWidget_3->setItem( row , 7 , new QTableWidgetItem( StringToQString(string(textNode->v.text.text)) )  );
        ui->tableWidget_3->item( row , 7 )->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        //outString( string(textNode->v.text.text) );

        row++;
    }

    //int tableWidget_3_width = 0;
    //ui->tableWidget_3->setColumnWidth(2,120);
    //for(int i=0; i<ui->tableWidget_3->columnCount();i++ ) {
    //    tableWidget_3_width += ui->tableWidget_3->columnWidth(i);
    //}
    //tableWidget_3_width += 20;
    //int tableWidget_3_height = this->height()-50;
    //int tableWidget_3_x = this->width()- tableWidget_3_width - 10;
    //int tableWidget_3_y = ui->tableWidget_3->geometry().y();

    //ui->tableWidget_3->setGeometry( tableWidget_3_x, tableWidget_3_y, tableWidget_3_width, tableWidget_3_height );
    ui->tableWidget_3->setCurrentCell(0,1);



}

void ClassTabTwo::downloadYinYeBuDayFinished()
{
    outQString("下载完毕，开始解析和输出 ClassTabTwo::downloadYinYeBuDayFinished()");
    //停止堵塞
    Data::GetInstance().eventLoop.quit();
    //获取网页源码
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QString all = codec->toUnicode(reply2->readAll());


    //封装成json解析文档和json对象
    QJsonParseError json_error;
    QByteArray allByte = all.toUtf8();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(allByte,&json_error);
    QJsonObject jsonObj = jsonDoc.object();

    //拿到data属性，循环获取
    QString htmlQString = jsonObj.take("data").toString();

    //把一些标签隐藏掉
    int len = htmlQString.indexOf("/thead>");
    htmlQString.remove(0, len+7 );

    int j;
    j=0;
    while( (j=htmlQString.indexOf("明细", j)) != -1 ) {
        htmlQString.replace(j,2,"");
    }
    j=0;
    while( (j=htmlQString.indexOf("cur\">", j)) != -1 ) {
        htmlQString.replace(j,5,"kk\">买入");
    }
    j=0;
    while( (j=htmlQString.indexOf("c_fall \">", j)) != -1 ) {
        htmlQString.replace(j,9,"kkk\">(万元)<!--");
    }
    j=0;
    while( (j=htmlQString.indexOf("</tr>", j)) != -1 ) {
        htmlQString.replace(j,5,"--></tr>");
        j+=5;
    }



    /*
    j=0;
    while( (j=htmlString.indexOf("<img ", j)) != -1 ) {
        //qDebug()<<"find span"<<j;
        htmlString.replace(j,101,"<k style=\"display:none;\"> ");
    }
    */


    labelYinYeBuHuoYue->setText(htmlQString);
    //ui->plainTextEdit->setPlainText(htmlQString);




}

void ClassTabTwo::downloadYinYeBuMonthFinished()
{
    //和downloadYinYeBuDayFinished没有太大区别 reply2变为reply3
    outQString("下载完毕，开始解析和输出 ClassTabTwo::downloadYinYeBuMonthFinished()");
    //停止堵塞
    Data::GetInstance().eventLoop.quit();
    //获取网页源码
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QString all = codec->toUnicode(reply3->readAll());


    //封装成json解析文档和json对象
    QJsonParseError json_error;
    QByteArray allByte = all.toUtf8();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(allByte,&json_error);
    QJsonObject jsonObj = jsonDoc.object();

    //拿到data属性，循环获取
    QString htmlQString = jsonObj.take("data").toString();

    //把一些标签隐藏掉
    int len = htmlQString.indexOf("/thead>");
    htmlQString.remove(0, len+7 );

    int j;
    j=0;
    while( (j=htmlQString.indexOf("明细", j)) != -1 ) {
        htmlQString.replace(j,2,"");
    }
    j=0;
    while( (j=htmlQString.indexOf("cur\">", j)) != -1 ) {
        htmlQString.replace(j,5,"kk\">买入");
    }
    j=0;
    while( (j=htmlQString.indexOf("c_fall \">", j)) != -1 ) {
        htmlQString.replace(j,9,"kkk\">(万元)<!--");
    }
    j=0;
    while( (j=htmlQString.indexOf("</tr>", j)) != -1 ) {
        htmlQString.replace(j,5,"--></tr>");
        j+=5;
    }

    /*
    j=0;
    while( (j=htmlString.indexOf("<img ", j)) != -1 ) {
        //qDebug()<<"find span"<<j;
        htmlString.replace(j,101,"<k style=\"display:none;\"> ");
    }
    */


    labelYinYeBuHuoYue->setText(htmlQString);
    //ui->plainTextEdit->setPlainText(htmlQString);

}

//这个函数用来拿到  营业部名字 (解析html  而不是解析接口json)
void ClassTabTwo::downloadYinYeBuPageFinished()
{
    //停止堵塞
    Data::GetInstance().eventLoop.quit();
    //获取网页源码
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QString htmlQString = codec->toUnicode(reply4->readAll());
    std::string htmlString = htmlQString.toStdString();
    std::wstring htmlWString = htmlQString.toStdWString();

    MyParse *parser = new MyParse;
    parser->parseHtml( htmlString.c_str() );
    //找到标题<title>便签，拿到标题里面的营业部名称
    QList<GumboNode*> titleNodeList = parser->getNodeListByTag(GUMBO_TAG_TITLE);

    GumboNode *titleNode,*textNode;
    //qDebug()<<"title size:"<<titleNodeList.size();
    titleNode = titleNodeList.at(0);
    textNode = parser->getChildAt(titleNode,0);
    //outQString( StringToQString( string( textNode->v.text.text ) ) );
    QString htmlTitle = StringToQString( string( textNode->v.text.text ) );
    int pos = htmlTitle.indexOf("_");

    Data::GetInstance().tabOne->currentYinYeBuNameString =  htmlTitle.mid(0,pos-4);
    ui->labelYinYeBuName->setText(  Data::GetInstance().tabOne->currentYinYeBuNameString );
    ui->labelYinYeBuName->setGeometry( ui->labelYinYeBuName->geometry().x(),ui->labelYinYeBuName->geometry().y(), this->width()-ui->labelYinYeBuName->geometry().x(),ui->labelYinYeBuName->geometry().height()  );





    //找到<span class="page_info">标签，里面的即为总页数
    QList<GumboNode*> spanNodeList = parser->getNodeListByTag(GUMBO_TAG_SPAN);
    GumboNode *spanNode; GumboAttribute* className;
    QString pageSizeQStr = "1";
    for(int i=0; i<spanNodeList.size(); i++ ) {
        spanNode = spanNodeList.at(i);
        if( className = gumbo_get_attribute( &spanNode->v.element.attributes,"class" )  ) {
            //qDebug()<<"span className: "<<  className->value;
            if( StringToQString( className->value ) == "page_info" ) {
                textNode = parser->getChildAt(spanNode,0);
                //qDebug()<<StringToQString( string( textNode->v.text.text ) );
                pageSizeQStr = StringToQString( string( textNode->v.text.text ) );
                break;
            }
        }
    }
    //qDebug()<<"indexof /"<<pageSizeQStr.indexOf('/');
    int po = pageSizeQStr.indexOf('/');
    //qDebug()<<"indexof /"<<po;
    //qDebug()<<"final pagesize:"<<pageSizeQStr.mid(po+1);
    pageSizeQStr = pageSizeQStr.mid(po+1);

    int pageSize = pageSizeQStr.toInt();
    qDebug()<<pageSize;
    ui->comboBox->clear();
    for(int i=1; i<=pageSize; i++) {
        ui->comboBox->insertItem(i-1, QString::number(i) );
    }

}




//加入追踪按钮
void ClassTabTwo::on_pushButton_3_clicked()
{

    //把营业部 加入追踪数据库
    if(    Data::GetInstance().tabOne->currentYinYeBuNameString.length()>1
         &&Data::GetInstance().tabOne->currentYinYeBuUrlHistory.length() >1
         &&Data::GetInstance().tabOne->currentYinYeBuUrlPage.length() >1
       )
    {
        BeanYinYeBu yinyebu;
        yinyebu.yinyebuName = Data::GetInstance().tabOne->currentYinYeBuNameString;
        yinyebu.yinyebuUrlPage = Data::GetInstance().tabOne->currentYinYeBuUrlPage;
        yinyebu.yinyebuUrlInterface = Data::GetInstance().tabOne->currentYinYeBuUrlHistory;
        Data::GetInstance().service->AddYinYeBu( yinyebu );

    }

}

void ClassTabTwo::on_pushButton_1_clicked()
{
    startDownloadYinYeBuDay();
}


void ClassTabTwo::on_pushButton_2_clicked()
{
    startDownloadYinYeBuMonth();
}


void ClassTabTwo::on_comboBox_activated(const QString &arg1)
{
    currentPage = arg1;
    qDebug()<<"on_comboBox_activated:"<<arg1;
    startDownloadYinYeBuHistory(currentUrl);

}
