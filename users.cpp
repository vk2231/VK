#include "users.h"
#include "QDir"


Users::Users()
{ //загрузка списка пользователей
    usersList.clear();

     QDir myDir("users/");
     QStringList Filter;
     Filter << "*.us";
     QStringList filesList = myDir.entryList(Filter, QDir::Files);
     //QString name;
     for (QStringList::const_iterator userFile = filesList.constBegin(); userFile != filesList.constEnd(); ++userFile){
         User * userItem;
         userItem->loadFromFile("users/"+ (*userFile));
         usersList.append(userItem);
     }

}
