/********************************************************************************
** Form generated from reading UI file 'classtabfive.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSTABFIVE_H
#define UI_CLASSTABFIVE_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassTabFive
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
    QWebView *webView;

    void setupUi(QWidget *ClassTabFive)
    {
        if (ClassTabFive->objectName().isEmpty())
            ClassTabFive->setObjectName(QStringLiteral("ClassTabFive"));
        ClassTabFive->resize(1000, 600);
        layoutWidget = new QWidget(ClassTabFive);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1102, 633));
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
        webView = new QWebView(layoutWidget);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        horizontalLayout_4->addWidget(webView);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout);

        layoutWidget->raise();
        tableWidget->raise();

        retranslateUi(ClassTabFive);

        QMetaObject::connectSlotsByName(ClassTabFive);
    } // setupUi

    void retranslateUi(QWidget *ClassTabFive)
    {
        ClassTabFive->setWindowTitle(QApplication::translate("ClassTabFive", "Form", 0));
        label->setText(QApplication::translate("ClassTabFive", "asdas ", 0));
    } // retranslateUi

};

namespace Ui {
    class ClassTabFive: public Ui_ClassTabFive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSTABFIVE_H
