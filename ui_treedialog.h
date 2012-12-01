/********************************************************************************
** Form generated from reading UI file 'treedialog.ui'
**
** Created: Sat 1. Dec 12:13:00 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEDIALOG_H
#define UI_TREEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_TreeDialog
{
public:
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QSpacerItem *horizontalSpacer;
    QPushButton *chooseFromTree;

    void setupUi(QDialog *TreeDialog)
    {
        if (TreeDialog->objectName().isEmpty())
            TreeDialog->setObjectName(QString::fromUtf8("TreeDialog"));
        TreeDialog->resize(485, 372);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TreeDialog->sizePolicy().hasHeightForWidth());
        TreeDialog->setSizePolicy(sizePolicy);
        TreeDialog->setMaximumSize(QSize(485, 372));
        gridLayout = new QGridLayout(TreeDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeView = new QTreeView(TreeDialog);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setMaximumSize(QSize(471, 331));

        gridLayout->addWidget(treeView, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(383, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        chooseFromTree = new QPushButton(TreeDialog);
        chooseFromTree->setObjectName(QString::fromUtf8("chooseFromTree"));

        gridLayout->addWidget(chooseFromTree, 1, 1, 1, 1);


        retranslateUi(TreeDialog);

        QMetaObject::connectSlotsByName(TreeDialog);
    } // setupUi

    void retranslateUi(QDialog *TreeDialog)
    {
        TreeDialog->setWindowTitle(QApplication::translate("TreeDialog", "Select Object", 0, QApplication::UnicodeUTF8));
        chooseFromTree->setText(QApplication::translate("TreeDialog", "Choose", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TreeDialog: public Ui_TreeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEDIALOG_H
