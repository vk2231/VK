#ifndef MAINWINDOWADMIN_H
#define MAINWINDOWADMIN_H

#include <QMainWindow>

namespace Ui {
    class MainWindowAdmin;
}

class MainWindowAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowAdmin(QWidget *parent = 0);
    ~MainWindowAdmin();

private:
    Ui::MainWindowAdmin *ui;
};

#endif // MAINWINDOWADMIN_H
