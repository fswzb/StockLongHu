/********************************************************************************
** Form generated from reading UI file 'webviewwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBVIEWWINDOW_H
#define UI_WEBVIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebViewWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QMainWindow *WebViewWindow)
    {
        if (WebViewWindow->objectName().isEmpty())
            WebViewWindow->setObjectName(QStringLiteral("WebViewWindow"));
        WebViewWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WebViewWindow->sizePolicy().hasHeightForWidth());
        WebViewWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(WebViewWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setMaximumSize(QSize(800, 16777215));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 70, 77, 170));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_1 = new QPushButton(widget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setCheckable(true);

        verticalLayout->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setCheckable(true);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setCheckable(true);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setCheckable(true);

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setCheckable(true);

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setCheckable(true);

        verticalLayout->addWidget(pushButton_6);

        WebViewWindow->setCentralWidget(centralwidget);

        retranslateUi(WebViewWindow);

        QMetaObject::connectSlotsByName(WebViewWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WebViewWindow)
    {
        WebViewWindow->setWindowTitle(QApplication::translate("WebViewWindow", "MainWindow", 0));
        pushButton_1->setText(QApplication::translate("WebViewWindow", "\344\272\221\350\264\242\347\273\217", 0));
        pushButton_2->setText(QApplication::translate("WebViewWindow", "\344\270\234\346\226\271\350\264\242\345\257\214", 0));
        pushButton_3->setText(QApplication::translate("WebViewWindow", "\346\220\234\347\213\220\350\264\242\347\273\217", 0));
        pushButton_4->setText(QApplication::translate("WebViewWindow", "\347\275\221\346\230\223\350\264\242\347\273\217", 0));
        pushButton_5->setText(QApplication::translate("WebViewWindow", "\350\257\201\345\210\270\344\271\213\346\230\237", 0));
        pushButton_6->setText(QApplication::translate("WebViewWindow", "\346\226\260\346\265\252\350\241\214\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class WebViewWindow: public Ui_WebViewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBVIEWWINDOW_H
