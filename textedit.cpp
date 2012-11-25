#include "textedit.h"
#include "ui_textedit.h"

#include <QFile>
#include <QTextStream>

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

void TextEdit::open(QString path){
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;
    QTextStream in(&file);
    ui->plainTextEdit->setPlainText(in.readAll());
}
