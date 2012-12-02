#ifndef PROTECTEDOBJECTS_H
#define PROTECTEDOBJECTS_H

#include <QDialog>

#include "ui_addobject.h"
#include "ui_treedialog.h"
//#include "log.h"
#include <QFileSystemModel>
#include <QListWidget>
#include <QStringList>
#include <QSet>
#include <QList>


#define protObjFile "protectedObjects.lst"

namespace Ui {
    class ProtectedObjects;
}

class ProtectedObjects : public QDialog
{
    Q_OBJECT

public:
    explicit ProtectedObjects(QWidget *parent = 0);
    ~ProtectedObjects();

    QStringList protectedObjectsList; //список всех защищаемых путей
    QSet<QString> protectedObjectsSet; //множнство всех защищаемых путей
    //пользуйтесь более удобным для вас QStringList или QSet. Гарантируется поддержание их соответствия
    void toDisk(); //должно вызываться перед закрытием программы
              //TODO придумать правильное место для вставки в общий код.


public slots:
    void addProtectedObject(QString path);//данная функция должна вызываться после IsLegal
                                          //при таких действиях, как добавление секретного файла или папки


private slots:
    //void on_pushButton_clicked();
    //void on_chooseUser_clicked();


    // void on_ok_clicked();
    void setObjectPath();
    void on_chooseObject_clicked();
    void on_treeView_doubleClicked(QModelIndex index);

    void on_addButton_clicked();


    void on_deleteButton_clicked();

private:
    Ui::ProtectedObjects *ui;
    QDialog *addObjectDialogUi;
    QDialog *treeDialogUi;

    //QListWidget *listProtected;
    Ui::AddObjectDialog addObjectDialog;
    Ui::TreeDialog treeDialog;
   // Ui::UsersListDialog usersListDialog;
    QFileSystemModel* fileModel;
    void initWindow();




};

#endif // PROTECTEDOBJECTS_H
