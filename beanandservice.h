#ifndef BEANANDSERVICE_H
#define BEANANDSERVICE_H

#include <QString>
#include <tool.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


//筛选出来的股票
class ResultStock {
public:
    QString stockName;
    QString stockCode;
    QStringList yinyebuURL;  //买入的机构 url列表
    QStringList yinyebuName; //买入的机构 名称列表
    int count; //买入的机构数量
};


//bean类: 营业部
class BeanYinYeBu
{
public:
    QString yinyebuId; //营业部在数据库中的id
    QString yinyebuName; //营业部名称
    QString yinyebuUrlPage; //(同花顺)营业部对应url
    QString yinyebuUrlInterface; // (同花顺)营业部股票数据对应url
    QString yinyebuRemark; //用户对营业部的备注
};


//bean类: 股票
class BeanStock
{
public:
    QString stockId; //股票在数据库中的id
    QString stockCode; //股票代码
    QString stockName; //股票名称
    QString stockRemark; //股票备注
};


//Service类，对股票和营业部进行增删改查
class Service
{
public:
    //把一只股票加入自选股票
    void AddStock( BeanStock stock );
    //删除自选股(根据股票代码)
    void DeleteStockByCode(QString code);
    //返回所有自选股
    QList<BeanStock> getAllStock();


    //把一只股票加入追踪营业部列表
    void AddYinYeBu( BeanYinYeBu yinyebu);
    //删除一个营业部(根据营业部的同花顺url)
    bool DeleteYinyebuByURL(QString url );
    //返回所有营业部
    QList<BeanYinYeBu> getAllYinYeBu();

};


#endif // BEANANDSERVICE_H
