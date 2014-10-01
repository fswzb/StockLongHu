#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initDataBase();
    initWindowUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWindowUI()
{
    Data::GetInstance().service = new Service;

    //窗口标题
    Data::GetInstance().currentDateString = QDate::currentDate().toString("yyyy-MM-dd");
    QString dateString = QDate::currentDate().toString("yyyy-MM-dd ddd");
    setWindowTitle("股票分析    当前日期:"  + dateString);
    //窗口大小
    setCentralWidget(ui->tabWidget);
    setWindowState(Qt::WindowMaximized);
    //屏幕分辨率
    Data::GetInstance().destopWidth =  QApplication::desktop()->width();
    Data::GetInstance().destopHeight =  QApplication::desktop()->height();
    qDebug()<<"屏幕宽"<<Data::GetInstance().destopWidth<<"  屏幕高:"<<Data::GetInstance().destopHeight;
    //



    //tab选项卡界面
    Data::GetInstance().tabWidget = ui->tabWidget;
    Data::GetInstance().tabOne = new ClassTabOne;
    ui->tabWidget->addTab(Data::GetInstance().tabOne,"个股龙虎榜");
    Data::GetInstance().tabTwo = new ClassTabTwo;
    ui->tabWidget->addTab(Data::GetInstance().tabTwo,"活跃营业部");
    Data::GetInstance().tabThree = new ClassTabThree;
    ui->tabWidget->addTab(Data::GetInstance().tabThree,"活跃个股");
    Data::GetInstance().tabFour = new ClassTabFour;
    ui->tabWidget->addTab(Data::GetInstance().tabFour,"营业部分析");
    Data::GetInstance().tabFive = new ClassTabFive;
    ui->tabWidget->addTab(Data::GetInstance().tabFive,"盈利预测");
    Data::GetInstance().tabSix = new ClassTabSix;
    ui->tabWidget->addTab(Data::GetInstance().tabSix,"个股行情");


}


//开启数据库连接
void MainWindow::initDataBase()
{
    QSqlDatabase &db = Data::GetInstance().db;

    //创建数据库实例(即创建数据库连接)
    //addDatabase() 第一个参数为要装载的驱动，这里使用qt自带的qsqlite
    //第二个参数"connectDB_1" 为自定义的数据库连接名，不是数据库名 )
    db = QSqlDatabase::addDatabase("QSQLITE", "connectDB_1");

    //选择要使用的数据库名字   即工程目录下的stock.db
    //因为连接的是本地sqlite数据库，所以  主机，用户名，密码不需要配置
    db.setDatabaseName("stock.db");
    //    db.setHostName("host");
    //    db.setDatabaseName("dbname");
    //    db.setUserName("username");
    //    db.setPassword("password");



    //尝试连接数据库
    if (!db.open()) {
        outQString("无法打开数据库，错误为:" + db.lastError().text() );
    }
    else {
        outQString("数据库已成功打开");
        qDebug()<<"数据库含表:"<< db.tables();  //输出数据库里面的表

        //QSL语句，参数里要填入一个数据库实例,而且一定要在 db.open()以后定义，
        //之前报了一个out of memory Unable to execute statement 就是因为在db.open()前就定义了
        QSqlQuery query( db )  ;

        //如果表table_zixuangu不存在  则创建
        if( ! db.tables().contains("table_zixuangu") ) {
           bool correct =  query.exec(" create table table_zixuangu ("
                                      " stockId  INTEGER PRIMARY KEY AUTOINCREMENT ,"
                                      " stockCode varchar not null ,"
                                      " stockName varchar not null ,"
                                      " stockRemark varchar"
                                      ")  ");

           if(!correct ) outQString("建表语句执行错误：" + query.lastError().text() );
           else
               outQString("建表table_zixuangu 成功");
        }
        else outQString("表table_zixuangu已存在");


        //如果表table_yinyebu不存在  则创建
        if( ! db.tables().contains("table_yinyebu") ) {
           bool correct =  query.exec(" create table table_yinyebu ("
                                      " yinyebuId  INTEGER PRIMARY KEY AUTOINCREMENT ,"
                                      " yinyebuName varchar not null unique,"
                                      " yinyebuUrlPage varchar not null unique,"
                                      " yinyebuUrlInterface varchar unique,"
                                      " yinyebuRemark varchar "

                                      ")  ");

           if(!correct ) outQString("建表语句执行错误：" + query.lastError().text() );
           else
               outQString("建表table_yinyebu 成功");
        }
        else outQString("表table_yinyebu已存在");

    }


    //最后输出数据库所有表
    qDebug()<<"数据库含表: "<<db.tables();


}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    qDebug()<<"currentChanged "<<index;
}
