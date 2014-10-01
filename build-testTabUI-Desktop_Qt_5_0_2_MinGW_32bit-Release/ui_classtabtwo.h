/********************************************************************************
** Form generated from reading UI file 'classtabtwo.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSTABTWO_H
#define UI_CLASSTABTWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassTabTwo
{
public:
    QTableWidget *tableWidget_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_1;
    QLabel *label_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QLabel *labelYinYeBuName;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;

    void setupUi(QWidget *ClassTabTwo)
    {
        if (ClassTabTwo->objectName().isEmpty())
            ClassTabTwo->setObjectName(QStringLiteral("ClassTabTwo"));
        ClassTabTwo->resize(1000, 600);
        tableWidget_3 = new QTableWidget(ClassTabTwo);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(700, 70, 301, 189));
        layoutWidget = new QWidget(ClassTabTwo);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(700, 40, 441, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_1 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        labelYinYeBuName = new QLabel(ClassTabTwo);
        labelYinYeBuName->setObjectName(QStringLiteral("labelYinYeBuName"));
        labelYinYeBuName->setGeometry(QRect(700, 0, 301, 41));
        QFont font;
        font.setPointSize(13);
        labelYinYeBuName->setFont(font);
        labelYinYeBuName->setStyleSheet(QStringLiteral("color:#ff0000;"));
        labelYinYeBuName->setAlignment(Qt::AlignCenter);
        scrollArea = new QScrollArea(ClassTabTwo);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(3, 54, 16, 16));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 16, 16));
        scrollArea->setWidget(scrollAreaWidgetContents);
        layoutWidget1 = new QWidget(ClassTabTwo);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 551, 37));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_1 = new QPushButton(layoutWidget1);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(0, 35));
        pushButton_1->setCheckable(true);

        horizontalLayout_2->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 35));
        pushButton_2->setCheckable(true);

        horizontalLayout_2->addWidget(pushButton_2);


        retranslateUi(ClassTabTwo);

        QMetaObject::connectSlotsByName(ClassTabTwo);
    } // setupUi

    void retranslateUi(QWidget *ClassTabTwo)
    {
        ClassTabTwo->setWindowTitle(QApplication::translate("ClassTabTwo", "Form", 0));
        pushButton_3->setText(QApplication::translate("ClassTabTwo", "\350\220\245\344\270\232\351\203\250\345\212\240\345\205\245\350\277\275\350\270\252", 0));
        label_2->setText(QApplication::translate("ClassTabTwo", "\351\200\211\346\213\251\351\241\265\346\225\260\357\274\232", 0));
        pushButton->setText(QApplication::translate("ClassTabTwo", "\350\202\241\347\245\250\345\212\240\345\205\245\350\207\252\351\200\211", 0));
        labelYinYeBuName->setText(QString());
        pushButton_1->setText(QApplication::translate("ClassTabTwo", "\345\275\223\346\227\245\346\264\273\350\267\203", 0));
        pushButton_2->setText(QApplication::translate("ClassTabTwo", "\345\275\223\346\234\210\346\264\273\350\267\203", 0));
    } // retranslateUi

};

namespace Ui {
    class ClassTabTwo: public Ui_ClassTabTwo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSTABTWO_H
