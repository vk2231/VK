#include "editusers.h"
#include "ui_editusers.h"

EditUsers::EditUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditUsers)
{
    ui->setupUi(this);
}

EditUsers::~EditUsers()
{
    delete ui;
}
