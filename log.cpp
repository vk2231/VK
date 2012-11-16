#include "log.h"
#include "ui_log.h"

#include <QDebug>

Log::Log(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log)
{
    ui->setupUi(this);
}

Log::~Log()
{
    delete ui;
}

void Log::log(QString str){
    qDebug() << str;
}
