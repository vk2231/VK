#ifndef EDITUSERS_H
#define EDITUSERS_H

#include <QDialog>
#include <QListWidgetItem>
#include "edituser.h"
#include "newfile.h"

namespace Ui {
    class EditUsers;
}

class EditUsers : public QDialog
{
    Q_OBJECT

public:
    EditUser* editUser;
    explicit EditUsers(QWidget *parent = 0);
    ~EditUsers();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::EditUsers *ui;
    QString name;
    NewFile* addUser;
signals:
    void log(QString);
};

#endif // EDITUSERS_H
