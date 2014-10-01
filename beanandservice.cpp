#include "beanandservice.h"

void Service::AddStock(BeanStock stock)
{
    QSqlDatabase &db = Data::GetInstance().db;
    QSqlQuery query(db);
    QString sql = "insert into table_zixuangu (stockCode,stockName) values ("
                   + stock.stockCode + " "+ stock.stockName +")";
    outQString( "执行语句:" + sql );
    bool re = query.exec(sql);
    if(re) {
        outQString("执行成功:"+sql);
    }
    else {
        outQString("执行失败:" + sql);
        outQString("失败原因:" + query.lastError().text() );
    }

}

void Service::DeleteStockByCode(QString code)
{
    QSqlDatabase &db = Data::GetInstance().db;
    QSqlQuery query(db);
    QString sql = "delete from table_zixuangu where stockCode = '"
                   + code + "';";
    outQString( "执行语句:" + sql );
    bool re = query.exec(sql);
    if(re) {
        outQString("执行成功:"+sql);
    }
    else {
        outQString("执行失败:" + sql);
        outQString("失败原因:" + query.lastError().text() );
    }

}

QList<BeanStock> Service::getAllStock()
{
    QList<BeanStock> t;
    return t;
}

void Service::AddYinYeBu(BeanYinYeBu yinyebu)
{
    QSqlDatabase &db = Data::GetInstance().db;
    QSqlQuery query(db);
    QString sql = "insert into table_yinyebu (yinyebuName,yinyebuUrlPage,yinyebuUrlInterface) values ('"
                + yinyebu.yinyebuName  + "','" + yinyebu.yinyebuUrlPage + "','"+ yinyebu.yinyebuUrlInterface +"')";
    outQString( "执行语句:" + sql );
    bool re = query.exec(sql);
    if(re) {
        outQString("执行成功:"+sql);
    }
    else {
        outQString("执行失败:" + sql);
        outQString("失败原因:" + query.lastError().text() );
    }

    //更新界面
    Data::GetInstance().tabFour->updateTableWidget();
}

bool Service::DeleteYinyebuByURL(QString url)
{
    QSqlDatabase &db = Data::GetInstance().db;
    QSqlQuery query(db);
    QString sql = "delete from table_yinyebu where yinyebuUrlPage = '"
                   + url + "';";
    outQString( "执行语句:" + sql );
    bool re = query.exec(sql);
    if(re) {
        outQString("执行成功:"+sql);
        return true;
    }
    else {
        outQString("执行失败:" + sql);
        outQString("失败原因:" + query.lastError().text() );
        return false;
    }

}

QList<BeanYinYeBu> Service::getAllYinYeBu()
{
    QList<BeanYinYeBu> yinyebuList;
    BeanYinYeBu yinyebu;

    QSqlDatabase &db = Data::GetInstance().db;
    QSqlQuery query(db);
    QString sql = "select * from table_yinyebu;";
    outQString( "执行语句:" + sql );
    bool re = query.exec(sql);
    if(re) {
        outQString("执行成功:"+sql);
        //循环放入yinyebuList
        while( query.next() ) {
            yinyebu.yinyebuUrlPage = query.value(2).toString();
            yinyebu.yinyebuName = query.value(1).toString();
            yinyebu.yinyebuUrlInterface = query.value(3).toString();
            yinyebuList.append(yinyebu);
        }
    }
    else {
        outQString("执行失败:" + sql);
        outQString("失败原因:" + query.lastError().text() );
    }


    return yinyebuList;
}




