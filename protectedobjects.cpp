#include "protectedobjects.h"
#include "ui_protectedobjects.h"

ProtectedObjects::ProtectedObjects(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProtectedObjects)
{
    ui->setupUi(this);
}

ProtectedObjects::~ProtectedObjects()
{
    delete ui;
}
