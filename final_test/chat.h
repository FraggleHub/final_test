#pragma once
#include <iostream>
using namespace std;

//------------------------
class stringMasive // обрезок класса контейнера от интЭррэй для стрингов
{
public:
    int m_length;
    string* m_chat = new string[m_length];

    stringMasive();
    stringMasive(int length);
    ~stringMasive();

    stringMasive(const stringMasive& other); // : m_length(other.m_length) //
    void resize(int newLength); // ресайзер из того же контейнера
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
class Chat// : public Account // класс чат в ктором создается контейнер стрингов
{
public:

    stringMasive* Messenger;
    IntArray* Sender;
    IntArray* Recipient;
    Chat();
    ~Chat();
};
//---------------------------------------------------------


class Account // : public Chat// уже не нсаледник ЧАТ
{
public:
    string _name, _parole;    // имя
    short _id; // id
    Account();
    Account(string name); // :_name(name) {}; // конструктор аккаунта с именем
    Account(string name, short id); // :_name(name), _id(id) {}; // конструктор аккаунта с именем и возрастом
    Account(string name, string parole);
    ~Account();

    Chat* createChat();
    void setMessage(Chat* T, int UserID);			// написать в чат 
    void GetMessage(Chat* T);			// прочитать  сообщение 
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
