#include "ident.h"
#include "ui_ident.h"

Ident::Ident(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ident)
{
    ui->setupUi(this);
    connect( ui->buttonBox, SIGNAL(rejected()), parent, SLOT(close()) );
    connect( ui->buttonBox,SIGNAL(accepted()), this, SLOT(pasEntered()) );
}

Ident::~Ident()
{
    delete ui;
}

void Ident::pasEntered(){
    //�������� ���� �����-������
    emit login(ui->loginEdit->text());
}
