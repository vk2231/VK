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
    void treeClicked( QModelIndex );                                                    //��������
    void login(QString name);                                                           //�������
    void createNewFile();                                                               //��������
    void createNewFolder();                                                             //��������
    void deleteFile();                                                                  //��������
    bool isLegal(QString path, ActionFS action);                                        //�������
    int typeFS(QString path);                                                           //�������
    void up();
    void logout();
private:
    User user;                                                                          //��������
    Ui::MainWindow *ui;
    Ident* ident;                                                                       //��������
    EditUsers* editUsers;                                                               //��������
    Log* log;                                                                           //�������
    Monitor* monitor;                                                                   //�������, ���������
    NewFile* newFile;
    ProtectedObjects* protectedObjects;                                                 //��������
    TextEdit* textEdit;                                                                 //�������
    QFileSystemModel* fileModel;
};

#endif // MAINWINDOW_H
