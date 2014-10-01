#include "classtabone.h"
#include "ui_classtabone.h"


ClassTabOne::ClassTabOne(QWidget *parent) : QWidget(parent), ui(new Ui::ClassTabOne)
{
    ui->setupUi(this);
    labelYinYeBu = new QLabel(this);
    labelYinYeBu->setStyleSheet("background-color:#fff;");
    connect(labelYinYeBu,SIGNAL(linkActivated(QString)),this,SLOT(openYinYeBuURL(QString)));


    //初始化模型
    tableModelOne = new ClassTableModelOne;


    //获得最新日期
    QString strUrl = "http://data.10jqka.com.cn/market/longhu/";
    QUrl url(strUrl);
    replyGetNewDate = manager.get( QNetworkRequest( url ) );
    connect(replyGetNewDate, SIGNAL(finished()),this, SLOT(DownloadNewDateFinished()));
    if( !Data::GetInstance().eventLoop.isRunning() ) Data::GetInstance().eventLoop.exec();

    //初始化时间控件
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd ddd");
    currentLongHuBangDateString = newDateString;
    ui->dateEdit->setDate( QDate::fromString(newDateString,"yyyy-MM-dd") );
    ui->dateEdit->setSelectedSection(QDateTimeEdit::DaySection);

    //currentYinYeBuDateString = "2014-07-18";  //交易营业部日期

}

ClassTabOne::~ClassTabOne()
{
    delete ui;
}


void ClassTabOne::initTableView()
{


    tableModelOne = new ClassTableModelOne;
    //代理model，实现表格排序   //默认按string排序，如果需要自定义排序规则，要继承重写这个类
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(tableModelOne);
    //为tableView设定model等设置
    ui->tableView1->setModel(proxyModel);  //代理model
    ui->tableView1->setSortingEnabled(true);    //可排序
    //ui->tableView1->horizontalHeader()->setStretchLastSection(true);
    ui->tableView1->verticalHeader()->hide();  //表格头的垂直部分隐藏
    ui->tableView1->setEditTriggers(QAbstractItemView::NoEditTriggers); //不允许直接界面上编辑
    ui->tableView1->setSelectionMode(QAbstractItemView::SingleSelection);//只能单选
    ui->tableView1->setSelectionBehavior(QAbstractItemView::SelectRows); //单击时选择一整行
    ui->tableView1->resizeColumnsToContents();//自适应列宽
    ui->tableView1->resizeRowsToContents(); //自适应行高

    //在界面上显示数据
    //tableModelOne->insertRows(0,Data::GetInstance().listLongHuBang.size(),QModelIndex());

    //列宽调整
    ui->tableView1->setColumnWidth(0,30);
    ui->tableView1->setColumnWidth(1,80);
    ui->tableView1->setColumnWidth(7,130);
    //计算左边表格宽度
    sumLeftLayoutWidth=0;
    for(int i=0;i<9;i++) {
        sumLeftLayoutWidth += ui->tableView1->columnWidth(i);
    }
    sumLeftLayoutWidth += 22;

    //左边表格宽高位置
    QSize sizeTableView1(sumLeftLayoutWidth,this->height()-5);
    ui->tableView1->setFixedSize(sizeTableView1);
    //右边
    //QRect r( sumLeftLayoutWidth+10, ui->tableView1->y(),  );
    qDebug()<<"this->width()"<<this->width()<<"  sumLeftLayoutWidth:"<<sumLeftLayoutWidth;
    ui->scrollArea->setFixedSize(Data::GetInstance().destopWidth-sumLeftLayoutWidth-25, this->height()-5);
    ui->scrollArea->setWidget(labelYinYeBu);
    //ui->webView->setGeometry(  );

}




//开始下载龙虎榜数据
void ClassTabOne::StartDownloadLongHuBang()
{
    qDebug()<<"开始下载龙虎榜数据 ClassTabOne::StartDownloadLongHuBang()";
    QUrl url1("http://data.10jqka.com.cn/market/longhu/date/"+currentLongHuBangDateString+"/");
    reply1 = manager.get( QNetworkRequest( url1 ) );
    connect(reply1, SIGNAL(finished()),this, SLOT(DownloadLongHuFinished()));
    if( !Data::GetInstance().eventLoop.isRunning() ) Data::GetInstance().eventLoop.exec();

}

