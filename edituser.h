#ifndef EDITUSER_H
#define EDITUSER_H

#include <QDialog>
#include <QListWidgetItem>
#include "user.h"
#include "newfile.h"
namespace Ui {
    class EditUser;
}

class EditUser : public QDialog
{
    Q_OBJECT

public:
    void initWindow (User us);
    explicit EditUser(QWidget *parent = 0);
    ~EditUser();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_5_clicked();

    void on_listWidget_3_itemClicked(QListWidgetItem *item);

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_listWidget_2_itemClicked(QListWidgetItem *item);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_listWidget_4_itemClicked(QListWidgetItem *item);

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::EditUser *ui;
    NewFile* addRes;
    User user;
    QString filename;
    QString progname;
    QString folname;
    QString discname;
};

#endif // EDITUSER_H
