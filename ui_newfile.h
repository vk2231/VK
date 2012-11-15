/********************************************************************************
** Form generated from reading UI file 'newfile.ui'
**
** Created: Fri 2. Nov 14:12:39 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFILE_H
#define UI_NEWFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NewFile
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *NewFile)
    {
        if (NewFile->objectName().isEmpty())
            NewFile->setObjectName(QString::fromUtf8("NewFile"));
        NewFile->resize(296, 121);
        lineEdit = new QLineEdit(NewFile);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 20, 231, 20));
        pushButton = new QPushButton(NewFile);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 80, 75, 23));
        pushButton_2 = new QPushButton(NewFile);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 80, 75, 23));

        retranslateUi(NewFile);

        QMetaObject::connectSlotsByName(NewFile);
    } // setupUi

    void retranslateUi(QDialog *NewFile)
    {
        NewFile->setWindowTitle(QApplication::translate("NewFile", "Dialog", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("NewFile", "Name", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("NewFile", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("NewFile", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewFile: public Ui_NewFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFILE_H
