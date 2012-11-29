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
        QString tmp = line.left(line.indexOf(';'));
        file.push_back(tmp);
        line = line.mid(line.indexOf(';')+1);
    }
    if (line != "")
        file.push_back(line);

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

void User::saveToFile (){
    QString str;
    QFile usfile("users/"+ name +".us");
    if (!usfile.open(QIODevice::ReadWrite))
        return;

    QTextStream stream( &usfile );

    stream<<"name=" + crypt(name) + ";\r\n";
    stream<<"pass=" + crypt(pass) + ";\r\n";
    stream<<"group_id=" + crypt(QString::number(group_id)) + ";\r\n";
    stream<<"secret_level=" + crypt(QString::number(secret_level)) + ";\r\n";
    stream<<"new_file_access=" + crypt(QString::number(new_file_access)) + ";\r\n";
    stream<<"new_folder_access=" + crypt(QString::number(new_folder_access)) + ";\r\n";

    str="[";
    for(int i=0;i<disc.size();++i)
        str+=disc[i]+"; ";
    if (disc.size()>0)
        str.chop(2);
    str+= "]";
    stream <<"disc=" + crypt(str) + ";\r\n";

    str="[";
    for(int i=0;i<folder.size();++i)
        str+=folder[i]+"; ";
    if (folder.size()>0)
        str.chop(2);
    str+= "]";
    stream <<"folder=" + crypt(str) + ";\r\n";

    str="[";
    for(int i=0;i<file.size();++i)
        str+=file[i]+"; ";
    if (file.size()>0)
        str.chop(2);
    str+= "]";
    stream <<"file=" + crypt(str) + ";\r\n";

    str="[";
    for(int i=0;i<prog.size();++i)
        str+=prog[i]+"; ";
    if (prog.size()>0)
        str.chop(2);
    str+= "]";
    stream <<"prog=" + crypt(str) + ";\r\n";
    usfile.flush();
    usfile.resize(usfile.pos());
    usfile.close();
}

int User::getLastError(){
    return error;
}
