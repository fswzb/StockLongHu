#include "classtablemodelone.h"

ClassTableModelOne::ClassTableModelOne()
{

}

int ClassTableModelOne::rowCount(const QModelIndex &parent) const
{
    return Data::GetInstance().listLongHuBang.size();
}


int ClassTableModelOne::columnCount(const QModelIndex &parent) const
{
    return 8; //龙虎榜有9列数据
}


QVariant ClassTableModelOne::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:return tr("序号");
            case 1:return tr("代码");
            case 2:return tr("简称");
            case 3:return tr("收盘价");
            case 4:return tr("涨跌幅");
            case 5:return "成交量/万股";
            case 6:return tr("成交额/万元");
            case 7:return tr("类型");
            default:
                return QVariant();
        }
    }
    return QVariant();
}



bool ClassTableModelOne::insertRows(int position, int rows, const QModelIndex &index)
{


    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    endInsertRows();
    return true;
}

bool ClassTableModelOne::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    endRemoveRows();
    return true;
}

//setData() 把界面的数据修改 同步到数据源
bool ClassTableModelOne::setData(const QModelIndex &index, const QVariant &value, int role)
{

    return true;
}



QVariant ClassTableModelOne::data(const QModelIndex &index, int role) const
{

    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() >= Data::GetInstance().listLongHuBang.size() || index.row() < 0) {
        return QVariant();
    }


    if (role == Qt::DisplayRole) {
       QStringList p = Data::GetInstance().listLongHuBang.at(index.row());
       return p.at( index.column() );
    }


    return QVariant();
}










