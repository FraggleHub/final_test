#include  "chat.h"
#include <string>
#include <iostream>
using namespace std;

#pragma region global init

//static int i0 = -1;// элемент массива (отправитель Sender)
static int razmerSendera = 1; // размер массива (отправители Sender)

//static int i1 = -1;// элемент массива (сообщение Messenger)
static int razmerMessengera = 1;// размер массива (все сообщения Messenger)

//static int i2 = -1; //элемент массива(получатель Recipient)
static int razmerRecipienta = 1; // размер массива (получатели Recipient)

#pragma endregion

#pragma region stringMassive

stringMasive::stringMasive() {}
stringMasive::stringMasive(int length) :m_length(length) {}
stringMasive::~stringMasive() { delete[]m_chat; }

/*stringMasive::stringMasive(const stringMasive& other) : m_length(other.m_length) //
{
    m_chat = new string[m_length];
    for (int i = 0; i < m_length; ++i)
    {
        m_chat[i] = other.m_chat[i];
    }
} */

void stringMasive::resize() // ресайзер 
{
    string* chat = new string[++razmerMessengera];
    for (int index = 0; index < m_length; ++index)
    {
        chat[index] = m_chat[index];
    }
    delete[]m_chat;
    m_chat = chat;
    m_length = razmerMessengera;
}

#pragma endregion

#pragma region intArray

IntArray::IntArray() {}    // = default;
IntArray::IntArray(int length) : m_length10(length) {}
IntArray::~IntArray() { delete[] m_data; }

void IntArray::resizeSender() {
    int* data = new int[++razmerSendera];
    for (int index = 0; index < m_length10; ++index)
        data[index] = m_data[index];
    delete[] m_data;
    m_data = data;
    m_length10 = razmerSendera;
}

void IntArray::resizeRecipient()
{
    int* data = new int[++razmerRecipienta];
    for (int index = 0; index < m_length10; ++index)
        data[index] = m_data[index];
    delete[] m_data;
    m_data = data;
    m_length10 = razmerRecipienta;
}

#pragma endregion

#pragma region chat

Chat::Chat()
{
    Sender = new IntArray(razmerSendera);
    Messenger = new stringMasive(razmerMessengera);
    Recipient = new IntArray(razmerRecipienta);
}

Chat::~Chat()
{
    delete Sender;
    delete Messenger;
    delete Recipient;
}

#pragma endregion

#pragma region account

Account::Account(string name) :_name(name) {} // конструктор аккаунта с именем
Account::Account(string name, short id) :_name(name), _id(id) {} // конструктор аккаунта с именем и возрастом
Account::Account(string name, string parole) :_name(name), _parole(parole) {}
Account::Account() {}
Account::~Account() {}

/*Chat* Account::createChat()
{
    Chat* T = new Chat;
    return T;
}*/

void Account::setLogin(string newLogin) { _name = newLogin; }

void Account::setPassword(string newPassword) { _parole = newPassword; }

void Account::setMessage(Chat* T, int UserID) // написать в чат 
{
    cout << "\n\t\t Введите сообщение :  ";
    string str;
    getline(cin >> ws, str);

    T->Sender->m_data[razmerSendera-1] = _id;
    T->Sender->resizeSender();

    T->Messenger->m_chat[razmerMessengera-1] = _name + " : " + str;
    T->Messenger->resize();

    T->Recipient->m_data[razmerRecipienta-1] = UserID;
    T->Recipient->resizeRecipient();
}

void Account::setMesAll(Chat* T) // написать в чат
{
    cout << "\n\t\t Введите сообщение для всех пользователей:  ";
    string strAll;
    getline(cin >> ws, strAll); 

    T->Sender->m_data[razmerSendera - 1] = _id;
    T->Sender->resizeSender();

    T->Messenger->m_chat[razmerMessengera - 1] = _name + " : " + strAll;
    T->Messenger->resize();

    T->Recipient->m_data[razmerRecipienta - 1] = -1; // "-1" взял наобум, хоть "-3" , все что с "-1" это отпрвака всем;
    T->Recipient->resizeRecipient();
}

