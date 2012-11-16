#include "newfile.h"
#include "ui_newfile.h"

NewFile::NewFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewFile)
{
    ui->setupUi(this);
    connect( ui->okButton, SIGNAL(clicked()), this, SLOT(accept()) );
    connect( ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()) );
}

NewFile::~NewFile()
{
    delete ui;
}

QString NewFile::getName(){
    this->exec();
    this->hide();
    if( this->result() == QDialog::Accepted )
        return ui->nameEdit->text();
    return "";
}
