#ifndef EDITUSERS_H
#define EDITUSERS_H

#include <QDialog>
#include "edituser.h"

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

private:
    Ui::EditUsers *ui;
};

#endif // EDITUSERS_H