void Account::GetMessage(Chat* T)	// прочитать  сообщение 
{
    int count = 0;
    for (int i = 0; i < razmerMessengera; ++i)
        if (T->Recipient->m_data[i] == _id || (T->Sender->m_data[i] != _id && T->Recipient->m_data[i] == -1))
            // проверка совпадения id получателя и если отпрвалено всем, то чтобы самому не отоброжалось сообщение всем
        {
            cout << "\n\n\t +++++    Новое сообщение от  ";
            cout << T->Messenger->m_chat[i] << endl;
          //  cout << "\n\t It's Id is : # " << T->Sender->m_data[i] << "   ++++++" << "\n" << endl;
            count++;
        }
    if (!count) cout << "\n\t\t\t\ ----    Нет новых сообщений  -----! \n" << endl;
}
void Account::changeUser(string newLogin, string newPassword)
{
    cout << "Введите новый логин: ";
    cin >> newLogin;
    setLogin(newLogin);
    cout << "Введите новый пароль: ";
    cin >> newPassword;
    setPassword(newPassword);
    cout << "Данные пользователя успешно изменены!" << endl;
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

#pragma endregion

#pragma region accMassive

accMasive::accMasive() {}
accMasive::accMasive(int length) :acc_length(length) {}
accMasive::~accMasive() { delete[]m_acc; }

void accMasive::resize(int newLength) // ресайзер 
{
    Account* m1_acc = new Account[newLength];
    for (int index = 0; index < acc_length; ++index)
        m1_acc[index] = m_acc[index];
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
    for (int i = 0; i < n3; ++i)
    {
        if (m_acc[i]._name == newAcc)
        {
            std::cout << "\nОшибка! Пользователь с логином " << newAcc << " уже существует. Пожалуйста, выберите другой логин." << std::endl;
            return;
        }
    }
    m_acc[++i3]._name = newAcc;
    m_acc[i3]._parole = newPar;
    
    m_acc[i3]._id = i3;
    m_acc[i3]._currentUser = false;
    accMasive::resize(++n3);
    std::cout << "\nАккаунт успешно зарегистрирован! Ваш ID: " << m_acc[i3]._id << endl;
}

void accMasive::showAllUsers()
{
    std::cout << "Все зарегистрированные пользователи:" << std::endl;
    for (int i = 0; i < n3; ++i)
    {
        if (!m_acc[i]._name.empty())
        {
            std::cout << "ID: " << m_acc[i]._id << " Логин: " << m_acc[i]._name;
            if (m_acc[i]._currentUser)
            {
                std::cout << " (Вы)";
            }
            std::cout << std::endl;
        }
    }
}

void accMasive::updateCurrentUser(int Id) //Метод для обновления текущего пользователя 
{
    for (int i = 0; i < n3; ++i)
        if (m_acc[i]._currentUser)
            m_acc[i]._currentUser = false;
    m_acc[Id]._currentUser = true;
}

#pragma endregion


void Menu()
{
   // string messageText;
    string newAccount, newParole;
    accMasive* Acc = new accMasive(n3);
    Chat* Chat1 = new Chat;
    bool exitApp = true;
    int choice, choice1, Id, recipientId;
    string newLogin, newPassword;
    while (exitApp) {
        string input;
        std::cout << "Добро пожаловать в чат!!!" << endl;
        std::cout << "1. Регистрация" << endl;
        std::cout << "2. Вход в аккаунт" << endl;
        std::cout << "3. Выйти из приложения" << endl;
        std::cout << "Выберите действие: ";

        std::cin >> input;

        try {
            choice = stoi(input);
            switch (choice) {
            case 1:
                std::cout << "\t Регистрация!! " << endl << endl;
                std::cout << "\t Введите ваш логин : ";

                std::cin >> newAccount;
                std::cout << endl << "\t Введите пароль : ";
                std::cin >> newParole;

                Acc->setNewAccount(newAccount, newParole);
                break;
            case 2: {
                string text;

                std::cout << "\nВведите ваш ID: ";
                std::cin >> text;
                Id = stoi(text);

                std::cout << "Введите логин: ";
                std::cin >> newAccount;
                std::cout << "Введите пароль: ";
                std::cin >> newParole;

                if (Acc->m_acc[Id]._name == newAccount && Acc->m_acc[Id]._parole == newParole) {
                    Acc->updateCurrentUser(Id);
                    bool logoutAccount = true;

                    while (logoutAccount) {

                        std::cout << "1. Отправить сообщение всем" << endl;
                        std::cout << "2. Отправить сообщение конкретному пользователю" << endl;
                        std::cout << "3. Просмотреть полученные сообщения" << endl;
                        std::cout << "4. Изменение Логина и Пароля" << endl;
                        std::cout << "5. Выйти из аккаунта" << endl;
                        std::cout << "Выберите действие: ";
                        std::cin >> input;

                        choice1 = stoi(input);

                        switch (choice1) {
                        case 1:
                            // cout << "Введите текст сообщения для отправки всем: ";
                            // cin.ignore();
                            // getline(cin, messageText);

                            Acc->m_acc[Id].setMesAll(Chat1);

                            std::cout << "Сообщение успешно отправлено всем пользователям!" << endl;

                            break;
                        case 2:
                            Acc->showAllUsers();
                            std::cout << "Введите ID получателя: ";
                            std::cin >> input;

                            recipientId = stoi(input);

                            if (recipientId >= 0 && recipientId < n3) {
                                // cout << "Введите текст сообщения для отправки пользователю - " << endl;
                                // cin.ignore();
                                // getline(cin, messageText);

                                Acc->m_acc[Id].setMessage(Chat1, recipientId); // отправляем сообщение конкретному пользователю
                                std::cout << "Сообщение успешно отправлено " << endl;
                            }
                            else
                                std::cout << "Получатель с ID " << recipientId << " не существует. Попробуйте снова." << endl;
                            break;
                        case 3:
                            Acc->m_acc[Id].GetMessage(Chat1);
                            break;
                        case 4:
                            Acc->m_acc[Id].changeUser(newLogin, newPassword);
                            break;
                        case 5:
                            logoutAccount = false;
                            break;
                        default:
                            std::cout << "Неверный выбор. Попробуйте снова." << endl;
                        }
                    }
                }
                else
                    std::cout << "Ошибка входа. Проверьте логин и пароль." << endl;
                break;
            }
            case 3:
                exitApp = false;
                delete Acc;
                delete Chat1;
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << endl;
            }
        }
        catch (invalid_argument const &e) {
            std::cout << "Ошибка! \nНеверный формат числа!" << endl;
        }
        catch (out_of_range const& e) {
            std::cout << "Ошибка! \nЧисло вне диапазона int" << endl;
        }
    }
}