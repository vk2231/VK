/********************************************************************************
** Form generated from reading UI file 'newfile.ui'
**
** Created: Thu 29. Nov 22:44:49 2012
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_NewFile
{
public:
    QGridLayout *gridLayout;
    QLineEdit *nameEdit;
    QPushButton *cancelButton;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *NewFile)
    {
        if (NewFile->objectName().isEmpty())
            NewFile->setObjectName(QString::fromUtf8("NewFile"));
        NewFile->resize(271, 69);
        gridLayout = new QGridLayout(NewFile);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nameEdit = new QLineEdit(NewFile);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 0, 1, 3);

        cancelButton = new QPushButton(NewFile);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout->addWidget(cancelButton, 1, 1, 1, 1);

        okButton = new QPushButton(NewFile);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        gridLayout->addWidget(okButton, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);


        retranslateUi(NewFile);

        QMetaObject::connectSlotsByName(NewFile);
    } // setupUi

    void retranslateUi(QDialog *NewFile)
    {
        NewFile->setWindowTitle(QApplication::translate("NewFile", "Dialog", 0, QApplication::UnicodeUTF8));
        nameEdit->setText(QApplication::translate("NewFile", "Name", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("NewFile", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("NewFile", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewFile: public Ui_NewFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFILE_H
