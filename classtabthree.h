#ifndef CLASSTABTHREE_H
#define CLASSTABTHREE_H

#include <QWidget>

namespace Ui {
class ClassTabThree;
}

class ClassTabThree : public QWidget
{
    Q_OBJECT
    
public:
    explicit ClassTabThree(QWidget *parent = 0);
    ~ClassTabThree();
    
private:
    Ui::ClassTabThree *ui;
};

#endif // CLASSTABTHREE_H
