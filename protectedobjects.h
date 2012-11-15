#ifndef PROTECTEDOBJECTS_H
#define PROTECTEDOBJECTS_H

#include <QDialog>

namespace Ui {
    class ProtectedObjects;
}

class ProtectedObjects : public QDialog
{
    Q_OBJECT

public:
    explicit ProtectedObjects(QWidget *parent = 0);
    ~ProtectedObjects();

private:
    Ui::ProtectedObjects *ui;
};

#endif // PROTECTEDOBJECTS_H
