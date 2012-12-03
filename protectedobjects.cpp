#include "protectedobjects.h"
#include "ui_protectedobjects.h"

#include <QFile>
#include <QTextStream>
#include <crypt.h>
#include "log.h"




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

    setModal(true);

    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath( QDir::homePath() );
    fileModel->setReadOnly( false );
    treeDialog.treeView->setModel( fileModel );
    treeDialog.treeView->setItemsExpandable(true);
    treeDialog.treeView->setExpandsOnDoubleClick(false);
    treeDialog.treeView->setEditTriggers(!QAbstractItemView::DoubleClicked);
    treeDialog.treeView->resizeColumnToContents(0);


    connect(treeDialog.chooseFromTree, SIGNAL(clicked()), this, SLOT(setObjectPath()));
    connect(treeDialog.treeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_treeView_doubleClicked(QModelIndex)));

    connect(addObjectDialog.chooseObject, SIGNAL(clicked()), this, SLOT(on_chooseObject_clicked()));
    connect( addObjectDialog.ok, SIGNAL(clicked()), this, SLOT(objectSelected()) );
    connect( addObjectDialog.ok, SIGNAL(clicked()), addObjectDialogUi, SLOT(close()) );

    initWindow();
}

ProtectedObjects::~ProtectedObjects()
{
    toDisk();
    delete ui;
}


/**
  Загружает список защищаемых оъектов из файла
  и выводит его на listProtected, а, заодно, в public список protectedObjectsList
  @author: Berezin
 */
void ProtectedObjects::initWindow(){

    QFile infile(protObjFile); //TODO договориться о пути к файлу
    if (!infile.open(QIODevice::ReadOnly | QIODevice::Text)){
        log(tr("ProtectedObjects:critical:cannot open list of protected objects"));
        return;
    }

    QTextStream in(&infile);
    QString cypherObject;
    while(!in.atEnd()) {
       cypherObject = in.readLine();
       QString pureObject=decrypt(cypherObject);
       ui->listProtected->insertItem(1,pureObject);
       protectedObjectsList<<pureObject;
    }
    protectedObjectsSet=protectedObjectsList.toSet();
    infile.close();
}


void ProtectedObjects::on_addButton_clicked()
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



void ProtectedObjects::setObjectPath()
{
     addObjectDialog.objectPath->setText((fileModel->filePath(treeDialog.treeView->currentIndex())));
     treeDialogUi->close();
}




void ProtectedObjects::on_chooseObject_clicked()
{
    treeDialogUi->show();
}





/**
  удаление одного или нескольких объектов из списка защищамых ресурсов
  @author: Berezin
 */
void ProtectedObjects::on_deleteButton_clicked()
{
    QList <QListWidgetItem *> selectedItems = ui->listProtected->selectedItems();
    for (int item=0; item<selectedItems.size();item++){
        protectedObjectsList.removeAll(selectedItems[item]->text());
    }
    ui->listProtected->clear();
     for (size_t item=0; item<protectedObjectsList.size();item++) {
       //QListWidgetItem *widgetitem = new QListWidgetItem();
       //widgetitem->setText(protectedObjectsList(item));
       ui->listProtected->insertItem(1, protectedObjectsList[item]);
    }
     protectedObjectsSet=protectedObjectsList.toSet();
}

/**
  удаление защищаемого объекта из protectedObjects
  @author: Berezin
  @param path это либо обычный путь, либо особый путь к секретному файлу
  */
  void ProtectedObjects::deleteProtectedObject(QString path){
      if (path.contains(".")){ //расширение .txx
          //значит секретный файл
        QString objectIterator;
        foreach(objectIterator,protectedObjectsList){
            if (objectIterator.contains(path)){
                protectedObjectsList.removeAll(objectIterator);
                protectedObjectsSet.remove(objectIterator);
            }

        }
      }
      protectedObjectsList.removeAll(path);
      protectedObjectsSet.remove(path);
  }





/**
   Добавление защищаемого объекта в список, в множество и в табличку
   @author: Berezin
*/
void ProtectedObjects::addProtectedObject(QString path){

    path = addObjectDialog.objectPath->text();
    if (protectedObjectsSet.contains(path))
        return;
    if (path.contains(",")){ //содержит уровень cекретности
        deleteProtectedObject(path.left(path.indexOf(',')));
    }
    protectedObjectsList<<path;
    protectedObjectsSet<<path;
    ui->listProtected->insertItem(1, path);
}




/**
  Вычисление степени секретности файла
  @author Berezin
  @param path - путь к файлу в стиле "C:/file.txx"
  @return 0-notSecret, 1-coolSecret, 2-topSecret, -1 - error
 */
int  ProtectedObjects::getSecretLevel(QString path){
    if (!path.contains(",")){
        //error нету грифа
        return -1;
    }
    if (path.at(path.indexOf(',')+1)==QChar('0'))
        return 0;
    else if(path.at(path.indexOf(',')+1)==QChar('1'))
        return 1;
    else if(path.at(path.indexOf(',')+1)==QChar('2'))
        return 2;
    return -1;
}




/**
   запись списка защищаемых объектов на диск
   @author: Berezin
  */
void ProtectedObjects::toDisk(){

    QFile outfile(protObjFile);
    if (!outfile.open(QIODevice::WriteOnly)){
        log(tr("ProtectedObjects:critical:cannot save to file"));
        return;
    }
    QTextStream stream( &outfile);

    for (size_t item=0;item<protectedObjectsList.size();item++){
        stream<<crypt(protectedObjectsList[item])<<"\n";

    }
    outfile.close();
    return;
}




void ProtectedObjects::objectSelected(){
    QString objName = addObjectDialog.objectPath->text();
    addProtectedObject( objName );
}
