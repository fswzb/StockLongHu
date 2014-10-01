#include "classtabfour.h"
#include "ui_classtabfour.h"

ClassTabFour::ClassTabFour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassTabFour)
{
    ui->setupUi(this);
    initUI();
    updateTableWidget();
}

ClassTabFour::~ClassTabFour()
{
    delete ui;
}

//把一只筛选出来的股票加入到listResultStock
void ClassTabFour::insertResultStock(ResultStock *pResultStock)
{

    bool flagFind = false; //默认list里不存在该股票
    for(int i=0; i<listResultStock.size(); i++) {
        if(pResultStock->stockCode == listResultStock.at(i)->stockCode ) {
            flagFind = true;
            listResultStock.at(i)->yinyebuName.append(pResultStock->yinyebuName);
            listResultStock.at(i)->yinyebuURL.append(pResultStock->yinyebuURL);
            listResultStock.at(i)->count++;
            break;
        }
    }
    if(!flagFind) {
        pResultStock->count = 1;
        listResultStock.append(pResultStock);
    }



}



void ClassTabFour::initUI()
{
    int destopWidth = Data::GetInstance().destopWidth;
    int destopHeight = Data::GetInstance().destopHeight;
    int tableWidget1_x = ui->tableWidget->geometry().x();
    int tableWidget1_y = ui->tableWidget->geometry().y();
    int tableWidget1_width = destopWidth*4/10;
    int tableWidget1_height = destopHeight-130;



    QStringList horizontalHeaderList;
    horizontalHeaderList<<" 序号 "<<" 营业部名称 "<<"历史数据"<<"  操作  ";
    ui->tableWidget->setColumnCount(4);
    //ui->tableWidget->setGeometry( tableWidget1_x , tableWidget1_y  , tableWidget1_width , tableWidget1_height    );
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeaderList);
    ui->tableWidget->verticalHeader()->hide(); //隐藏垂直表头
    ui->tableWidget->resizeColumnsToContents(); //紧凑列宽
    ui->tableWidget->setColumnWidth(1,tableWidget1_width-170);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);//填充最后一列
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //选择一整行


    ui->tableWidget->setFixedSize( QSize(tableWidget1_width,tableWidget1_height) );
    ui->scrollArea->setFixedSize( QSize(destopWidth-tableWidget1_width-80,tableWidget1_height - 60  ) );


    //分析类型
    ui->comboBox->insertItem(0,"<追踪>营业部中近1日最大买入个股");
    ui->comboBox->insertItem(1,"<追踪>营业部中近3日最大买入个股");



    //分析结果
    labelResult = new QLabel(this);
    labelResult->setStyleSheet("background-color:#fff;");
    //labelResult->setOpenExternalLinks(true);
    labelResult->setWordWrap(true);
    labelResult->setAlignment(Qt::AlignTop);
    ui->scrollArea->setWidget(labelResult);
    //信号:labelResult的点击股票链接
    connect(labelResult,SIGNAL(linkActivated(QString)),this,SLOT(activeStockURL(QString)));


}






void ClassTabFour::updateTableWidget()
{

    QLabel *labelHistory,*labelDeal;
    listMyYinYeBu = Data::GetInstance().service->getAllYinYeBu();
    qDebug()<<"ClassTabFour::updateTableWidget() size:"<<listMyYinYeBu.size();
    ui->tableWidget->setRowCount( listMyYinYeBu.size() );
    for(int row=0; row<listMyYinYeBu.size(); row++) {
        ui->tableWidget->setItem( row, 0, new QTableWidgetItem( QString::number(row+1)  )  );
        ui->tableWidget->setItem( row, 1, new QTableWidgetItem( listMyYinYeBu.at(row).yinyebuName  ) );

        labelHistory = new QLabel("<a href='" + listMyYinYeBu.at(row).yinyebuUrlPage + "'>查看行情</a>");
        labelHistory->setStyleSheet("margin:2;text-align:center;");
        connect(labelHistory,SIGNAL(linkActivated(QString)),this,SLOT(checkHistory(QString)) );
        ui->tableWidget->setCellWidget( row , 2, labelHistory );
        //qDebug()<<list.at(row).nameYinYeBu;

        labelDeal = new QLabel("<a href='" + listMyYinYeBu.at(row).yinyebuUrlPage + "'>取消追踪</a>");
        labelDeal->setStyleSheet("margin:2;text-align:center;");
        connect(labelDeal,SIGNAL(linkActivated(QString)),this,SLOT(cancelZhuiZong(QString)) );
        ui->tableWidget->setCellWidget( row , 3, labelDeal );
    }

}



