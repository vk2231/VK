/********************************************************************************
** Form generated from reading UI file 'addobject.ui'
**
** Created: Sat 1. Dec 12:40:52 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOBJECT_H
#define UI_ADDOBJECT_H

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

class Ui_AddObjectDialog
{
public:
    QGridLayout *gridLayout;
    QLineEdit *objectPath;
    QPushButton *chooseObject;
    QLineEdit *userName;
    QPushButton *chooseUser;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *AddObjectDialog)
    {
        if (AddObjectDialog->objectName().isEmpty())
            AddObjectDialog->setObjectName(QString::fromUtf8("AddObjectDialog"));
        AddObjectDialog->resize(485, 372);
        gridLayout = new QGridLayout(AddObjectDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        objectPath = new QLineEdit(AddObjectDialog);
        objectPath->setObjectName(QString::fromUtf8("objectPath"));

        gridLayout->addWidget(objectPath, 0, 0, 1, 2);

        chooseObject = new QPushButton(AddObjectDialog);
        chooseObject->setObjectName(QString::fromUtf8("chooseObject"));

        gridLayout->addWidget(chooseObject, 0, 2, 1, 1);

        userName = new QLineEdit(AddObjectDialog);
        userName->setObjectName(QString::fromUtf8("userName"));

        gridLayout->addWidget(userName, 1, 0, 1, 2);

        chooseUser = new QPushButton(AddObjectDialog);
        chooseUser->setObjectName(QString::fromUtf8("chooseUser"));

        gridLayout->addWidget(chooseUser, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(213, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        ok = new QPushButton(AddObjectDialog);
        ok->setObjectName(QString::fromUtf8("ok"));

        gridLayout->addWidget(ok, 2, 1, 1, 1);

        cancel = new QPushButton(AddObjectDialog);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        gridLayout->addWidget(cancel, 2, 2, 1, 1);


        retranslateUi(AddObjectDialog);
        QObject::connect(cancel, SIGNAL(clicked()), AddObjectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddObjectDialog);
    } // setupUi

    void retranslateUi(QDialog *AddObjectDialog)
    {
        AddObjectDialog->setWindowTitle(QApplication::translate("AddObjectDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        chooseObject->setText(QApplication::translate("AddObjectDialog", "Choose Object", 0, QApplication::UnicodeUTF8));
        chooseUser->setText(QApplication::translate("AddObjectDialog", "Choose User", 0, QApplication::UnicodeUTF8));
        ok->setText(QApplication::translate("AddObjectDialog", "OK", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("AddObjectDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddObjectDialog: public Ui_AddObjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOBJECT_H
