#ifndef EDITUSERS_H
#define EDITUSERS_H

#include <QDialog>

namespace Ui {
    class EditUsers;
}

class EditUsers : public QDialog
{
    Q_OBJECT

public:
    explicit EditUsers(QWidget *parent = 0);
    ~EditUsers();

private:
    Ui::EditUsers *ui;
};

#endif // EDITUSERS_H
