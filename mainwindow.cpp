#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ident.h"

#include <QtCore>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ident = new Ident(this);
    log = new Log(this);
    monitor = new Monitor(this);
    newFile = new NewFile(this);
    textEdit = new TextEdit(this);
    editUsers = new EditUsers(this);
    protectedObjects = new ProtectedObjects(this);
    fileModel = new QFileSystemModel(this);

    this->hide();
    ident->show();
    ident->setModal( true );
    log->setModal(true);
    monitor->setModal(true);
    newFile->setModal(true);
    editUsers->setModal(true);
    protectedObjects->setModal(true);


    fileModel->setRootPath( QDir::homePath() );
    fileModel->setReadOnly( false );
    ui->treeView->setModel( fileModel );
    ui->treeView->setItemsExpandable(true);
    ui->treeView->setExpandsOnDoubleClick(false);
    ui->treeView->setEditTriggers(!QAbstractItemView::DoubleClicked);
    ui->treeView->resizeColumnToContents(0);

    connect( ident, SIGNAL(login(QString)), this, SLOT( login(QString)) );
    connect( ui->actionLog, SIGNAL(triggered()), log, SLOT(show()) );
    connect( ui->actionMonitor, SIGNAL(triggered()), monitor, SLOT(show()) );
    connect( ui->actionEditUsers, SIGNAL(triggered()), editUsers, SLOT(show()) );
    connect( ui->actionProtectedObjects, SIGNAL(triggered()), protectedObjects, SLOT(show()) );
    connect( ui->treeView,SIGNAL(doubleClicked(QModelIndex)), this, SLOT(treeClicked(QModelIndex)) );
    connect( ui->newFileButton, SIGNAL(clicked()), this, SLOT(createNewFile()) );
    connect( ui->newFolderButton, SIGNAL(clicked()), this, SLOT(createNewFolder()) );
    connect( ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteFile()) );
    connect( ui->upButton, SIGNAL(clicked()), this, SLOT(up()) );
    connect( ui->actionLogout, SIGNAL(triggered()), this, SLOT(logout()) );
    connect( ui->actionExit, SIGNAL(triggered()), this, SLOT(close()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::treeClicked(QModelIndex m){
    int c = typeFS(fileModel->filePath(m));
    switch(c) {
        case 0:
        case 1:
            if(!isLegal(fileModel->filePath(m), openFolder)) {
                //log("Attempt to access denied folder");
                QMessageBox msgBox;
                msgBox.setText("You have not permissions to view this folder");
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.exec();
            } else {
                if(ui->treeView->isExpanded(m)) {
                    ui->treeView->collapse(m);
                    ui->treeView->resizeColumnToContents(0);
                } else {
                    ui->treeView->expand(m);
                    ui->treeView->resizeColumnToContents(0);
                }
            }
            break;
        case 2:
            if(!isLegal(fileModel->filePath(m), readFile)) {
                //log("Attempt to read denied file");
                QMessageBox msgBox;
                msgBox.setText("You have not permissions to read this file");
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.exec();
            } else {
                textEdit->open(fileModel->filePath(m));
                textEdit->setVisible(true);
            }
            break;
        case 3:
            if(!isLegal(fileModel->filePath(m), runProg)) {
                //log("Attempt to run denied application");
                QMessageBox msgBox;
                msgBox.setText("You have not permissions to run this application");
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.exec();
            } else {
                QStringList arguments;
                QProcess *myProcess = new QProcess(this);
                myProcess->start(fileModel->filePath(m), arguments);
            }
            break;
    }
}

void MainWindow::up(){
    ui->treeView->setRootIndex( ui->treeView->rootIndex().parent() );
}

void MainWindow::login(QString name){
    //действия при вводе пользователем правильного пароля
    if( name == "admin" ){
        ui->menuAdministration->setVisible( true );
        user.name = "admin";
    }
    else{
        ui->menuAdministration->setVisible( false );
        user.loadFromFile( name + ".us" );
    }
    show();
}

void MainWindow::logout(){
    hide();
    ident->show();
}

void MainWindow::createNewFile(){
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;
    if(fileModel->isDir(ui->treeView->currentIndex())) {
        if(isLegal(fileModel->filePath(ui->treeView->currentIndex()), openFolder)) {
            QString Name = QInputDialog::getText (this, "New File", "Enter the Name");
            if(Name.isEmpty()) return;
            QFile file(fileModel->filePath(ui->treeView->currentIndex())+ "/" + Name);
            file.open(QIODevice::Append | QIODevice::Text);
        } else {
            //log("Attempt to change content of denied folder");
            QMessageBox msgBox;
            msgBox.setText(QString("You have not permissions to change content of ").append(fileModel->filePath(ui->treeView->currentIndex())));
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.exec();
        }
    }
}

void MainWindow::createNewFolder(){
    if(isLegal(fileModel->filePath(ui->treeView->currentIndex()), openFolder)) {
        QString folderName = newFile->getName();
        if(!folderName.isEmpty())
            fileModel->mkdir( ui->treeView->currentIndex(), folderName );
    } else {
        //log("Attempt to change content of denied folder");
        QMessageBox msgBox;
        msgBox.setText(QString("You have not permissions to change content of ").append(fileModel->filePath(ui->treeView->currentIndex())));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}

void MainWindow::deleteFile(){
    int c = typeFS(fileModel->filePath(ui->treeView->currentIndex()));
    switch(c) {
    case 1: if(isLegal(fileModel->filePath(ui->treeView->currentIndex()), delFolder))
                fileModel->remove( ui->treeView->currentIndex());
            else {
                //log("Attempt to delete denied folder");
                QMessageBox msgBox;
                msgBox.setText("You have not permissions to delete this folder");
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.exec();
            }
        break;
    case 2: if(isLegal(fileModel->filePath(ui->treeView->currentIndex()), delFile))
                fileModel->remove( ui->treeView->currentIndex());
            else {
                //log("Attempt to delete denied file");
                QMessageBox msgBox;
                msgBox.setText("You have not permissions to delete this file");
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.exec();
            }
        break;
    default:
        QMessageBox msgBox;
        msgBox.setText("Option is unavailable for this object");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        break;
    }
}

bool MainWindow::isLegal(QString path, ActionFS action){
    return true;
}

int MainWindow::typeFS(QString path){
    QModelIndex index = fileModel->index(path);
    if(fileModel->fileInfo(index).isDir()) return 1;
    if(fileModel->fileInfo(index).isFile() && !fileModel->fileInfo(index).isExecutable()) return 2;
    if(fileModel->fileInfo(index).isExecutable()) return 3;
    return -1;
}


void MainWindow::on_treeView_expanded(const QModelIndex &index)
{
    if(!isLegal(fileModel->filePath(index), openFolder)){
        //log("Attempt to access denied folder");
        ui->treeView->collapse(index);
        QMessageBox msgBox;
        msgBox.setText("You have not permissions to view this folder");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    } else {
        ui->treeView->resizeColumnToContents(0);
    }
}
