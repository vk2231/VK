#include "ident.h"
#include "ui_ident.h"
#include "user.h"
#include <QFile>

QString AdLogin = "admin";
Ident::Ident(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ident)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit ::Password);
    ui->lineEdit_2->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);
    connect( ui->buttonBox, SIGNAL(rejected()), parent, SLOT(close()) );
    connect( ui->buttonBox,SIGNAL(accepted()), this, SLOT(pasEntered()) );
}

Ident::~Ident()
{
    delete ui;
}

void Ident::pasEntered(){
    QString lg = ui->loginEdit->text();
    QString pass = ui->lineEdit_2->text();
    QString line;
    if (lg=="" || pass=="")
        return;
    if (lg == AdLogin){
        QFile Adfile("admin.ad");
        if (!Adfile.open(QIODevice::ReadOnly))
            return ;
        line=Adfile.readLine();
        if(!line.isEmpty()){
            if (line.startsWith("pass")){
                line = line.replace( "pass=", "");
                //pass=gethash(pass)
                if (line == pass){
                    Adfile.close();
                    emit login(ui->loginEdit->text());
                    this->close();
                }else{
                    ui->label_3->setText("incorrect login or password");
                    emit log(QString("password"));
                }
            }
        }
    }
    else{
        User us;
        us.loadFromFile("users/"+lg+".us");
        switch(us.getLastError()){
            case 1: emit log("Unknown user(" + lg + ") try to access");
                ui->label_3->setText("incorrect login or password");
                return;
            case 2: emit log("Error with user(" + lg +") file, mismatch params");
                return;
            case 3: emit log("Error with user(" + lg +") file, open file");
                 return;
            default: break;
        }
        if (us.pass == pass){
            emit login(ui->loginEdit->text());
            this->close();
        }else{
            ui->label_3->setText("incorrect password");
            emit log("incorrect login or password");
        }
    }
}

void Ident::clear(){
    ui->loginEdit->clear();
    ui->lineEdit_2->clear();
}
