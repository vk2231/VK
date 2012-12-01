#ifndef PROTECTEDOBJECTS_H
#define PROTECTEDOBJECTS_H

#include <QDialog>

#include "ui_addobject.h"
#include "ui_treedialog.h"
#include "ui_userslist.h"
#include <QFileSystemModel>

namespace Ui {
    class ProtectedObjects;
}

class ProtectedObjects : public QDialog
{
    Q_OBJECT

public:
    explicit ProtectedObjects(QWidget *parent = 0);
    ~ProtectedObjects();

private slots:
    void on_pushButton_clicked();
    void on_chooseUser_clicked();
    void on_ok_clicked();
    void setObjectPath();
    void on_chooseObject_clicked();
    void on_treeView_doubleClicked(QModelIndex index);
    void setUser();

private:
    Ui::ProtectedObjects *ui;
    QDialog *addObjectDialogUi;
    QDialog *treeDialogUi;
    QDialog *usersListDialogUi;
    Ui::AddObjectDialog addObjectDialog;
    Ui::TreeDialog treeDialog;
    Ui::UsersListDialog usersListDialog;
    QFileSystemModel* fileModel;
};

#endif // PROTECTEDOBJECTS_H
