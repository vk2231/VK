#include "editusers.h"
#include "ui_editusers.h"
#include "newfile.h"
#include <QDir>
#include <QFile>
EditUsers::EditUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditUsers)
{
    ui->setupUi(this);
    name ="";
    editUser = new EditUser(this);
    QDir myDir("users/");
    QStringList Filter;
    Filter << "*.us";
    QStringList filesList = myDir.entryList(Filter, QDir::Files);
    QStringList::const_iterator it;
    QString name;
    for (it = filesList.constBegin(); it != filesList.constEnd(); ++it){
        name = (*it);
        ui->listWidget->addItem(name.replace(".us",""));
    }
    addUser = new NewFile(this);
    addUser->setModal( true );
}

EditUsers::~EditUsers()
{
    delete ui;
}



void EditUsers::on_pushButton_clicked()
{
    addUser->show();
    QString name = addUser->getName();
    if (name=="")
        return;
    for(int i=0;i<ui->listWidget->count(); ++i){
        if (ui->listWidget->item(i)->text() == name)
            return;
    }
    ui->listWidget->addItem(name);
    QFile f1( "users/"+name+".us" );
    f1.open(QIODevice::WriteOnly);
    User us;
    us.name = name;
    us.pass = "1234";
    us.group_id =  0;
    us.secret_level = 0;
    us.new_file_access = 0;
    us.new_folder_access = 0;
    us.file.clear();
    us.folder.clear();
    us.disc.clear();
    us.prog.clear();
    us.saveToFile();
}

void EditUsers::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    User us;
    us.loadFromFile("users/"+ item->text() +".us");
    editUser->initWindow(us);
    editUser->show();
}

void EditUsers::on_pushButton_2_clicked()
{
    if (name == "")
       return;
    int i=0;
    bool finish = false;
    QListWidgetItem *item;
    while(!finish){
        item =  ui->listWidget->item(i);
        if(item->text() == name){
            delete item;
            QFile Usfile("users/"+ name + ".us");
            if(Usfile.exists())
                Usfile.remove();
            finish = true;
        }
        ++i;
    }
    name="";
}

void EditUsers::on_listWidget_itemClicked(QListWidgetItem *item)
{
    name = item->text();
}
