#pragma once
#include <iostream>
//#include <string>

using namespace std;

//#pragma region global int

//#pragma endregion

#pragma region chatMassive

class stringMasive
{
public: // вся прога пока на паблике выполнена
    int m_length;
    string* m_chat = new string[m_length]; // массив сообщений

    stringMasive(); // конструкторы, деструкторы
    stringMasive(int length);
    ~stringMasive();

    //stringMasive(const stringMasive& other); // : m_length(other.m_length) //

    //void resize(int newLength); // ресайзер (добавляет новую строку, сообщение)
    void resize();// легкий апгрейд ресайзера. без входных данных
};

#pragma endregion

#pragma region intArray

class IntArray // класс для хранения ID отправителя получателя
{
public:
    //private:
    int m_length10;
    int* m_data = new int[m_length10];// массив для отправителя или получателя 
    IntArray(); // конструкторы, деструкторы;
    IntArray(int length);
    ~IntArray();
    //void resize(int newLength);// ресайзер ("добавляет для сообщения", ID отправителя/получателя)
    void resizeSender();// легкий апгрейд ресайзера. без входных данных. 
    void resizeRecipient();// теперь два ресайзера,так как два интэррэя - отправитель и получатель

};

#pragma endregion

#pragma region chat

class Chat
    // класс чат в котором создается три массива (сообщений, отправителя и получателя)
{
public:

    stringMasive* Messenger; // контейнер сообщений
    IntArray* Sender; //контейнер отправителей
    IntArray* Recipient; // контейнер получателей
    Chat(); // конструктор, деструктор
    ~Chat();
};

#pragma endregion

#pragma region account

class Account // класс пользователя
{
public:
    bool _currentUser;
    string _name, _parole;    // имя, пароль
    short _id; // id
    //конструкторы, деструкторы
    Account();
    Account(string name); // :_name(name) {}; // конструктор аккаунта с именем
    Account(string name, short id); // :_name(name), _id(id) {}; // конструктор аккаунта с именем и возрастом
    Account(string name, string parole);
    ~Account();

    //Chat* createChat(); не нужная сейчас функция (если вообще нужна)
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setMessage(Chat* T, int UserID);// написать в чат (массив стрингов) 
    void setMesAll(Chat* T); //написать в чат всем

    void GetMessage(Chat* T);			// прочитать  сообщение(из массива стрингов) 
    void changeUser(string newLogin, string newPassword);
};

#pragma endregion

#pragma region accMassive

class accMasive // класс массив пользователей (массив класса Account)
{
public:
    int acc_length;
    Account* m_acc = new Account[acc_length]; // массив Account

    accMasive(); // конструкторы, деструкторы
    accMasive(int length);
    ~accMasive();

    void resize(); // ресайзер (добавляет аккаунт)
    //void setAccount();  старая функция заменил на setNewAccount
    void setNewAccount(string newAcc, string newPar);//создание нового аккаунта
    void showAllUsers();
    void updateCurrentUser(int Id);
};

#pragma endregion

void Menu(); //главное меню