void ClassTabFour::addResultText(QString text)
{

    labelResult->setText( labelResult->text() + text );
}

void ClassTabFour::startAnalysis()
{
    int currentAnalysisType = ui->comboBox->currentIndex();
    listResultStock.clear(); //清空统计数据

    if( currentAnalysisType==0 ) {

        BeanYinYeBu yinyebu;
        for(int i=0; i<listMyYinYeBu.size(); i++) {
            yinyebu = listMyYinYeBu.at(i);
            currentYinyebu = &yinyebu;
            downloadYinyebuStockNdays(yinyebu,1);
        }
        //对统计结果排序
        startSortListResultStock();
        //输出排序结果
        QString str = "";
        for(int i=0; i<listResultStock.size(); i++) {
            str.append(  listResultStock.at(i)->stockCode + "  <a href='http://data.10jqka.com.cn/market/longhu/cjmx/" + listResultStock.at(i)->stockCode + "'>" + listResultStock.at(i)->stockName + "</a>  买入机构数:"+ QString::number(listResultStock.at(i)->count) + "<br>" );
        }
        addResultText(str);

    }
    else if( currentAnalysisType==1 ) {
        BeanYinYeBu yinyebu;
        for(int i=0; i<listMyYinYeBu.size(); i++) {
            yinyebu = listMyYinYeBu.at(i);
            currentYinyebu = &yinyebu;
            downloadYinyebuStockNdays(yinyebu,3);
        }
        //对统计结果排序
        startSortListResultStock();
        //输出排序结果
        QString str = "";
        for(int i=0; i<listResultStock.size(); i++) {
            str.append(listResultStock.at(i)->stockCode + listResultStock.at(i)->stockName
                        + "买入机构数:"+ QString::number(listResultStock.at(i)->count ) + "<br>" );
        }
        addResultText(str);



    }
}



//下载一个营业部最近n天内所买入的个股
void ClassTabFour::downloadYinyebuStockNdays(BeanYinYeBu yinyebu, int days)
{

    nDays = days;
    //QString strURL = yinyebu.yinyebuUrlInterface + QString::number(days);
    QString strURL = yinyebu.yinyebuUrlInterface + "1";
    //qDebug()<<"当前下载营业部:近"<<days<<"天"<<strURL;
    QUrl url(strURL);
    reply1 = manager.get( QNetworkRequest(url) );
    connect(reply1, SIGNAL(finished()),this, SLOT(downloadYinyebuStockDataFinished()));
    if( !Data::GetInstance().eventLoop.isRunning() ) Data::GetInstance().eventLoop.exec();

}

