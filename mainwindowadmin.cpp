#include "mainwindowadmin.h"
#include "ui_mainwindowadmin.h"

MainWindowAdmin::MainWindowAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowAdmin)
{
    ui->setupUi(this);
}

MainWindowAdmin::~MainWindowAdmin()
{
    delete ui;
}
