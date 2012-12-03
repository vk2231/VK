#include "users.h"
#include "QDir"


/**
  �������� ������ ������������� d ��
  @author Berezin
  */
Users::Users()
{
    usersList.clear();

     QDir myDir("users/");
     QStringList Filter;
     Filter << "*.us";
     QStringList filesList = myDir.entryList(Filter, QDir::Files);
     //QString name;
     for (QStringList::const_iterator userFile = filesList.constBegin(); userFile != filesList.constEnd(); ++userFile){
         User * userItem=new User();
         userItem->loadFromFile("users/"+ (*userFile));
         usersList.append(userItem);
     }

}
Users::~Users(){
    for (int i=0; i<usersList.size(); i++){
        delete usersList[i];
    }
}

/**
  ���������� ���� ���������, ����������� � �������������� � ����������� ������.
  @author Berezin

  ������ ������������ ������������� �������� isLegal

  */
void Users::toDisk(){
    User * userIterator;
    foreach(userIterator,usersList){
        userIterator->saveToFile();
    }
}