//
void ClassTabOne::StartDownloadYinYeBu()
{

    //解析网页，获得日期列表，营业部标题等信息
    QUrl url3("http://data.10jqka.com.cn/market/longhu/cjmx/"+currentStockCode+"/");
    reply3 = manager.get( QNetworkRequest( url3 ) );
    connect(reply3, SIGNAL(finished()),this, SLOT(DownloadLongHuDateListFinished()));
    if( !Data::GetInstance().eventLoop.isRunning() ) Data::GetInstance().eventLoop.exec();

    //通过同花顺接口   获得营业部历史操作的股票数据列表
    QUrl url2("http://data.10jqka.com.cn/interface/market/cjmx/"+currentStockCode+"/"+currentYinYeBuDateString+"/");
    reply2 = manager.get( QNetworkRequest( url2 ) );
    connect(reply2, SIGNAL(finished()),this, SLOT(DownloadYinYeBuFinished()));
    if( !Data::GetInstance().eventLoop.isRunning() ) Data::GetInstance().eventLoop.exec();




    qDebug()<<"开始下载营业部数据  ClassTabOne::StartDownloadYinYeBu()";

}

//下载完毕，封装到Tool.listLongHuBang中

void ClassTabOne::DownloadLongHuFinished()
{
    qDebug()<<"龙虎榜数据下载完毕 ClassTabOne::DownloadLongHuFinished()";
    //停止堵塞
    Data::GetInstance().eventLoop.quit();
    //获取网页源码
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QString htmlQString = codec->toUnicode(reply1->readAll());
    std::string htmlString = htmlQString.toStdString();
    std::wstring htmlWString = htmlQString.toStdWString();

    //解析网页源码，把数据整合好放进 QList<QStringList> listLongHuBang;
    handleData(htmlString);

    //通知界面更新
    initTableView();

}

//下载完毕
void ClassTabOne::DownloadYinYeBuFinished()
{
    outQString("营业部信息下载完毕，开始解析    ClassTabOne::DownloadYinYeBuFinished()");
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
    QString htmlString = jsonObj.take("data").toString();
    //把<span>标签和<img>标签隐藏掉
    int j=0;
    while( (j=htmlString.indexOf("<span ", j)) != -1 ) {
        //qDebug()<<"find span"<<j;
        htmlString.replace(j,49,"<k style=\"display:none;\"> ");
    }
    j=0;
    while( (j=htmlString.indexOf("<img ", j)) != -1 ) {
        //qDebug()<<"find span"<<j;
        htmlString.replace(j,101,"<k style=\"display:none;\"> ");
    }

    QString stockCode =  Data::GetInstance().listLongHuBang.at(wantIndex.row()).at(1);
    QString stockname =  Data::GetInstance().listLongHuBang.at(wantIndex.row()).at(2);
    ui->labelStockNow->setText(stockCode+"  "+stockname);
    labelYinYeBu->setText( htmlString );

    qDebug()<<"营业部数据下载完毕 ClassTabOne::DownloadYinYeBuFinished()";



}


void ClassTabOne::DownloadLongHuDateListFinished()
{
    outQString("营业部日期列表下载完毕 开始解析 ClassTabOne::DownloadLongHuDateListFinished()");
    //停止堵塞
    Data::GetInstance().eventLoop.quit();
    //获取网页源码
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QString htmlQString = codec->toUnicode(reply3->readAll());
    std::string htmlString = htmlQString.toStdString();

    MyParse parser;
    parser.parseHtml( htmlString.c_str() );
    QList<GumboNode*> selectNodeList = parser.getNodeListByTag(GUMBO_TAG_SELECT);
    GumboNode* selectNode = selectNodeList.at(0);
    QList<GumboNode*> optionList = parser.getNodeListByTag(selectNode,GUMBO_TAG_OPTION);
    GumboNode  *optionNode,*textNode;

    //outQString( optionList.size() );
    ui->comboBox->clear();
    int currentIndex = 0;
    ui->comboBox->setFrame(true); //当前项不在下拉选择项中
    for(int i=0; i<optionList.size(); i++) {
        optionNode = optionList.at(i);
        textNode = parser.getChildAt( optionNode , 0 );
        if( StringToQString(textNode->v.text.text) == currentYinYeBuDateString ) currentIndex=i;
        ui->comboBox->addItem( StringToQString(textNode->v.text.text) );
    }
    ui->comboBox->setCurrentIndex(currentIndex);


    qDebug()<<"营业部日期列表解析和整合完毕 ClassTabOne::DownloadLongHuDateListFinished";

}


