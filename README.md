## 说明
使用QT，Gumbo-parser，AVOSCloud等开发工具
对交易所每日公布的营业部交易数据(龙虎榜) 进行统计分析
从而对相关股票进行盈利预测分析

数据库：
```
//如果表table_zixuangu不存在  则创建
        if( ! db.tables().contains("table_zixuangu") ) {
           bool correct =  query.exec(" create table table_zixuangu ("
                            " stockId  INTEGER PRIMARY KEY AUTOINCREMENT ,"
                            " stockCode varchar not null ,"
                            " stockName varchar not null "
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
                            " YinYeBuURL_1 varchar not null ,"
                            " yinyebuName varchar not null ,"
                            " yinyebuRemark varchar "
                            ")  ");


```  
  
程序加载的哪一个html? :
在Qt-creator编译运行，打开的html是 build-testTabUI-Desktop_Qt_5_0_2_MinGW_32bit-Release下面的  

直接在release文件夹里的exe，打开的html是 build-testTabUI-Desktop_Qt_5_0_2_MinGW_32bit-Release\release下面的








