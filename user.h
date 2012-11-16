#ifndef USER_H
#define USER_H

#include <QStringList>

class User
{
public:
    User();
    int id, gtoup_id, secret_level, new_file_access, new_folder_access, disc_n, folder_n, file_n, prog_n;
    QString name, pas;
    QStringList disc, folder, file, prog;
    void loadFromFile(QString path);
};

#endif // USER_H
