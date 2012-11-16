/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 15. Nov 14:58:25 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogout;
    QAction *actionExit;
    QAction *actionEditUsers;
    QAction *actionLog;
    QAction *actionMonitor;
    QAction *actionProtectedObjects;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QPushButton *newFolderButton;
    QPushButton *newFileButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QPushButton *upButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAdministration;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(604, 458);
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QString::fromUtf8("actionLogout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionEditUsers = new QAction(MainWindow);
        actionEditUsers->setObjectName(QString::fromUtf8("actionEditUsers"));
        actionLog = new QAction(MainWindow);
        actionLog->setObjectName(QString::fromUtf8("actionLog"));
        actionMonitor = new QAction(MainWindow);
        actionMonitor->setObjectName(QString::fromUtf8("actionMonitor"));
        actionProtectedObjects = new QAction(MainWindow);
        actionProtectedObjects->setObjectName(QString::fromUtf8("actionProtectedObjects"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        gridLayout->addWidget(treeView, 0, 1, 5, 1);

        newFolderButton = new QPushButton(centralwidget);
        newFolderButton->setObjectName(QString::fromUtf8("newFolderButton"));

        gridLayout->addWidget(newFolderButton, 1, 3, 1, 1);

        newFileButton = new QPushButton(centralwidget);
        newFileButton->setObjectName(QString::fromUtf8("newFileButton"));

        gridLayout->addWidget(newFileButton, 2, 3, 1, 1);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 3, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 3, 1, 1);

        upButton = new QPushButton(centralwidget);
        upButton->setObjectName(QString::fromUtf8("upButton"));

        gridLayout->addWidget(upButton, 0, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 604, 18));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAdministration = new QMenu(menubar);
        menuAdministration->setObjectName(QString::fromUtf8("menuAdministration"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAdministration->menuAction());
        menuFile->addAction(actionLogout);
        menuFile->addAction(actionExit);
        menuAdministration->addAction(actionEditUsers);
        menuAdministration->addAction(actionLog);
        menuAdministration->addAction(actionMonitor);
        menuAdministration->addAction(actionProtectedObjects);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionLogout->setText(QApplication::translate("MainWindow", "Logout", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionEditUsers->setText(QApplication::translate("MainWindow", "Edit users", 0, QApplication::UnicodeUTF8));
        actionLog->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        actionMonitor->setText(QApplication::translate("MainWindow", "Controled files", 0, QApplication::UnicodeUTF8));
        actionProtectedObjects->setText(QApplication::translate("MainWindow", "Edit protected objects", 0, QApplication::UnicodeUTF8));
        newFolderButton->setText(QApplication::translate("MainWindow", "New Folder", 0, QApplication::UnicodeUTF8));
        newFileButton->setText(QApplication::translate("MainWindow", "New File", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete selected", 0, QApplication::UnicodeUTF8));
        upButton->setText(QApplication::translate("MainWindow", "Up", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuAdministration->setTitle(QApplication::translate("MainWindow", "Administration if admin", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
