#ifndef USERS_H
#define USERS_H


/**
������ ����� ������������ ��� �������� ���� ������ � ������������� � ������ ��� ���������� �����.
��������� user'�� ���������� ��� ��������� ���������� ��������� ��������,
�������� ��� ���������� ������ ���������� �����,
��������� ������ � ���� ����� ������������ ���� ��������� ������������� ������.
��� �������� ������ � ������� ��������� � ������ Users.
*/

//TODO ��� ��������� ��� ����� ����� � ������� � ������� ����� ������ �� �������?
//question by Berezin.

#include "user.h"


class Users
{
public:
    QList <User *> usersList;
    Users();
    void toDisk();
    ~Users();
};

#endif // USERS_H
