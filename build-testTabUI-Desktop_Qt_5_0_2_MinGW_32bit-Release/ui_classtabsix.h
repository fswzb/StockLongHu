/********************************************************************************
** Form generated from reading UI file 'classtabsix.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSTABSIX_H
#define UI_CLASSTABSIX_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassTabSix
{
public:
    QWebView *webView;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QWidget *ClassTabSix)
    {
        if (ClassTabSix->objectName().isEmpty())
            ClassTabSix->setObjectName(QStringLiteral("ClassTabSix"));
        ClassTabSix->resize(780, 464);
        webView = new QWebView(ClassTabSix);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(120, 10, 641, 431));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));
        widget = new QWidget(ClassTabSix);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 81, 77, 199));
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

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setCheckable(true);

        verticalLayout->addWidget(pushButton_7);


        retranslateUi(ClassTabSix);

        QMetaObject::connectSlotsByName(ClassTabSix);
    } // setupUi

    void retranslateUi(QWidget *ClassTabSix)
    {
        ClassTabSix->setWindowTitle(QApplication::translate("ClassTabSix", "Form", 0));
        pushButton_1->setText(QApplication::translate("ClassTabSix", "\344\272\221\350\264\242\347\273\217", 0));
        pushButton_2->setText(QApplication::translate("ClassTabSix", "\344\270\234\346\226\271\350\264\242\345\257\214", 0));
        pushButton_3->setText(QApplication::translate("ClassTabSix", "\346\220\234\347\213\220\350\264\242\347\273\217", 0));
        pushButton_4->setText(QApplication::translate("ClassTabSix", "\347\275\221\346\230\223\350\264\242\347\273\217", 0));
        pushButton_5->setText(QApplication::translate("ClassTabSix", "\350\257\201\345\210\270\344\271\213\346\230\237", 0));
        pushButton_6->setText(QApplication::translate("ClassTabSix", "\346\226\260\346\265\252\350\241\214\346\203\205", 0));
        pushButton_7->setText(QApplication::translate("ClassTabSix", "\351\276\231\350\231\216\346\246\234\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class ClassTabSix: public Ui_ClassTabSix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSTABSIX_H
