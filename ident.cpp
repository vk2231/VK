#include "ident.h"
#include "ui_ident.h"

ident::ident(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ident)
{
    ui->setupUi(this);
    connect( ui->pushButton,SIGNAL(clicked()), this, SLOT(ok()) );
}

ident::~ident()
{
    delete ui;
}

void ident::ok(){
    emit go();
    this->close();
}
