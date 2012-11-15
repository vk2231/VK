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
    this->hide();
    ident* ide = new ident();
    connect( ide, SIGNAL(go()), this, SLOT(show()) );
    ide->show();
    l = new Log();
    m = new Monitor();
    n = new NewFile();
    t = new TextEdit();
    EditUser* e = new EditUser();
    EditUsers* ee = new EditUsers();
    p = new ProtectedObjects();
    connect( ui->actionView_log, SIGNAL(triggered()), l, SLOT(show()) );
    connect( ui->actionEdit_controled_filed, SIGNAL(triggered()), m, SLOT(show()) );
    connect( ui->actionEdit_users, SIGNAL(triggered()), e, SLOT(show()) );
    connect( ui->actionEdit_users, SIGNAL(triggered()), ee, SLOT(show()) );
    connect( ui->actionEdit_mandats, SIGNAL(triggered()), p, SLOT(show()) );
    connect( ui->pushButton, SIGNAL(clicked()), n, SLOT(show()) );
    QFileSystemModel* model = new QFileSystemModel;
         model->setRootPath(QDir::currentPath());
         ui->treeView->setModel( model );
         ui->treeView->setRootIndex(model->index(QDir::rootPath() ) );
    ui->treeView->setExpandsOnDoubleClick( false );
    ui->treeView->setColumnHidden( 1, 1 );
    connect( ui->treeView,SIGNAL(clicked(QModelIndex)),this, SLOT(clicked(QModelIndex)) );
    connect( ui->treeView,SIGNAL(expanded(QModelIndex)),this, SLOT(clicked(QModelIndex)) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clicked(QModelIndex m){
    QMessageBox::information( this, "", model->filePath( m ) );
}
