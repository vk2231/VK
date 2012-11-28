/********************************************************************************
** Form generated from reading UI file 'edituser.ui'
**
** Created: Wed 28. Nov 22:46:26 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITUSER_H
#define UI_EDITUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditUser
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QListWidget *listWidget;
    QListWidget *listWidget4;
    QPushButton *pushButton_2;
    QListWidget *listWidget3;
    QListWidget *listWidget2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_11;
    QPushButton *pushButton;

    void setupUi(QDialog *EditUser)
    {
        if (EditUser->objectName().isEmpty())
            EditUser->setObjectName(QString::fromUtf8("EditUser"));
        EditUser->resize(638, 402);
        gridLayout = new QGridLayout(EditUser);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(EditUser);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(EditUser);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 2, 1, 2);

        pushButton_3 = new QPushButton(EditUser);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 4, 1, 1);

        lineEdit_3 = new QLineEdit(EditUser);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 1, 0, 1, 1);

        lineEdit_4 = new QLineEdit(EditUser);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 1, 2, 1, 2);

        comboBox = new QComboBox(EditUser);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 0, 1, 1);

        comboBox_2 = new QComboBox(EditUser);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 2, 2, 1, 2);

        listWidget = new QListWidget(EditUser);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 3, 0, 2, 1);

        listWidget4 = new QListWidget(EditUser);
        new QListWidgetItem(listWidget4);
        listWidget4->setObjectName(QString::fromUtf8("listWidget4"));

        gridLayout->addWidget(listWidget4, 3, 2, 2, 2);

        pushButton_2 = new QPushButton(EditUser);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 8, 4, 1, 1);

        listWidget3 = new QListWidget(EditUser);
        listWidget3->setObjectName(QString::fromUtf8("listWidget3"));

        gridLayout->addWidget(listWidget3, 6, 0, 2, 1);

        listWidget2 = new QListWidget(EditUser);
        listWidget2->setObjectName(QString::fromUtf8("listWidget2"));

        gridLayout->addWidget(listWidget2, 6, 2, 2, 2);

        pushButton_4 = new QPushButton(EditUser);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 3, 1, 1, 1);

        pushButton_5 = new QPushButton(EditUser);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 4, 1, 1, 1);

        pushButton_8 = new QPushButton(EditUser);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 6, 1, 1, 1);

        pushButton_9 = new QPushButton(EditUser);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 7, 1, 1, 1);

        pushButton_10 = new QPushButton(EditUser);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 6, 4, 1, 1);

        pushButton_7 = new QPushButton(EditUser);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 3, 4, 1, 1);

        pushButton_6 = new QPushButton(EditUser);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 4, 4, 1, 1);

        pushButton_11 = new QPushButton(EditUser);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 7, 4, 1, 1);

        pushButton = new QPushButton(EditUser);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 8, 3, 1, 1);


        retranslateUi(EditUser);

        QMetaObject::connectSlotsByName(EditUser);
    } // setupUi

    void retranslateUi(QDialog *EditUser)
    {
        EditUser->setWindowTitle(QApplication::translate("EditUser", "Editing user N", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("EditUser", "id", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("EditUser", "Set new password", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("EditUser", "Set", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("EditUser", "group", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setText(QApplication::translate("EditUser", "Grif", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("EditUser", "File access label", 0, QApplication::UnicodeUTF8)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("EditUser", "Folder Access label", 0, QApplication::UnicodeUTF8)
        );

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("EditUser", "Granted file access", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = listWidget4->isSortingEnabled();
        listWidget4->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = listWidget4->item(0);
        ___qlistwidgetitem1->setText(QApplication::translate("EditUser", "Granted Folder access", 0, QApplication::UnicodeUTF8));
        listWidget4->setSortingEnabled(__sortingEnabled1);

        pushButton_2->setText(QApplication::translate("EditUser", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("EditUser", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("EditUser", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("EditUser", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("EditUser", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("EditUser", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("EditUser", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("EditUser", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("EditUser", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("EditUser", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditUser: public Ui_EditUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITUSER_H
