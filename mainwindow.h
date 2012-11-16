#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editusers.h"
#include "log.h"
#include "monitor.h"
#include "newfile.h"
#include "protectedobjects.h"
#include "textedit.h"
#include "ident.h"
#include <QModelIndex>
#include <QFileSystemModel>
#include "user.h"


namespace Ui {
    class MainWindow;
}

enum ActionFS{ delFile, delFolder, openFolder, readFile, writeFile, runProg };

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void treeClicked( QModelIndex );                                                    //Гайнулин
    void login(QString name);                                                           //Баранов
    void createNewFile();                                                               //Гайнулин
    void createNewFolder();                                                             //Гайнулин
    void deleteFile();                                                                  //Гайнулин
    bool isLegal(QString path, ActionFS action);                                        //Березин
    int typeFS(QString path);                                                           //Березин
    void up();
    void logout();
private:
    User user;                                                                          //Агабабян
    Ui::MainWindow *ui;
    Ident* ident;                                                                       //Агабабян
    EditUsers* editUsers;                                                               //Агабабян
    Log* log;                                                                           //Ядгаров
    Monitor* monitor;                                                                   //Баранов, Мокроусов
    NewFile* newFile;
    ProtectedObjects* protectedObjects;                                                 //Агабабян
    TextEdit* textEdit;                                                                 //Бабаков
    QFileSystemModel* fileModel;
};

#endif // MAINWINDOW_H
