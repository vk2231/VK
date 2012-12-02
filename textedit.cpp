/*
WARNING!

SET USER BEFORE OPENING THE FILE
AND GIVE THIS CLASS protectedObject instance

*/

#include "textedit.h"
#include "ui_textedit.h"
#include "crypt.h"
#include "QMessageBox"
#include "newfile.h"
#include "user.h"

#include <QFile>
#include <QDir>
#include <QTextStream>

QString USERSCATALOG = "users";
QString SEPARATOR = "\\";

TextEdit::TextEdit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextEdit)
{
    ui->setupUi(this);
    newFileDialog = new NewFile(this);
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFileSlot()));
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFileSlot()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFileSlot()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(hide()));
    connect(ui->actionSave_as, SIGNAL(triggered()),this, SLOT(saveFileAsSlot()));
    newSession();
}

TextEdit::~TextEdit()
{
    delete ui;
}

void TextEdit::setUserName(QString name) {
    currentUser = name;
}

void TextEdit::newSession() {
    currentUser = "";
}

void TextEdit::saveFileAsSlot() {
    //XXX not checking rights.Also may overright file with higher secret status
    //Also FULL FILE PATH should be entered in newFileDialog
    currentFilePath = newFileDialog->getName(); // should be remaked or removed.
    saveFileSlot();
}

void TextEdit::newFileSlot() {
    //XXX not checking rights
    currentFilePath = newFileDialog->getName();
    ui->plainTextEdit->setPlainText("");
    saveFileSlot();//initiate creating file and adding to protected objects
}

void TextEdit::openFileSlot() {
    //XXX not checking rights
    open(newFileDialog->getName());
}


void TextEdit::saveFileSlot() {
    QFile file(currentFilePath);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(0, QString("Error"), QString("Cannot save file"));
        return;
    }

    QString text = ui->plainTextEdit->toPlainText();
    //text = crypt(text);
    QByteArray b(text.toUtf8());
    file.write(b);
    file.flush();
    file.close();
    QMessageBox::warning(0, QString("Success"), QString("Saved"));

    protObj->addProtectedObject(currentFilePath);

    //XXX currentUser = "user1";

    //also add to user passports
    addFileToPassports();
}

void TextEdit::addFileToPassports() {
    //currentFilePath contains file path
    //currentUser contains user
    User mainUser;
    QString mainUserPath = USERSCATALOG+SEPARATOR+currentUser+".us";
     mainUser.loadFromFile(mainUserPath);

    QDir dir(USERSCATALOG);
    dir.setFilter(QDir::Files);
    QStringList userList = dir.entryList();
    for (int i = 0; i < userList.count(); ++i){
        //userList[i] - current passport
        User iteratorUser;
        iteratorUser.loadFromFile(USERSCATALOG+SEPARATOR+userList[i]);

        foreach(QString fileString, iteratorUser.file) {
            //if passport already contains record about file, delete it first.
            QStringList nameAndAccessPair = fileString.split(",");
            QString name = nameAndAccessPair[0];
            if (!(QString::compare(currentFilePath,name,Qt::CaseInsensitive))) {
                iteratorUser.file.removeOne(fileString);
                break;
            }
        }

        QString forAdding;
        forAdding.append(currentFilePath);
        if (iteratorUser.group_id == mainUser.group_id) {
            iteratorUser.file.append(forAdding+",-rw");
        } else {
            switch (mainUser.new_file_access) {
            case 0: {//0 case:nothing
                break;
            }
            case 1:{//1 case
                iteratorUser.file.append(forAdding+",-r");
                break;
            }
            default:{//2 case
                iteratorUser.file.append(forAdding+",-rw");
                break;
            }
            }
        }

        iteratorUser.saveToFile();
    }
}

void TextEdit::open(QString path)
{
    //XXX rights should be checking outside or here.
    currentFilePath = path;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(0, QString("Error"), QString("Cannot open file"));
        return;
    }

    QByteArray data = file.readAll();
    QString crypteddata = QString::fromUtf8(data.data(), data.size());

    file.close();

    //QString decrypteddata = decrypt(crypteddata);
    QString decrypteddata = crypteddata;
    ui->plainTextEdit->setPlainText(decrypteddata);
}

