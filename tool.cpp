#include "tool.h"

void outWString(std::wstring str)
{
    qDebug()<< QString::fromStdWString(str);
}

void outString(std::string str )
{
    qDebug()<< QString::fromStdString(str);
}

void outQString(QVariant value)
{
    qDebug()<< value.toString() ;
}

QString StringToQString(std::string str)
{
    return QString::fromStdString(str);
}

QString WStringToQString(std::wstring str)
{
   return QString::fromStdWString(str);
}

//把网页源码的string.c_str()解析出每一个node放进nodelist
void MyParse::parseHtml(const char* buffer)
{
    GumboOutput* output = gumbo_parse(buffer);
    parse(output->root);
}

//用来从根节点开始递归遍历所有节点，放进htmlNodeList
void MyParse::parse(GumboNode* node)
{
    if (node->type != GUMBO_NODE_ELEMENT ) {
        return;
    }
    else if( node->type == GUMBO_NODE_ELEMENT )
    {
        htmlNodeList.append(node);
        GumboVector* children = &node->v.element.children;
        for (int i = 0; i < children->length; ++i)
        {
           parse((GumboNode*) children->data[i]);
        }
    }

}

//在htmlNodeList中找到标签为tagType的lit
QList<GumboNode*> MyParse::getNodeListByTag(GumboTag tagType)
{
    QList<GumboNode*> nodeList;
    for(int i=0; i<htmlNodeList.size();i++)
    {
        if( htmlNodeList.at(i)->v.element.tag == tagType ){
            nodeList.append( htmlNodeList.at(i) );
        }

    }
    return nodeList;
}


GumboNode* MyParse::getChildAt(GumboNode* node,int i)
{
    GumboVector* children = &node->v.element.children;

    return ((GumboNode*)children->data[i]);
}

QList<GumboNode*> MyParse::getChildrenNodeList(GumboNode* node)
{
    QList<GumboNode*> nodeList;
    GumboVector* children = &node->v.element.children;
    for (int i = 0; i < children->length; ++i)
    {
        nodeList.append( (GumboNode*) children->data[i] );
    }
    return nodeList;
}

QList<GumboNode*> MyParse::getNodeListByTag(GumboNode* node,GumboTag tagType)
{
    QList<GumboNode*> childrenNodeList = getChildrenNodeList(node);
    QList<GumboNode*> nodeList;
    for(int i=0; i<childrenNodeList.size();i++)
    {
        if( childrenNodeList.at(i)->v.element.tag == tagType ){
            nodeList.append( childrenNodeList.at(i) );
        }

    }
    return nodeList;

}


GumboNode* MyParse::getNodeByTag(GumboNode* node,GumboTag tagType)
{
    QList<GumboNode*> childrenNodeList = getChildrenNodeList(node);
    for(int i=0; i<childrenNodeList.size();i++)
    {
        if( childrenNodeList.at(i)->v.element.tag == tagType ){
            return childrenNodeList.at(i);
        }

    }
}


void Data::activeTab(int i,int msg)
{
    if( i==1 ) {

    }
    else if( i==2 ) {

    }
    else if( i==3 ) {

    }
    else if( i==4) {

    }



}

void Data::activeTab(int i, QString msg)
{
    if( i==2) {
       //激活第二个tab，根据url找到营业部对应名称 (msg即为url)
       tabWidget->setCurrentIndex(1);
       tabTwo->currentPage = "1";
       tabTwo->currentUrl = msg;
       tabTwo->startDownloadYinYeBuHistory(msg);
    } else if( i==6 ) {
        //激活第6个tab，msg为个股代码
        tabWidget->setCurrentIndex(5);
        tabSix->currentStockCode = msg;
        qDebug()<<"currentStockCode"<<tabSix->currentStockCode;
        tabSix->checkButton(6);
    }



}



