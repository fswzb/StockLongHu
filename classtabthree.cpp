#include "classtabthree.h"
#include "ui_classtabthree.h"

ClassTabThree::ClassTabThree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassTabThree)
{
    ui->setupUi(this);
}

ClassTabThree::~ClassTabThree()
{
    delete ui;
}