void ClassTabOne::DownloadNewDateFinished()
{

    qDebug()<<"正在获取龙虎榜数据的最新发布日期 ClassTabOne::DownloadNewDateFinished()";
    //停止堵塞
    Data::GetInstance().eventLoop.quit();
    //获取网页源码
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QString htmlQString = codec->toUnicode(replyGetNewDate->readAll());
    std::string htmlString = htmlQString.toStdString();
    std::wstring htmlWString = htmlQString.toStdWString();

    //解析网页
    MyParse *parser = new MyParse;
    parser->parseHtml( htmlString.c_str() );
    QList<GumboNode*> inputNodeList = parser->getNodeListByTag(GUMBO_TAG_INPUT);

    qDebug()<<"input size:"<<inputNodeList.size();
    GumboNode *inputNode; GumboAttribute *className,*valueName;
    for(int i=0; i<inputNodeList.size(); i++ ) {
        inputNode = inputNodeList.at(i);
        if( className = gumbo_get_attribute( &inputNode->v.element.attributes,"class" )  ) {
            //qDebug()<<"input className: "<<  className->value;
            if( StringToQString( className->value ) == "m_text_date startday" ) {
                valueName = gumbo_get_attribute( &inputNode->v.element.attributes,"value" );
                //qDebug()<<"input value: "<<  valueName->value;
                newDateString = StringToQString( valueName->value );
                break;
            }
        }
    }

    //停止堵塞
    Data::GetInstance().eventLoop.quit();



}


void ClassTabOne::handleData(std::string htmlString)
{
    //解析网页，收集所有tr元素节点
    MyParse *parser = new MyParse;
    parser->parseHtml( htmlString.c_str() );
    QList<GumboNode*> trNodeList = parser->getNodeListByTag(GUMBO_TAG_TR);

    QStringList stringList;
    //先清空原来的数据
    Data::GetInstance().listLongHuBang.clear();


    if( trNodeList.size() < 3 ) {
        //QMessageBox::information(NULL,"提醒","此日期非交易日，无数据");
        stringList.clear();
        stringList<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<"非交易日，无数据";
        Data::GetInstance().listLongHuBang.append(stringList);
        return;
    }




    //处理节点 封装进stringList
    GumboNode* textNode,*trNode,*aNode;
    QList<GumboNode*> tdNodeList;  // <td>标签 节点列表
    //cout<<"size: "<<trNodeList.size()<<endl;
    //处理每一个tr元素 封装进strinlist，然后放进model的listLongHuBang
    for(int i=1; i<trNodeList.size();i++)
    {
        stringList.clear();

        tdNodeList = parser->getNodeListByTag( trNodeList.at(i),GUMBO_TAG_TD );

        //(序号)第一个td节点里面的文本节点
        textNode = parser->getChildAt( tdNodeList.at(0) , 0 );
        stringList.append( StringToQString( string( textNode->v.text.text) )  );

        //(代码)第二个td节点里面的 a节点里面的  文本节点
        aNode = parser->getNodeByTag(tdNodeList.at(1) , GUMBO_TAG_A );
        textNode = parser->getChildAt( aNode , 0 );
        stringList.append( StringToQString(  string( textNode->v.text.text)   ));

        //(简称)第三个td节点里面的 a节点里面的  文本节点
       aNode = parser->getNodeByTag(tdNodeList.at(2) , GUMBO_TAG_A );
       textNode = parser->getChildAt( aNode , 0 );
       stringList.append( StringToQString(  string( textNode->v.text.text)   ));

       //第四个td节点里面的文本节点
       textNode = parser->getChildAt( tdNodeList.at(3) , 0 );
       stringList.append( StringToQString(  string( textNode->v.text.text)   ));

       //第五个节点里面的
       textNode = parser->getChildAt( tdNodeList.at(4) , 0 );
       stringList.append( StringToQString(  string( textNode->v.text.text)   ));

       //第六个节点里面的
       textNode = parser->getChildAt( tdNodeList.at(5) , 0 );
       stringList.append( StringToQString(  string( textNode->v.text.text) ));

       //第七个节点里面的
       textNode = parser->getChildAt( tdNodeList.at(6) , 0 );
       stringList.append( StringToQString(  string( textNode->v.text.text) ));

       //第八个节点里面的
       textNode = parser->getChildAt( tdNodeList.at(7) , 0 );
       stringList.append( StringToQString(  string( textNode->v.text.text)   ));

       Data::GetInstance().listLongHuBang.append(stringList);
    }



}

