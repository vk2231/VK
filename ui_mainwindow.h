/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 2. Nov 14:12:39 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionLogout;
    QAction *actionExit;
    QAction *actionChange_password;
    QAction *actionExit_2;
    QAction *actionEdit_users;
    QAction *actionView_log;
    QAction *actionEdit_controled_filed;
    QAction *actionEdit_mandats;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTreeView *treeView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAdministration;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(604, 458);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QString::fromUtf8("actionLogout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionChange_password = new QAction(MainWindow);
        actionChange_password->setObjectName(QString::fromUtf8("actionChange_password"));
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName(QString::fromUtf8("actionExit_2"));
        actionEdit_users = new QAction(MainWindow);
        actionEdit_users->setObjectName(QString::fromUtf8("actionEdit_users"));
        actionView_log = new QAction(MainWindow);
        actionView_log->setObjectName(QString::fromUtf8("actionView_log"));
        actionEdit_controled_filed = new QAction(MainWindow);
        actionEdit_controled_filed->setObjectName(QString::fromUtf8("actionEdit_controled_filed"));
        actionEdit_mandats = new QAction(MainWindow);
        actionEdit_mandats->setObjectName(QString::fromUtf8("actionEdit_mandats"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(480, 40, 91, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(484, 80, 81, 23));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 130, 91, 31));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 0, 461, 421));
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
        menuFile->addAction(actionNew);
        menuFile->addAction(actionLogout);
        menuFile->addAction(actionExit);
        menuFile->addAction(actionExit_2);
        menuAdministration->addAction(actionEdit_users);
        menuAdministration->addAction(actionView_log);
        menuAdministration->addAction(actionEdit_controled_filed);
        menuAdministration->addAction(actionEdit_mandats);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New Folder", 0, QApplication::UnicodeUTF8));
        actionLogout->setText(QApplication::translate("MainWindow", "New File", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Logout", 0, QApplication::UnicodeUTF8));
        actionChange_password->setText(QApplication::translate("MainWindow", "Change password", 0, QApplication::UnicodeUTF8));
        actionExit_2->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionEdit_users->setText(QApplication::translate("MainWindow", "Edit users", 0, QApplication::UnicodeUTF8));
        actionView_log->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        actionEdit_controled_filed->setText(QApplication::translate("MainWindow", "Controled files", 0, QApplication::UnicodeUTF8));
        actionEdit_mandats->setText(QApplication::translate("MainWindow", "Edit protected objects", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "New Folder", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "New File", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Delete selected", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuAdministration->setTitle(QApplication::translate("MainWindow", "Administration if admin", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
