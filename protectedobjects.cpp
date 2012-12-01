#include "protectedobjects.h"
#include "ui_protectedobjects.h"

#include <QFile>
#include <QTextStream>

ProtectedObjects::ProtectedObjects(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProtectedObjects)
{
    ui->setupUi(this);

    addObjectDialogUi = new QDialog(this);
    addObjectDialog.setupUi(addObjectDialogUi);
    setModal(true);


    treeDialogUi = new QDialog(this);
    treeDialog.setupUi(treeDialogUi);
    setModal(true);
    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath( QDir::homePath() );
    fileModel->setReadOnly( false );
    treeDialog.treeView->setModel( fileModel );
    treeDialog.treeView->setItemsExpandable(true);
    treeDialog.treeView->setExpandsOnDoubleClick(false);
    treeDialog.treeView->setEditTriggers(!QAbstractItemView::DoubleClicked);
    treeDialog.treeView->resizeColumnToContents(0);

    usersListDialogUi = new QDialog(this);
    usersListDialog.setupUi(usersListDialogUi);
    setModal(true);
    QFile file("users.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString user;
    while(!in.atEnd()) {
       user = in.readLine();
       QListWidgetItem *item = new QListWidgetItem();
       item->setText(user);
       usersListDialog.usersList->insertItem(1, user);
    }


    connect(treeDialog.chooseFromTree, SIGNAL(clicked()), this, SLOT(setObjectPath()));
    connect(treeDialog.treeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_treeView_doubleClicked(QModelIndex)));

    connect(usersListDialog.choose, SIGNAL(clicked()), this, SLOT(setUser()));

    connect(addObjectDialog.chooseUser, SIGNAL(clicked()), this, SLOT(on_chooseUser_clicked()));
    connect(addObjectDialog.chooseObject, SIGNAL(clicked()), this, SLOT(on_chooseObject_clicked()));
}

ProtectedObjects::~ProtectedObjects()
{
    delete ui;
}

void ProtectedObjects::on_pushButton_clicked()
{
    addObjectDialogUi->show();
}

void ProtectedObjects::on_treeView_doubleClicked(QModelIndex index)
{
    if(treeDialog.treeView->isExpanded(index)) {
        treeDialog.treeView->collapse(index);
        treeDialog.treeView->resizeColumnToContents(0);
    } else {
        treeDialog.treeView->expand(index);
        treeDialog.treeView->resizeColumnToContents(0);
    }
}


void ProtectedObjects::on_chooseUser_clicked()
{
    usersListDialogUi->show();
}

void ProtectedObjects::on_ok_clicked()
{

}

void ProtectedObjects::setObjectPath()
{
     addObjectDialog.objectPath->setText((fileModel->filePath(treeDialog.treeView->currentIndex())));
     treeDialogUi->close();
}


void ProtectedObjects::setUser()
{
     addObjectDialog.userName->setText(usersListDialog.usersList->selectedItems().first()->text());
     usersListDialogUi->close();
}

void ProtectedObjects::on_chooseObject_clicked()
{
    treeDialogUi->show();
}
