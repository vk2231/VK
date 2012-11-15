/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created: Fri 2. Nov 14:12:39 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Log
{
public:
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Log)
    {
        if (Log->objectName().isEmpty())
            Log->setObjectName(QString::fromUtf8("Log"));
        Log->resize(400, 300);
        plainTextEdit = new QPlainTextEdit(Log);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(30, 10, 261, 281));
        pushButton = new QPushButton(Log);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 40, 75, 23));
        pushButton_2 = new QPushButton(Log);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 240, 75, 23));

        retranslateUi(Log);

        QMetaObject::connectSlotsByName(Log);
    } // setupUi

    void retranslateUi(QDialog *Log)
    {
        Log->setWindowTitle(QApplication::translate("Log", "Dialog", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QApplication::translate("Log", "The log will be shown here", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Log", "Clear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Log", "Back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Log: public Ui_Log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
