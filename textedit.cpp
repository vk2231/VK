#include "textedit.h"
#include "ui_textedit.h"

TextEdit::TextEdit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEdit)
{
    ui->setupUi(this);
}

TextEdit::~TextEdit()
{
    delete ui;
}
