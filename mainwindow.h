#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "edituser.h"
#include "editusers.h"
#include "log.h"
#include "monitor.h"
#include "newfile.h"
#include "protectedobjects.h"
#include "textedit.h"
#include <QModelIndex>
#include <QFileSystemModel>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void clicked( QModelIndex );

private:
    Ui::MainWindow *ui;
    EditUser* e1;
    EditUsers* e2;
    Log* l;
    Monitor* m;
    NewFile* n;
    ProtectedObjects* p;
    TextEdit* t;
    QFileSystemModel *model ;
};

#endif // MAINWINDOW_H
