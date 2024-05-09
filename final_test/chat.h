#pragma once

#include <iostream>

using namespace std;

#pragma region глобальные переменные

static int i3 = -1; // элемент массива (пользователь одновременно и его ID)
static int n3 = 1; // размер массива (количество аккаунтов или пользователей)

#pragma endregion

#pragma region класс контейнера текста всех сообщений в чате

class stringMasive {
public: // вся прога пока на паблике выполнена
    int m_length;
    string* m_chat = new string[m_length]; // массив сообщений

    stringMasive(); // конструкторы, деструкторы
    stringMasive(int length);
    ~stringMasive();

    //stringMasive(const stringMasive& other); // : m_length(other.m_length) //

    void resize(int newLength); // ресайзер (добавляет новую строку, сообщение)
};

#pragma endregion

#pragma region класс для хранения id отправителя получателя

class IntArray {
public:
    int m_length10;
    int* m_data = new int[m_length10];// массив для отправителя или получателя 
    IntArray(); // конструкторы, деструкторы;
    IntArray(int length);
    ~IntArray();
    void resize(int newLength);// ресайзер ("добавляет для сообщения", ID отправителя/получателя)
};

#pragma endregion

#pragma region чат на 3-х массивах

class Chat {
public:
    stringMasive* Messenger; // контейнер сообщений
    IntArray* Sender; //контейнер отправителей
    IntArray* Recipient; // контейнер получателей
    Chat(); // конструктор, деструктор
    ~Chat();
};

#pragma endregion

#pragma region класс пользователей

class Account {
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

#pragma region массив пользователей

class accMasive {
protected:
    int acc_length;
    Account* m_acc = new Account[acc_length];
public:

    accMasive(); // конструкторы, деструкторы
    accMasive(int length);
    ~accMasive();

    void resize(); //новый ресайз замена старому
    int getSize() const; // получение размера массива
    void resize(int newLength); // ресайзер (добавляет аккаунт)
    void setNewAccount(string newAcc, string newPar);//создание нового аккаунта
    void showAllUsers();
    void updateCurrentUser(int Id);
};

#pragma endregion

#pragma region основное меню

void Menu();

#pragma endregion