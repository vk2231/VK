#include "user.h"
#include <QFile>
#include <qtextstream.h>
#include <crypt.h>
User::User()
{
    error = 0;
}

void User::loadFromFile(QString path){
    QFile usfile(path);
    QString line;
    if(!usfile.exists()){

        //emit log("Unknown user");
        error = NOTUSER;
        usfile.close();
        return;
    }
    if (!usfile.open(QIODevice::ReadOnly)){
        error = FILEOPENERR;
        usfile.close();
        return ;
    }
    line=usfile.readLine();
    line=decrypt(line);
    if (!line.startsWith("name"))
        error = PARAMMIS;
    name = line.replace( "name=", "").replace(";","").replace("\r\n","");

    line=usfile.readLine();
    line=decrypt(line);
    if (!line.startsWith("pass"))
        error = PARAMMIS;
    pass = line.replace( "pass=", "").replace(";","").replace("\r\n","");

    line=usfile.readLine();
    line=decrypt(line);
    if (!line.startsWith("group_id"))
        error = PARAMMIS;
    group_id = line.replace( "group_id=", "").replace(";","").replace("\r\n","").toInt();

    line=usfile.readLine();
    line=decrypt(line);
    if (!line.startsWith("secret_level"))
        error = PARAMMIS;
    secret_level = line.replace( "secret_level=", "").replace(";","").replace("\r\n","").toInt();

    line=usfile.readLine();
    line=decrypt(line);
    if (!line.startsWith("new_file_access"))
        error = PARAMMIS;
    new_file_access = line.replace( "new_file_access=", "").replace(";","").replace("\r\n","").toInt();

    line=usfile.readLine();
    line=decrypt(line);
    if (!line.startsWith("new_folder_access"))
        error = PARAMMIS;
    new_folder_access = line.replace( "new_folder_access=", "").replace(";","").replace("\r\n","").toInt();

    line=usfile.readLine();
    line=decrypt(line).replace(" ","");
    if (!line.startsWith("disc"))
        error = PARAMMIS;
    line.replace( "disc=[", "").replace("\r\n","").replace("];","");
    while(line.contains(";")){
        QString tmp = line.left(line.indexOf(';'));
        disc.push_back(tmp);
        line = line.mid(line.indexOf(';')+1);
    }
    if (line != "")
        disc.push_back(line);

    line=usfile.readLine();
    line=decrypt(line).replace(" ","");
    if (!line.startsWith("folder="))
        error = PARAMMIS;
    line.replace( "folder=[", "").replace("\r\n","").replace("];","");
    while(line.contains(";")){
        QString tmp = line.left(line.indexOf(';'));
        folder.push_back(tmp);
        line = line.mid(line.indexOf(';')+1);
    }
    if (line != "")
        folder.push_back(line);

    line=usfile.readLine();
    line=decrypt(line).replace(" ","");
    if (!line.startsWith("file="))
        error = PARAMMIS;
    line.replace( "file=[", "").replace("\r\n","").replace("];","");
    while(line.contains(";")){
        file.push_back(line.left(line.indexOf(';')));
        line = line.mid(line.indexOf(';')+1);
    }
    if (line != "")
        file.push_back(line.left(line.indexOf(';')));
    line=usfile.readLine();
    line=decrypt(line).replace(" ","");
    if (!line.startsWith("prog="))
        error = PARAMMIS;
    line.replace( "prog=[", "").replace("\r\n","").replace("];","");
    while(line.contains(";")){
        QString tmp = line.left(line.indexOf(';'));
        prog.push_back(tmp);
        line = line.mid(line.indexOf(';')+1);
    }
    if (line != "")
        prog.push_back(line);
    usfile.close();
}

QString User:: getFileName (QString fname){
    return fname.left(fname.indexOf(','));
}

int User::getFileAccess(QString fname){
    QString type = fname.mid(fname.indexOf(',')+1);
    if (type == "-r")
        return 0;
    else
        return 1;
}

void User::saveToFile (){
    QString str;
    QFile usfile("users/"+ name +".us");
    if (!usfile.open(QIODevice::WriteOnly))
        return;

    QTextStream stream( &usfile );

    stream<<crypt("name=" + name + ";\r\n")<<"\n";
    stream<<crypt("pass=" + pass + ";\r\n")<<"\n";
    stream<<crypt("group_id=" + QString::number(group_id) + ";\r\n")<<"\n";
    stream<<crypt("secret_level=" + QString::number(secret_level) + ";\r\n")<<"\n";
    stream<<crypt("new_file_access=" + QString::number(new_file_access) + ";\r\n")<<"\n";
    stream<<crypt("new_folder_access=" + QString::number(new_folder_access) + ";\r\n")<<"\n";

    str="[";
    for(int i=0;i<disc.size();++i)
        str+=disc[i]+"; ";
    if (disc.size()>0)
        str.chop(2);
    str+= "]";
    stream <<crypt("disc=" + str + ";\r\n")<<"\n";

    str="[";
    for(int i=0;i<folder.size();++i)
        str+=folder[i]+"; ";
    if (folder.size()>0)
        str.chop(2);
    str+= "]";
    stream <<crypt("folder=" + str + ";\r\n")<<"\n";

    str="[";
    for(int i=0;i<file.size();++i)
        str+=file[i]+"; ";
    if (file.size()>0)
        str.chop(2);
    str+= "]";
    stream <<crypt("file=" + str + ";\r\n")<<"\n";

    str="[";
    for(int i=0;i<prog.size();++i)
        str+=prog[i]+"; ";
    if (prog.size()>0)
        str.chop(2);
    str+= "]";
    stream <<crypt("prog=" + str + ";\r\n")<<"\n";
    usfile.flush();
    usfile.resize(usfile.pos());
    usfile.close();
}

int User::getLastError(){
    return error;
}
