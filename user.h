#ifndef USER_H
#define USER_H

#include <QStringList>
#include <QVector>
#define NOTUSER 1;
#define PARAMMIS 2;
#define FILEOPENERR 3;
class User
{
    int error;
public:
    User();
    int group_id, secret_level, new_file_access, new_folder_access;
    QString name, pass;
    QStringList disc, folder, file, prog;
    void loadFromFile(QString path);
    void saveToFile();
    int getLastError();
};

#endif // USER_H
