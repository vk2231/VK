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
#include "users.h"


namespace Ui {
    class MainWindow;
}

enum ActionFS{ delFile, delFolder, openFolder, readFile, writeFile, runProg,createFolder };
enum TypeFS{directory, programm, file}; //���� ��� ���������. �� ������������

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void treeClicked( QModelIndex );                                                    //��������
    void login(QString name);                                                           //
    void createNewFile();                                                               //��������
    void createNewFolder();                                                             //��������
    void deleteFile();                                                                  //��������
    bool isLegal(QString path, ActionFS action);                                        //�������
    int typeFS(QString path);                                                           //�������
    void up();
    void logout();
private slots:
    void on_treeView_expanded(const QModelIndex &index);

private:
    User user;                                                                          //��������
    Ui::MainWindow *ui;
    Ident* ident;                                                                       //��������
    EditUsers* editUsers;                                                               //��������
    Log* logWindow;                                                                           //�������
    Monitor* monitor;                                                                   //�������, ���������
    NewFile* newFile;
    ProtectedObjects* protectedObjects;                                                 //��������, �������
    TextEdit* textEdit;                                                                 //�������
    QFileSystemModel* fileModel;
    Users * users;
signals:
    void log(QString);
};

#endif // MAINWINDOW_H
