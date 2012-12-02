/********************************************************************************
** Form generated from reading UI file 'editusers.ui'
**
** Created: Sun 2. Dec 11:10:22 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITUSERS_H
#define UI_EDITUSERS_H

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

class Ui_EditUsers
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *EditUsers)
    {
        if (EditUsers->objectName().isEmpty())
            EditUsers->setObjectName(QString::fromUtf8("EditUsers"));
        EditUsers->resize(400, 300);
        gridLayout = new QGridLayout(EditUsers);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(EditUsers);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(EditUsers);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        listWidget = new QListWidget(EditUsers);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 3, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);


        retranslateUi(EditUsers);

        QMetaObject::connectSlotsByName(EditUsers);
    } // setupUi

    void retranslateUi(QDialog *EditUsers)
    {
        EditUsers->setWindowTitle(QApplication::translate("EditUsers", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("EditUsers", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("EditUsers", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditUsers: public Ui_EditUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITUSERS_H
