#include  "chat.h"

#include <iostream>
using namespace std;

// глобальные переменные
static int i0 = -1;// элемент массива (отправитель Sender)
static int n0 = 1; // размер массива (отправители Sender)

static int i1 = -1;// элемент массива (сообщение Messenger)
static int n1 = 1;// размер массива (все сообщения Messenger)

static int i2 = -1; //элемент массива(получатель Recipient)
static int n2 = 1; // размер массива (получатели Recipient)

//------------------------------------------------
stringMasive::stringMasive() {}
stringMasive::stringMasive(int length) :m_length(length) {}
stringMasive::~stringMasive()
{
    delete[]m_chat;
}

/*stringMasive::stringMasive(const stringMasive& other) : m_length(other.m_length) //
{
    m_chat = new string[m_length];
    for (int i = 0; i < m_length; ++i)
    {
        m_chat[i] = other.m_chat[i];
    }
} */

void stringMasive::resize(int newLength) // ресайзер 
{
    string* chat = new string[newLength];
    for (int index = 0; index < m_length; ++index)
    {
        chat[index] = m_chat[index];
    }
    delete[]m_chat;
    m_chat = chat;
    m_length = newLength;
}

//--------------------------------------------------------
IntArray::IntArray() {}    // = default;
IntArray::IntArray(int length) : m_length10(length) {}
IntArray::~IntArray()
{
    delete[] m_data;
}

void IntArray::resize(int newLength)
{
    int* data = new int[newLength];
    for (int index = 0; index < m_length10; ++index)
    {
        data[index] = m_data[index];
    }
    delete[] m_data;
    m_data = data;
    m_length10 = newLength;
}
//-------------------------------------
Chat::Chat()
{
    Sender = new IntArray(n0);
    Messenger = new stringMasive(n1);
    Recipient = new IntArray(n2);
}

Chat::~Chat()
{
    delete Sender;
    delete Messenger;
    delete Recipient;
}
//---------------------------------------------------------

Account::Account(string name) :_name(name) {}; // конструктор аккаунта с именем
Account::Account(string name, short id) :_name(name), _id(id) {}; // конструктор аккаунта с именем и возрастом
Account::Account(string name, string parole) :_name(name), _parole(parole) {};
Account::Account() {};
Account::~Account() {};

/*Chat* Account::createChat()
{
    Chat* T = new Chat;
    return T;
}*/

void Account::setMessage(Chat* T, int UserID) // написать в чат 
{

    cout << "\n\t\t INPUT THE MESSAGE :  ";
    string str;
    cin >> str;

    T->Sender->m_data[++i0] = _id;
    T->Sender->resize(++n0);

    T->Messenger->m_chat[++i1] = _name + " : " + str;
    T->Messenger->resize(++n1);

    T->Recipient->m_data[++i2] = UserID;
    T->Recipient->resize(++n2);
}

void Account::setMesAll(Chat* T) // написать в чат
{

    cout << "\n\t\t INPUT THE MESSAGE to ALL:  ";
    string strAll;
    cin >> strAll;

    T->Sender->m_data[++i0] = _id;
    T->Sender->resize(++n0);

    T->Messenger->m_chat[++i1] = _name + " writes to All : " + strAll;
    T->Messenger->resize(++n1);

    T->Recipient->m_data[++i2] = -1;// "-1" взял наобум, хоть "-3" , все что с "-1" это отпрвака всем;
    T->Recipient->resize(++n2);
}

void Account::GetMessage(Chat* T)	// прочитать  сообщение 
{
    int count = 0;
    for (int i = 0; i < n1; ++i)
    {
        if (T->Recipient->m_data[i] == _id || (T->Sender->m_data[i] != _id && T->Recipient->m_data[i] == -1))
            // проверка совпадения id получателя и если отпрвалено всем, то чтобы самому не отоброжалось сообщение всем
        {
            cout << "\n\n\t +++++      YOU HAVE A MESSAGE!! from ";
            cout << T->Messenger->m_chat[i] << endl;
            cout << "\n\t It's Id is : # " << T->Sender->m_data[i] << "   ++++++" << "\n" << endl;
            count++;
        }
    }
    if (!count)
    {
        cout << "\n\t\t\t\ ----    You Have No Messages  -----! \n" << endl;
    }
}
/*void Account::GetMessage(Chat* T)	// прочитать  сообщение
{
    int count = 0;
    for (int i = 0; i < n1; ++i)
    {
        if (T->Recipient->m_data[i] == _id)
        {
            cout << "\n\n\t +++++      YOU HAVE A MESSAGE!! from ";
            cout << T->Messenger->m_chat[i] << endl;
            cout << "\n\t It's Id is : # " << T->Sender->m_data[i] << "   ++++++" << "\n" << endl;
            count++;
        }
    }
    if (!count)
    {
        cout << "\n\t\t\t\ ----    You Have No Messages  -----! \n" << endl;
    }
}*/

//------------------------------------------------------
accMasive::accMasive() {};
accMasive::accMasive(int length) :acc_length(length) {};
accMasive::~accMasive()
{
    delete[]m_acc;
};

void accMasive::resize(int newLength) // ресайзер 
{
    Account* m1_acc = new Account[newLength];
    for (int index = 0; index < acc_length; ++index)
    {
        m1_acc[index] = m_acc[index];
    }
    delete[] m_acc;
    m_acc = m1_acc;
    acc_length = newLength;
}

/* void accMasive::setAccount()			// new account
 {

     cout << "\n\t\t INPUT your login:  ";
     string Name1;
     cin >> Name1;

     cout << endl;

     m_acc[++i3];
     m_acc[i3]._name = Name1;
     m_acc[i3]._id = i3;
     resize(++n3);
 }*/

void accMasive::setNewAccount(string newAcc, string newPar)			// new account
{
    m_acc[++i3]._name = newAcc;
    m_acc[i3]._parole = newPar;
    m_acc[i3]._id = i3;
    accMasive::resize(++n3);
}

