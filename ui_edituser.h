/********************************************************************************
** Form generated from reading UI file 'edituser.ui'
**
** Created: Fri 2. Nov 14:12:39 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditUser
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QListWidget *listWidget;
    QListWidget *listWidget_2;

    void setupUi(QDialog *EditUser)
    {
        if (EditUser->objectName().isEmpty())
            EditUser->setObjectName(QString::fromUtf8("EditUser"));
        EditUser->resize(404, 381);
        pushButton = new QPushButton(EditUser);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 350, 75, 23));
        pushButton_2 = new QPushButton(EditUser);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 350, 75, 23));
        lineEdit = new QLineEdit(EditUser);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 20, 113, 20));
        lineEdit_2 = new QLineEdit(EditUser);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 20, 113, 20));
        pushButton_3 = new QPushButton(EditUser);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 20, 75, 23));
        lineEdit_3 = new QLineEdit(EditUser);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(40, 50, 113, 20));
        lineEdit_4 = new QLineEdit(EditUser);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(200, 50, 113, 20));
        comboBox = new QComboBox(EditUser);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 90, 111, 22));
        comboBox_2 = new QComboBox(EditUser);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(200, 90, 121, 22));
        listWidget = new QListWidget(EditUser);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 130, 141, 192));
        listWidget_2 = new QListWidget(EditUser);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(220, 130, 161, 191));

        retranslateUi(EditUser);

        QMetaObject::connectSlotsByName(EditUser);
    } // setupUi

    void retranslateUi(QDialog *EditUser)
    {
        EditUser->setWindowTitle(QApplication::translate("EditUser", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("EditUser", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("EditUser", "Cancel", 0, QApplication::UnicodeUTF8));
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


        const bool __sortingEnabled1 = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = listWidget_2->item(0);
        ___qlistwidgetitem1->setText(QApplication::translate("EditUser", "Granted Folder access", 0, QApplication::UnicodeUTF8));
        listWidget_2->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class EditUser: public Ui_EditUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITUSER_H
