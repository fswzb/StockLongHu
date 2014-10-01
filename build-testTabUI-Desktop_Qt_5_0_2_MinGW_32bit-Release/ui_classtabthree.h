/********************************************************************************
** Form generated from reading UI file 'classtabthree.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSTABTHREE_H
#define UI_CLASSTABTHREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassTabThree
{
public:

    void setupUi(QWidget *ClassTabThree)
    {
        if (ClassTabThree->objectName().isEmpty())
            ClassTabThree->setObjectName(QStringLiteral("ClassTabThree"));
        ClassTabThree->resize(400, 300);

        retranslateUi(ClassTabThree);

        QMetaObject::connectSlotsByName(ClassTabThree);
    } // setupUi

    void retranslateUi(QWidget *ClassTabThree)
    {
        ClassTabThree->setWindowTitle(QApplication::translate("ClassTabThree", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ClassTabThree: public Ui_ClassTabThree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSTABTHREE_H
