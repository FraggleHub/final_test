#pragma once
#include <iostream>
using namespace std;

//------------------------
class stringMasive // ������� ������ ���������� �� �������� ��� ��������
{
public:
    int m_length;
    string* m_chat = new string[m_length];

    stringMasive();
    stringMasive(int length);
    ~stringMasive();

    stringMasive(const stringMasive& other); // : m_length(other.m_length) //
    void resize(int newLength); // �������� �� ���� �� ����������
};
//---------------------------------------
class IntArray
{
public:
    //private:
    int m_length10;
    int* m_data = new int[m_length10];      // () {};
    //public:
    IntArray(); // = default;
    IntArray(int length);
    ~IntArray();
    void resize(int newLength);
};


//-----------------------------------------
class Chat// : public Account // ����� ��� � ������ ��������� ��������� ��������
{
public:

    stringMasive* Messenger;
    IntArray* Sender;
    IntArray* Recipient;
    Chat();
    ~Chat();
};
//---------------------------------------------------------


class Account // : public Chat// ��� �� ��������� ���
{
public:
    string _name, _parole;    // ���
    short _id; // id
    Account();
    Account(string name); // :_name(name) {}; // ����������� �������� � ������
    Account(string name, short id); // :_name(name), _id(id) {}; // ����������� �������� � ������ � ���������
    Account(string name, string parole);
    ~Account();

    Chat* createChat();
    void setMessage(Chat* T, int UserID);			// �������� � ��� 
    void GetMessage(Chat* T);			// ���������  ��������� 
};

//------------------------------------------------------------------


/*class MassAccount
{
    public:

    Account * chater = new Account[3];
    MassAccount ()
    {

    }
    ~MassAccount ()
    {
      delete [] chater;
    }
};*/
