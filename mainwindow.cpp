#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ident.h"
#include <QFileSystemModel>
#include <QMessageBox>

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
    ui->treeView->setItemsExpandable( false );

    connect( ident, SIGNAL(login(QString)), this, SLOT( login(QString)) );
    connect( ui->actionLog, SIGNAL(triggered()), log, SLOT(show()) );
    connect( ui->actionMonitor, SIGNAL(triggered()), monitor, SLOT(show()) );
    connect( ui->actionEditUsers, SIGNAL(triggered()), editUsers, SLOT(show()) );
    connect( ui->actionProtectedObjects, SIGNAL(triggered()), protectedObjects, SLOT(show()) );
    connect( ui->treeView,SIGNAL(doubleClicked(QModelIndex)), this, SLOT(treeClicked(QModelIndex)) );
    //connect( ui->treeView,SIGNAL(expanded(QModelIndex)),this, SLOT(treeClicked(QModelIndex)) );
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
    //действия при нажатии на элемент браузера файловой системы
    //вызов метода typeFD(fileModel->filePath( m )) для получения типа выполняемого действия
    //вызов метода isLegal
    if( fileModel->isDir( m ) ){
        ui->treeView->setRootIndex( m );
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
    //выполняется при нажатии накнопку New File
    //проверка прав доступа
    //fileModel->
}

void MainWindow::createNewFolder(){
    //выполняется при нажатии накнопку New Folder
    //проверка прав доступа
    QString folderName = newFile->getName();
    if( folderName != "" )
        fileModel->mkdir( ui->treeView->currentIndex(), folderName );
}

void MainWindow::deleteFile(){
    //выполняется при нажатии накнопку Delete
    //проверка прав доступа
    fileModel->remove( ui->treeView->currentIndex() );
}

bool MainWindow::isLegal(QString path, ActionFS action){
    return true;
}

int MainWindow::typeFS(QString path){
    return 0;
}

