#ifndef IDENT_H
#define IDENT_H

#include <QMainWindow>

namespace Ui {
    class ident;
}

class ident : public QMainWindow
{
    Q_OBJECT

public:
    explicit ident(QWidget *parent = 0);
    ~ident();

signals:
    void go();

public slots:
    void ok();


private:
    Ui::ident *ui;
};

#endif // IDENT_H
