/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myGraphicsView/myGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonRhomb;
    QPushButton *buttonRectangle;
    QPushButton *buttonRectangleOval;
    QPushButton *buttonParallelepiped;
    QPushButton *buttonHexagon;
    QPushButton *buttonLine;
    QPushButton *buttonArrow;
    QGridLayout *gridLayout_2;
    myGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonSave;
    QPushButton *buttonLoad;
    QPushButton *buttonExport;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(720, 512);
        MainWindow->setMinimumSize(QSize(720, 512));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setFocusPolicy(Qt::NoFocus);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 149, 1056));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        buttonRhomb = new QPushButton(scrollAreaWidgetContents_2);
        buttonRhomb->setObjectName(QString::fromUtf8("buttonRhomb"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonRhomb->sizePolicy().hasHeightForWidth());
        buttonRhomb->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/rhomb.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRhomb->setIcon(icon);
        buttonRhomb->setIconSize(QSize(128, 128));

        verticalLayout->addWidget(buttonRhomb);

        buttonRectangle = new QPushButton(scrollAreaWidgetContents_2);
        buttonRectangle->setObjectName(QString::fromUtf8("buttonRectangle"));
        sizePolicy2.setHeightForWidth(buttonRectangle->sizePolicy().hasHeightForWidth());
        buttonRectangle->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRectangle->setIcon(icon1);
        buttonRectangle->setIconSize(QSize(128, 128));

        verticalLayout->addWidget(buttonRectangle);

        buttonRectangleOval = new QPushButton(scrollAreaWidgetContents_2);
        buttonRectangleOval->setObjectName(QString::fromUtf8("buttonRectangleOval"));
        sizePolicy2.setHeightForWidth(buttonRectangleOval->sizePolicy().hasHeightForWidth());
        buttonRectangleOval->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/rectangle_oval.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRectangleOval->setIcon(icon2);
        buttonRectangleOval->setIconSize(QSize(128, 128));

        verticalLayout->addWidget(buttonRectangleOval);

        buttonParallelepiped = new QPushButton(scrollAreaWidgetContents_2);
        buttonParallelepiped->setObjectName(QString::fromUtf8("buttonParallelepiped"));
        sizePolicy2.setHeightForWidth(buttonParallelepiped->sizePolicy().hasHeightForWidth());
        buttonParallelepiped->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/parallelepiped.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonParallelepiped->setIcon(icon3);
        buttonParallelepiped->setIconSize(QSize(128, 128));

        verticalLayout->addWidget(buttonParallelepiped);

        buttonHexagon = new QPushButton(scrollAreaWidgetContents_2);
        buttonHexagon->setObjectName(QString::fromUtf8("buttonHexagon"));
        sizePolicy2.setHeightForWidth(buttonHexagon->sizePolicy().hasHeightForWidth());
        buttonHexagon->setSizePolicy(sizePolicy2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/hexagon.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonHexagon->setIcon(icon4);
        buttonHexagon->setIconSize(QSize(128, 128));

        verticalLayout->addWidget(buttonHexagon);

        buttonLine = new QPushButton(scrollAreaWidgetContents_2);
        buttonLine->setObjectName(QString::fromUtf8("buttonLine"));
        sizePolicy2.setHeightForWidth(buttonLine->sizePolicy().hasHeightForWidth());
        buttonLine->setSizePolicy(sizePolicy2);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonLine->setIcon(icon5);
        buttonLine->setIconSize(QSize(128, 128));

        verticalLayout->addWidget(buttonLine);

        buttonArrow = new QPushButton(scrollAreaWidgetContents_2);
        buttonArrow->setObjectName(QString::fromUtf8("buttonArrow"));
        sizePolicy2.setHeightForWidth(buttonArrow->sizePolicy().hasHeightForWidth());
        buttonArrow->setSizePolicy(sizePolicy2);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonArrow->setIcon(icon6);
        buttonArrow->setIconSize(QSize(128, 128));

        verticalLayout->addWidget(buttonArrow);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView = new myGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(256, 256));

        gridLayout_2->addWidget(graphicsView, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonSave = new QPushButton(centralwidget);
        buttonSave->setObjectName(QString::fromUtf8("buttonSave"));

        horizontalLayout->addWidget(buttonSave);

        buttonLoad = new QPushButton(centralwidget);
        buttonLoad->setObjectName(QString::fromUtf8("buttonLoad"));

        horizontalLayout->addWidget(buttonLoad);

        buttonExport = new QPushButton(centralwidget);
        buttonExport->setObjectName(QString::fromUtf8("buttonExport"));

        horizontalLayout->addWidget(buttonExport);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Editor of infological schemes", nullptr));
        buttonRhomb->setText(QString());
        buttonRectangle->setText(QString());
        buttonRectangleOval->setText(QString());
        buttonParallelepiped->setText(QString());
        buttonHexagon->setText(QString());
        buttonLine->setText(QString());
        buttonArrow->setText(QString());
        buttonSave->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        buttonLoad->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        buttonExport->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