void ClassTabOne::on_tableView1_clicked(const QModelIndex &index)
{
    //鼠标点击的index不是tableModelOne的index，而是proxyModel的index，佩服qt的巧妙设计
    //outQString( tableModelOne->data(index,Qt::DisplayRole).toString() ); //不是这个
    //outQString( proxyModel->data(index,Qt::DisplayRole).toString() );
    wantIndex = proxyModel->mapToSource(index);
    //outQString( tableModelOne->data(wantIndex,Qt::DisplayRole).toString() );
    //下面这个就是鼠标点击所在行的股票代码
    //outQString( listLongHuBang->at(wantIndex.row()).at(2) );
    currentStockCode =  Data::GetInstance().listLongHuBang.at(wantIndex.row()).at(1);
    currentStockName =  Data::GetInstance().listLongHuBang.at(wantIndex.row()).at(2);
    //currentLongHuBangDateString = "2014-07-18";
    currentYinYeBuDateString = currentLongHuBangDateString;
    StartDownloadYinYeBu();

}


void ClassTabOne::openYinYeBuURL(QString url)
{
    Data::GetInstance().activeTab(2,url);
}



void ClassTabOne::on_comboBox_activated(const QString &arg1)
{
    currentYinYeBuDateString = arg1;
    StartDownloadYinYeBu();
}


//单击"查看行情"按钮    显示股票行情
void ClassTabOne::on_pushButton_2_clicked()
{

    outQString(currentStockCode + "  " + currentStockName);
    //Data::GetInstance().showStockWebViewWindow(currentStockCode,currentStockName);

}

//双击表格，显示股票行情
void ClassTabOne::on_tableView1_doubleClicked(const QModelIndex &index)
{

    outQString( "双击表格，开始调用行情窗口 ClassTabOne::on_tableView1_doubleClicked " );
    //Data::GetInstance().showStockWebViewWindow(currentStockCode,currentStockName);

}



//按钮 前一日
void ClassTabOne::on_pushButton_3_clicked()
{
    //ui->dateEdit->setDate();
    QDate date = ui->dateEdit->date();
    date = date.addDays(-1) ;
    currentLongHuBangDateString = date.toString("yyyy-MM-dd");
    ui->dateEdit->setDate(date);

}


//按钮 后一日
void ClassTabOne::on_pushButton_4_clicked()
{
    QDate date = ui->dateEdit->date();
    date = date.addDays(1) ;
    currentLongHuBangDateString = date.toString("yyyy-MM-dd");
    ui->dateEdit->setDate(date);

}

void ClassTabOne::on_dateEdit_userDateChanged(const QDate &date)
{
    qDebug()<<"ClassTabOne::on_dateEdit_userDateChanged():"<<date.toString("yyyy-MM-dd");
    currentLongHuBangDateString = date.toString("yyyy-MM-dd");
    StartDownloadLongHuBang();
}


void ClassTabOne::on_dateEdit_dateChanged(const QDate &date)
{
    qDebug()<<"ClassTabOne::on_dateEdit_dateChanged()"<<date.toString("yyyy-MM-dd");

}


