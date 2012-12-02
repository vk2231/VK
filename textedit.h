#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QMainWindow>
#include "protectedobjects.h"
#include "newfile.h"

namespace Ui {
    class TextEdit;
}

class TextEdit : public QMainWindow
{
    Q_OBJECT

public slots:
    void saveFileSlot();
    void openFileSlot();
    void saveFileAsSlot();
    void newFileSlot();


public:
    ProtectedObjects *protObj; //someone should initialize this value
    explicit TextEdit(QWidget *parent = 0);
    ~TextEdit();
    void setUserName(QString name);
    void open(QString path);
    void newSession();
private:
    Ui::TextEdit *ui;

    void addFileToPassports();
    NewFile* newFileDialog; //dialog for creating file from the editor.
    QString currentFilePath;
    QString currentUser;
};

#endif // TEXTEDIT_H


