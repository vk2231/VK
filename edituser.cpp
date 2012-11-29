#include "edituser.h"
#include "ui_edituser.h"

EditUser::EditUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditUser)
{
    ui->setupUi(this);
    ui->comboBox->addItem("0");
    ui->comboBox->addItem("1");
    ui->comboBox->addItem("2");

    ui->comboBox_2->addItem("0");
    ui->comboBox_2->addItem("1");
    ui->comboBox_2->addItem("2");

    addRes = new NewFile(this);
    addRes->setModal( true );
}

void EditUser::initWindow (User us){
    user = us;
    ui->label->setText(us.name);
    ui->lineEdit_2->setText(us.pass);
    ui->lineEdit_3->setText(QString::number(us.group_id));
    ui->lineEdit_4->setText(QString::number(us.secret_level));
    ui->comboBox->setCurrentIndex(us.new_file_access);
    ui->comboBox_2->setCurrentIndex(us.new_folder_access);

    ui->listWidget->clear();
    ui->listWidget->addItems(us.file);

    ui->listWidget_2->clear();
    ui->listWidget_2->addItems(us.folder);

    ui->listWidget_3->clear();
    ui->listWidget_3->addItems(us.disc);

    ui->listWidget_4->clear();
    ui->listWidget_4->addItems(us.prog);

}

EditUser::~EditUser()
{
    delete ui;
}

void EditUser::on_pushButton_2_clicked()
{
    close();
}

void EditUser::on_pushButton_clicked()
{
    user.name = ui->label->text();
    user.pass = ui->lineEdit_2->text();
    user.group_id = ui->lineEdit_3->text().toInt();
    user.secret_level = ui->lineEdit_4->text().toInt();
    user.new_file_access = ui->comboBox->currentIndex();
    user.new_folder_access = ui->comboBox_2->currentIndex();

    user.file.clear();
    for(int i = 0; i <  ui->listWidget->count () ; ++i)
         user.file.push_back( ui->listWidget->item(i)->text());

    user.folder.clear();
    for(int i = 0; i <  ui->listWidget_2->count () ; ++i)
         user.folder.push_back( ui->listWidget_2->item(i)->text());


    user.disc.clear();
    for(int i = 0; i <  ui->listWidget_3->count () ; ++i)
         user.disc.push_back( ui->listWidget_3->item(i)->text());

    user.prog.clear();
    for(int i = 0; i <  ui->listWidget_4->count () ; ++i)
         user.prog.push_back( ui->listWidget_4->item(i)->text());

    user.saveToFile();
    close();
}

//add file
void EditUser::on_pushButton_4_clicked()
{
    addRes->show();
    QString name = addRes->getName();
    if (name=="")
        return;
    for(int i=0;i<ui->listWidget->count(); ++i){
        if (ui->listWidget->item(i)->text() == name)
            return;
    }
    ui->listWidget->addItem(name);
}

void EditUser::on_listWidget_itemClicked(QListWidgetItem *item)
{
    filename = item->text();
}

void EditUser::on_pushButton_5_clicked()
{
    if (filename == "")
       return;
    int i=0;
    bool finish = false;
    QListWidgetItem *item;
    while(!finish){
        item =  ui->listWidget->item(i);
        if(item->text() == filename){
            delete item;
            finish = true;
        }
        ++i;
    }
    filename="";
}

void EditUser::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    folname = item->text();
}

void EditUser::on_pushButton_6_clicked()
{
    if (folname == "")
        return;
     int i=0;
     bool finish = false;
     QListWidgetItem *item;
     while(!finish){
         item =  ui->listWidget_2->item(i);
         if(item->text() == folname){
             delete item;
             finish = true;
         }
         ++i;
     }
     folname="";
}
//add folder
void EditUser::on_pushButton_7_clicked()
{
    addRes->show();
    QString name = addRes->getName();
    if (name=="")
        return;
    for(int i=0;i<ui->listWidget_2->count(); ++i){
        if (ui->listWidget_2->item(i)->text() == name)
            return;
    }
    ui->listWidget_2->addItem(name);
}

void EditUser::on_listWidget_3_itemClicked(QListWidgetItem *item)
{
    discname = item->text();
}

void EditUser::on_pushButton_9_clicked()
{
    if (discname == "")
        return;
     int i=0;
     bool finish = false;
     QListWidgetItem *item;
     while(!finish){
         item =  ui->listWidget_3->item(i);
         if(item->text() == discname){
             delete item;
             finish = true;
         }
         ++i;
     }
     discname="";
 }

//add disc
void EditUser::on_pushButton_8_clicked()
{
    addRes->show();
    QString name = addRes->getName();
    if (name=="")
        return;
    for(int i=0;i<ui->listWidget_3->count(); ++i){
        if (ui->listWidget_3->item(i)->text() == name)
            return;
    }
    ui->listWidget_3->addItem(name);
}

void EditUser::on_listWidget_4_itemClicked(QListWidgetItem *item)
{
    progname = item->text();
}

void EditUser::on_pushButton_11_clicked()
{
    if (progname == "")
        return;
     int i=0;
     bool finish = false;
     QListWidgetItem *item;
     while(!finish){
         item =  ui->listWidget_4->item(i);
         if(item->text() == progname){
             delete item;
             finish = true;
         }
         ++i;
     }
     progname="";
}

//add prog
void EditUser::on_pushButton_10_clicked()
{
    addRes->show();
    QString name = addRes->getName();
    if (name=="")
        return;
    for(int i=0;i<ui->listWidget_4->count(); ++i){
        if (ui->listWidget_4->item(i)->text() == name)
            return;
    }
    ui->listWidget_4->addItem(name);
}
