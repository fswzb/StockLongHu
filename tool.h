#ifndef TOOL_H
#define TOOL_H



#include <QDebug>
#include <qstring>
#include <QStringList>
#include <QList>
#include <QVariant>
#include <QTabWidget>
#include <webviewwindow.h>
#include <gumbo/gumbo.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <beanandservice.h>

#include "classtabone.h"
#include "classtabtwo.h"
#include "classtabthree.h"
#include "classtabfour.h"
#include "classtabfive.h"
#include "classtabsix.h"

class ClassTabOne;
class ClassTabTwo;
class ClassTabThree;
class ClassTabFour;
class ClassTabFive;
class ClassTabSix;
class WebViewWindow;
class Service;
class BeanStock;
class BeanYinYeBu;


//一些字符串处理的函数
void outWString(std::wstring str);
void outString(std::string str );
void outQString(QVariant value);
QString StringToQString(std::string str);
QString WStringToQString(std::wstring str);



class Data
{
private:
    //构造函数是私有的
    Data() {}
public:
    static Data& GetInstance()
    {
        static Data data;
        return data;
    }

    //屏幕分辨率
    int destopWidth = 0;
    int destopHeight = 0;
    //当前日期
    QString currentDateString;

    //选项卡界面
    QTabWidget* tabWidget;
    ClassTabOne *tabOne;
    ClassTabTwo *tabTwo;
    ClassTabThree *tabThree;
    ClassTabFour *tabFour;
    ClassTabFive *tabFive;
    ClassTabSix *tabSix;

    //循环，用于发送http请求后堵塞程序，实现同步,
    //在代码 get，connect之后，运行eventLoop.exec()进行堵塞，在onXxxFinished()里的第一句停止循环堵塞 eventLoop.quit()
    QEventLoop eventLoop;

    //数据库
    QSqlDatabase db;
    //操作类:  对数据库业务模型的增删改查
    Service *service;


    //数据源:下载好的龙虎榜的股票列表
    //1 "序号"        2 "股票代码"  3 "股票简称"
    //4 "收盘价"   5 "涨跌幅"       6 "成交量(万股)"
    //7 "成交额(万元)"   8 "类型"   9 "明细"
    QList<QStringList> listLongHuBang;


    //数据源 自选追踪营业部
    QList<BeanYinYeBu> listZiXuanYinYeBu;

    //数据源: 用户自选和追踪的营业部
    //WebViewWindow stockWebViewWindow; //显示股票行情


    //激活某个选项页
    void activeTab(int i,int msg);
    void activeTab(int i,QString msg);


    //网络接口：将选股数据传送到服务器保存
    QString URL_Upload_Stock = "http://localhost/mystock1993/upload.php?";



};




//MyParse类，对Gumbo进一步封装
class MyParse
{

public:
    //维护网页的所有节点
    QList<GumboNode*> htmlNodeList;
    //把网页源码的string.c_str()解析出每一个元素node放进htmlNodeList
    void parseHtml(const char* buffer);
    //用来从根节点开始递归遍历所有节点，放进htmlNodeList
    void parse(GumboNode* node);
    //获得一个节点的子节点列表
    QList<GumboNode*> getChildrenNodeList(GumboNode* node);
    //获得节点node的第i个子节点
    GumboNode* getChildAt(GumboNode* node,int i);
    //在htmlNodeList中找到标签为tagType的节点
    QList<GumboNode*> getNodeListByTag(GumboTag tagType);
    //在node的子节点中找到标签为tagType的节点列表
    QList<GumboNode*> getNodeListByTag(GumboNode* node,GumboTag tagType);
    //在node的子节点中找到标签为tagType的节点
    GumboNode* getNodeByTag(GumboNode* node,GumboTag tagType);

};


#endif
