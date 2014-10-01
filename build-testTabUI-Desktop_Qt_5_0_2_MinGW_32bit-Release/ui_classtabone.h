/********************************************************************************
** Form generated from reading UI file 'classtabone.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSTABONE_H
#define UI_CLASSTABONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassTabOne
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView1;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QLabel *labelStockNow;

    void setupUi(QWidget *ClassTabOne)
    {
        if (ClassTabOne->objectName().isEmpty())
            ClassTabOne->setObjectName(QStringLiteral("ClassTabOne"));
        ClassTabOne->resize(1200, 600);
        ClassTabOne->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(ClassTabOne);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 60, 325, 194));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableView1 = new QTableView(layoutWidget);
        tableView1->setObjectName(QStringLiteral("tableView1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView1->sizePolicy().hasHeightForWidth());
        tableView1->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(tableView1);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        scrollArea = new QScrollArea(layoutWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 60, 190));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_3->addWidget(scrollArea);

        pushButton_4 = new QPushButton(ClassTabOne);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(270, 10, 75, 41));
        pushButton_3 = new QPushButton(ClassTabOne);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 10, 75, 41));
        dateEdit = new QDateEdit(ClassTabOne);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(90, 10, 171, 41));
        QFont font;
        font.setPointSize(12);
        dateEdit->setFont(font);
        dateEdit->setDateTime(QDateTime(QDate(2014, 12, 31), QTime(0, 0, 0)));
        pushButton = new QPushButton(ClassTabOne);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 10, 75, 41));
        pushButton->setStyleSheet(QStringLiteral(""));
        pushButton_2 = new QPushButton(ClassTabOne);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 10, 75, 41));
        comboBox = new QComboBox(ClassTabOne);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(990, 10, 151, 41));
        comboBox->setMinimumSize(QSize(100, 0));
        QFont font1;
        font1.setPointSize(14);
        comboBox->setFont(font1);
        labelStockNow = new QLabel(ClassTabOne);
        labelStockNow->setObjectName(QStringLiteral("labelStockNow"));
        labelStockNow->setGeometry(QRect(790, 10, 191, 41));
        labelStockNow->setFont(font1);
        labelStockNow->setStyleSheet(QStringLiteral("color:red;"));

        retranslateUi(ClassTabOne);

        QMetaObject::connectSlotsByName(ClassTabOne);
    } // setupUi

    void retranslateUi(QWidget *ClassTabOne)
    {
        ClassTabOne->setWindowTitle(QApplication::translate("ClassTabOne", "Form", 0));
        pushButton_4->setText(QApplication::translate("ClassTabOne", "\345\220\216\344\270\200\346\227\245", 0));
        pushButton_3->setText(QApplication::translate("ClassTabOne", "\345\211\215\344\270\200\346\227\245", 0));
        dateEdit->setDisplayFormat(QApplication::translate("ClassTabOne", "yyyy/M/d ddd", 0));
        pushButton->setText(QApplication::translate("ClassTabOne", "\345\212\240\345\205\245\350\207\252\351\200\211\350\202\241", 0));
        pushButton_2->setText(QApplication::translate("ClassTabOne", "\346\237\245\347\234\213\350\241\214\346\203\205", 0));
        labelStockNow->setText(QApplication::translate("ClassTabOne", "\350\202\241\347\245\250\345\220\215\347\247\260", 0));
    } // retranslateUi

};

namespace Ui {
    class ClassTabOne: public Ui_ClassTabOne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSTABONE_H