void ClassTabFour::downloadYinyebuStockDataFinished()
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
    GumboNode* textNode,*trNode,*aNode;


    //单个营业部的分析结果
    QString resultStr = currentYinyebu->yinyebuName+":<br>";
    //数据
    QString sMaiMai,sDate,sName,sVol,sMoney,sReason;
    StockData* stockData;
    GumboAttribute* className;
    QStringList yinyebuStockNameList; //一个营业部所操作的股票列表，如果已存在则不再重复统计

    int daycount = 1;
    //该营业部最近一日的操作日期
    tdNodeList = parser->getNodeListByTag( trNodeList.at(2), GUMBO_TAG_TD );
    textNode = parser->getChildAt( tdNodeList.at(0) , 0 );
    QString sNewDate = StringToQString(string(textNode->v.text.text))  ;
    //
    ResultStock *pResultStock;


    for(int i=2; i<trNodeList.size(); i++) {

        stockData = new StockData;
        //第1个td:  上榜日期
        textNode = parser->getChildAt( tdNodeList.at(0) , 0 );
        sDate = StringToQString(string(textNode->v.text.text))  ;
        //if(sDate!= Data::GetInstance().tabOne->newDateString) continue;
        if( sDate != sNewDate ) {
            sNewDate = sDate;
            daycount++;
            if( daycount > nDays ) break;
        }
        stockData->buyDate  = sDate;

        //<<"上榜日期"<<"股票简称"<<"上榜原因"<<"涨跌幅"<<"成交性质"<<"成交量"<<"成交额"<<"成交额占比";
        tdNodeList = parser->getNodeListByTag( trNodeList.at(i), GUMBO_TAG_TD );
        //第5个td: 成交性质
        textNode = parser->getChildAt( tdNodeList.at(4) , 0 );
        sMaiMai = StringToQString(string(textNode->v.text.text));
        if(sMaiMai != "买入") continue;
        else {
            //第3个td: 上榜原因
            textNode = parser->getChildAt( tdNodeList.at(2) , 0 );
            sReason = StringToQString(string(textNode->v.text.text));
            //qDebug()<<"原因:"<<sReason.at(0);
            if(sReason.at(0).unicode() == 36830 ) continue; //上榜原因为"连续3天xxx"的不要

        }

        //第2个td:  股票简称
        aNode = parser->getNodeByTag( tdNodeList.at(1) , GUMBO_TAG_A );
        textNode = parser->getChildAt( aNode, 0  );
        sName = StringToQString(string(textNode->v.text.text));
        stockData->stockName = sName;

        if( yinyebuStockNameList.contains(sName) ) continue; //避免重复统计
        //解析a标签，获得股票链接
        if( className = gumbo_get_attribute( &aNode->v.element.attributes,"href" ) ) {
            stockData->stockLink = "http://data.10jqka.com.cn" + StringToQString( className->value );
        }

        //第4个td: 涨跌幅
        //textNode = parser->getChildAt( tdNodeList.at(3) , 0 );
        //addResultText(StringToQString(string(textNode->v.text.text)) )  ;

        //第6个td: 成交量
        textNode = parser->getChildAt( tdNodeList.at(5) , 0 );
        stockData->buyVol = StringToQString(string(textNode->v.text.text));
        sVol = stockData->buyVol + "(手) ";

        //第7个td: 成交额
        textNode = parser->getChildAt( tdNodeList.at(6) , 0 );
        stockData->buyMoney = StringToQString(string(textNode->v.text.text));
        sMoney = "约" + StringToQString(string(textNode->v.text.text)) + "(万)";

        //第8个td: 成交额占比
        //textNode = parser->getChildAt( tdNodeList.at(7) , 0 );

        pResultStock = new ResultStock;
        pResultStock->stockCode = stockData->stockLink.mid(stockData->stockLink.length()-7 ,6 );
        //qDebug()<<pResultStock->stockCode;
        pResultStock->stockName = sName;
        pResultStock->yinyebuURL.append( currentYinyebu->yinyebuUrlPage );
        pResultStock->yinyebuName.append( currentYinyebu->yinyebuName );
        pResultStock->count = 1;
        insertResultStock(pResultStock);
        resultStr += (  sDate + " " + sMaiMai + " <a href=\"" + stockData->stockLink + " \">" + sName + "</a> " + sVol + sMoney + "<br>"  );


        yinyebuStockNameList.append(sName);
    }


    addResultText(resultStr);


}






void ClassTabFour::checkHistory(QString url)
{
    qDebug()<<"ClassTabFour::checkHistory(): "<<url;
    Data::GetInstance().activeTab(2,url);

}



void ClassTabFour::cancelZhuiZong(QString url){

    QMessageBox message(QMessageBox::NoIcon, "提醒", "确定取消追踪?", QMessageBox::Yes|QMessageBox::No, NULL);
    if(message.exec() == QMessageBox::Yes)
    {
        qDebug()<<"用户确定取消追踪此营业部";
        if( Data::GetInstance().service->DeleteYinyebuByURL(url) ) {
            qDebug()<<"ClassTabFour::cancelZhuiZong() 取消成功 ";
            updateTableWidget();
        }else{
            qDebug()<<"ClassTabFour::cancelZhuiZong() 取消失败 ";
        }

    }else{
        qDebug()<<"用户不取消追踪此营业部了";
    }


}



