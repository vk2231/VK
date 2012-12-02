/********************************************************************************
** Form generated from reading UI file 'protectedobjects.ui'
**
** Created: Sun 2. Dec 11:10:22 2012
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
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ProtectedObjects
{
public:
    QGridLayout *gridLayout;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QListWidget *listProtected;

    void setupUi(QDialog *ProtectedObjects)
    {
        if (ProtectedObjects->objectName().isEmpty())
            ProtectedObjects->setObjectName(QString::fromUtf8("ProtectedObjects"));
        ProtectedObjects->resize(416, 311);
        gridLayout = new QGridLayout(ProtectedObjects);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        addButton = new QPushButton(ProtectedObjects);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 0, 1, 1, 1);

        deleteButton = new QPushButton(ProtectedObjects);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(72, 226, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        listProtected = new QListWidget(ProtectedObjects);
        listProtected->setObjectName(QString::fromUtf8("listProtected"));

        gridLayout->addWidget(listProtected, 0, 0, 4, 1);


        retranslateUi(ProtectedObjects);

        QMetaObject::connectSlotsByName(ProtectedObjects);
    } // setupUi

    void retranslateUi(QDialog *ProtectedObjects)
    {
        ProtectedObjects->setWindowTitle(QApplication::translate("ProtectedObjects", "Dialog", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("ProtectedObjects", "Add", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("ProtectedObjects", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProtectedObjects: public Ui_ProtectedObjects {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTECTEDOBJECTS_H
