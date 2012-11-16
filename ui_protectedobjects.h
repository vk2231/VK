/********************************************************************************
** Form generated from reading UI file 'protectedobjects.ui'
**
** Created: Thu 15. Nov 14:58:25 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTECTEDOBJECTS_H
#define UI_PROTECTEDOBJECTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProtectedObjects
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QListView *listView;
    QPushButton *pushButton_4;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_2;

    void setupUi(QDialog *ProtectedObjects)
    {
        if (ProtectedObjects->objectName().isEmpty())
            ProtectedObjects->setObjectName(QString::fromUtf8("ProtectedObjects"));
        ProtectedObjects->resize(400, 300);
        verticalLayout = new QVBoxLayout(ProtectedObjects);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(ProtectedObjects);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        listView = new QListView(tab);
        listView->setObjectName(QString::fromUtf8("listView"));

        gridLayout->addWidget(listView, 0, 0, 6, 1);

        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 5, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(ProtectedObjects);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ProtectedObjects);
    } // setupUi

    void retranslateUi(QDialog *ProtectedObjects)
    {
        ProtectedObjects->setWindowTitle(QApplication::translate("ProtectedObjects", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ProtectedObjects", "New", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ProtectedObjects", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ProtectedObjects", "Edit", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("ProtectedObjects", "Back", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ProtectedObjects", "Discs", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ProtectedObjects", "Folders", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("ProtectedObjects", "Secret Files", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ProtectedObjects", "Programms", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProtectedObjects: public Ui_ProtectedObjects {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTECTEDOBJECTS_H