//点击分析结果的股票链接 实现跳转
void ClassTabFour::activeStockURL(const QString &link)
{
    qDebug()<<"点击个股链接:"<<link;
    //msg为股票代码
    int startPos = link.indexOf("cjmx/") + 5;
    QString code = link.mid(startPos,6);
    Data::GetInstance().activeTab(6,code);
    //qDebug()<<"加工过后的位置:"<<link.mid(startPos,6);
    //QString msg = link.mid(link.length()-6 ,6 );
    //Data::GetInstance().activeTab(6,msg);

}

//按钮:开始分析
void ClassTabFour::on_pushButton_2_clicked()
{
    addResultText("<html>");
    addResultText("最新交易数据的日期为:" + Data::GetInstance().tabOne->newDateString + "<br>" );
    startAnalysis();
}


//按钮： 清空结果
void ClassTabFour::on_pushButton_3_clicked()
{
    labelResult->clear();
}


//按钮: 上传结果到服务器
void ClassTabFour::on_pushButton_clicked()
{
    int i,j;
    //构造请求

    //
    uploadProgressDialog.setLabelText("正在上传到服务器，请稍候...");
    uploadProgressDialog.setRange(0, listResultStock.size()); // 指定进度条的值范围
    uploadProgressDialog.setValue(0);
    uploadProgressDialog.setCancelButton(0);
    uploadProgressDialog.setModal(true);
    uploadProgressDialog.reset();

    //输出排序结果
    QString urlString,yinyebuUrlStringList,yinyebuNameStringList;
    QUrl url;
    uploadStockCount = 0;

    for(i=0; i<listResultStock.size(); i++) {
        uploadProgressDialog.setValue(i);
        urlString.clear();
        yinyebuNameStringList.clear();
        yinyebuUrlStringList.clear();
        //拼接营业部name列表
        for(j=0; j< listResultStock.at(i)->yinyebuName.size(); j++ ) {
            yinyebuNameStringList.append(listResultStock.at(i)->yinyebuName.at(j));
            if( j != (listResultStock.at(i)->yinyebuName.size()-1) ) {
                yinyebuNameStringList.append(",");
            }
        }
        //拼接营业部nrl列表
        for(j=0; j< listResultStock.at(i)->yinyebuURL.size(); j++ ) {
            yinyebuUrlStringList.append(listResultStock.at(i)->yinyebuURL.at(j));
            if( j != (listResultStock.at(i)->yinyebuURL.size()-1) ) {
                yinyebuUrlStringList.append(",");
            }
        }
        //拼接http请求
        urlString.append(Data::GetInstance().URL_Upload_Stock);
        urlString.append("stockCode=" + listResultStock.at(i)->stockCode);
        urlString.append("&stockName=" + listResultStock.at(i)->stockName );
        urlString.append("&yinyebuUrlList=" + yinyebuUrlStringList );
        urlString.append("&yinyebuNameList=" + yinyebuNameStringList );
        urlString.append("&uploadTime=" + Data::GetInstance().currentDateString );

        //发送请求，一只股票对应一个请求
        url.setUrl(urlString);
        reply2 = manager.get( QNetworkRequest( url ) );
        connect(reply2, SIGNAL(finished()),this, SLOT(uploadStockFinished()));
        if( !Data::GetInstance().eventLoop.isRunning() ) Data::GetInstance().eventLoop.exec();
        //qDebug()<<"发送请求:"<<urlString;
    }


}


void ClassTabFour::uploadStockFinished()
{
    //停止堵塞
    Data::GetInstance().eventLoop.quit();
    uploadStockCount++;
    uploadProgressDialog.setValue(uploadStockCount);

}

//排序的cmp函数
bool sortCmp(const ResultStock* stock1, const ResultStock* stock2)
{
    return ( stock1->count > stock2->count );
}

//开始对listResultStock排序
void ClassTabFour::startSortListResultStock()
{
    qStableSort( listResultStock.begin(),listResultStock.end(),sortCmp );
    //qSort( listResultStock.begin(),listResultStock.end(),sortCmp );

}
