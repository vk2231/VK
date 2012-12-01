/********************************************************************************
** Form generated from reading UI file 'userslist.ui'
**
** Created: Sat 1. Dec 12:25:18 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSLIST_H
#define UI_USERSLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_UsersListDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *choose;
    QListWidget *usersList;

    void setupUi(QDialog *UsersListDialog)
    {
        if (UsersListDialog->objectName().isEmpty())
            UsersListDialog->setObjectName(QString::fromUtf8("UsersListDialog"));
        UsersListDialog->resize(485, 372);
        gridLayout = new QGridLayout(UsersListDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(383, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        choose = new QPushButton(UsersListDialog);
        choose->setObjectName(QString::fromUtf8("choose"));

        gridLayout->addWidget(choose, 2, 1, 1, 1);

        usersList = new QListWidget(UsersListDialog);
        usersList->setObjectName(QString::fromUtf8("usersList"));

        gridLayout->addWidget(usersList, 1, 0, 1, 2);


        retranslateUi(UsersListDialog);

        QMetaObject::connectSlotsByName(UsersListDialog);
    } // setupUi

    void retranslateUi(QDialog *UsersListDialog)
    {
        UsersListDialog->setWindowTitle(QApplication::translate("UsersListDialog", "Select Users", 0, QApplication::UnicodeUTF8));
        choose->setText(QApplication::translate("UsersListDialog", "Choose", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UsersListDialog: public Ui_UsersListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSLIST_H
