/********************************************************************************
** Form generated from reading UI file 'classtabfour.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSTABFOUR_H
#define UI_CLASSTABFOUR_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassTabFour
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *ClassTabFour)
    {
        if (ClassTabFour->objectName().isEmpty())
            ClassTabFour->setObjectName(QStringLiteral("ClassTabFour"));
        ClassTabFour->resize(1000, 600);
        layoutWidget = new QWidget(ClassTabFour);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(2, 10, 444, 194));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(layoutWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout_2->addWidget(tableWidget);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setStyleSheet(QStringLiteral("height:30px;font-size:14px;"));

        horizontalLayout_4->addWidget(comboBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("height:30px;\n"
"line-height:30px;\n"
"font-size:12px;"));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("height:30px;\n"
"line-height:30px;\n"
"font-size:12px;"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QLatin1String("height:30px;\n"
"line-height:30px;\n"
"font-size:12px;"));

        horizontalLayout_3->addWidget(pushButton_3);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        scrollArea = new QScrollArea(layoutWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 357, 113));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(ClassTabFour);

        QMetaObject::connectSlotsByName(ClassTabFour);
    } // setupUi

    void retranslateUi(QWidget *ClassTabFour)
    {
        ClassTabFour->setWindowTitle(QApplication::translate("ClassTabFour", "Form", 0));
        label->setText(QApplication::translate("ClassTabFour", "\351\200\211\346\213\251\345\210\206\346\236\220\346\226\271\345\274\217:", 0));
        pushButton_2->setText(QApplication::translate("ClassTabFour", "\345\274\200\345\247\213\345\210\206\346\236\220", 0));
        pushButton->setText(QApplication::translate("ClassTabFour", "\346\217\220\344\272\244\347\273\223\346\236\234\345\210\260\346\234\215\345\212\241\345\231\250", 0));
        pushButton_3->setText(QApplication::translate("ClassTabFour", "\346\270\205\347\251\272\347\273\223\346\236\234", 0));
    } // retranslateUi

};

namespace Ui {
    class ClassTabFour: public Ui_ClassTabFour {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSTABFOUR_H
