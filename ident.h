#ifndef IDENT_H
#define IDENT_H

#include <QDialog>

namespace Ui {
    class Ident;
}

class Ident : public QDialog
{
    Q_OBJECT

public:
    explicit Ident(QWidget *parent = 0);
    ~Ident();
public slots:
    void pasEntered();

private:
    Ui::Ident *ui;
signals:
    void login(QString);
};

#endif // IDENT_H
