#ifndef CLASSTABFIVE_H
#define CLASSTABFIVE_H

#include <QWidget>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class ClassTabFive;
}

class ClassTabFive : public QWidget
{
    Q_OBJECT
    
public:
    explicit ClassTabFive(QWidget *parent = 0);
    ~ClassTabFive();
    
private:
    Ui::ClassTabFive *ui;
};

#endif // CLASSTABFIVE_H
