#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QMainWindow>

namespace Ui {
    class TextEdit;
}

class TextEdit : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextEdit(QWidget *parent = 0);
    ~TextEdit();

private:
    Ui::TextEdit *ui;
};

#endif // TEXTEDIT_H
