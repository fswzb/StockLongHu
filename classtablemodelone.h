#ifndef CLASSTABLEMODELONE_H
#define CLASSTABLEMODELONE_H

#include <QDebug>
#include <tool.h>
#include <QAbstractTableModel>
#include <QList>
#include <QStringList>
#include <QSortFilterProxyModel>





class ClassTableModelOne : public QAbstractTableModel
{
    Q_OBJECT

public:
    ClassTableModelOne();



    //以下为继承父类虚函数
    int rowCount(const QModelIndex &parent) const;  //行数
    int columnCount(const QModelIndex &parent) const;  //列数
    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);
    //view刚显示时通过model的这个函数初始化数据显示(重写此函数，以确定数据源的数据要显示在view的哪个位置(ModelIndex))
    QVariant data(const QModelIndex &index, int role) const;
    //后期通过调用这个函数  设置某个item的数据
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    //view刚刚显示时，会调用这个函数，显示表格表头(横向和纵向)
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;



};

#endif // CLASSTABLEMODELONE_H
