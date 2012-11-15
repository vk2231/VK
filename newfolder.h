#ifndef NEWFOLDER_H
#define NEWFOLDER_H

#include <QDialog>

namespace Ui {
    class NewFolder;
}

class NewFolder : public QDialog
{
    Q_OBJECT

public:
    explicit NewFolder(QWidget *parent = 0);
    ~NewFolder();

private:
    Ui::NewFolder *ui;
};

#endif // NEWFOLDER_H
