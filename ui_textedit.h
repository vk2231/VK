/********************************************************************************
** Form generated from reading UI file 'textedit.ui'
**
** Created: Fri 2. Nov 14:12:39 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDIT_H
#define UI_TEXTEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextEdit
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TextEdit)
    {
        if (TextEdit->objectName().isEmpty())
            TextEdit->setObjectName(QString::fromUtf8("TextEdit"));
        TextEdit->resize(800, 600);
        actionNew = new QAction(TextEdit);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(TextEdit);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(TextEdit);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionSave = new QAction(TextEdit);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(TextEdit);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionExit = new QAction(TextEdit);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(TextEdit);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 10, 781, 481));
        TextEdit->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TextEdit);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 18));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        TextEdit->setMenuBar(menubar);
        statusbar = new QStatusBar(TextEdit);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TextEdit->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionExit);

        retranslateUi(TextEdit);

        QMetaObject::connectSlotsByName(TextEdit);
    } // setupUi

    void retranslateUi(QMainWindow *TextEdit)
    {
        TextEdit->setWindowTitle(QApplication::translate("TextEdit", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("TextEdit", "New", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("TextEdit", "Open", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("TextEdit", "Close", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("TextEdit", "Save", 0, QApplication::UnicodeUTF8));
        actionSave_as->setText(QApplication::translate("TextEdit", "Save as", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("TextEdit", "Exit", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QApplication::translate("TextEdit", "Here the text will be", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("TextEdit", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TextEdit: public Ui_TextEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDIT_H
