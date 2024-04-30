

#include "chat.h"

#include <iostream>
using namespace std;

int main()
{
    accMasive* Acc = new accMasive(n3); // создаем массив аккаунтов (пользователей)
    bool prog = 1; // перемееная для зацикливания выполнения программы
    bool account = 0; // переменная для зацикливания написания сообщения из аккаунта
    Chat* Chat1 = new Chat; // создаем "чат", объект с двумя вложенными массивами интежер (ID) для писателя и получателя
    // и один массив стрингов для сообщений, счетчики всех массивов ведется параллельно
    // т.е. как бы i1 = i2 = i3, но инкрементируются каждый отдельно т.е. ++i1 , следом ++i2 ,++i3;

    while (prog == true) // цикл выполнения программы, который по хорошему надо в процедуру или функцию затолкать наверно
    {
        while (account == false) // регистрируем аккаунт
        {
            cout << endl << "\t\t Hello! it's CHAT! \n" << endl;
            cout << " Do you have an account? 0/1 " << endl;
            cin >> account;
            if (account == false) // создаем несколько или много аккаунтов по циклу
            {
                cout << "\t Let's do registrating!! " << endl << endl;
                cout << "\t input your name / login : "; // имя-логин
                string newAccount, newParole;
                cin >> newAccount;
                cout << endl << "\t input your parole : "; // пароль
                cin >> newParole;

                Acc->setNewAccount(newAccount, newParole); // создакем, фиксируем анкету
                cout << endl << " \n\tThat's GOOD!! You have registrated!! " << endl << endl;

                // вывод заполненных данных и присвоенного ID
                cout << endl << "\t you are :  " << Acc->m_acc[++i3]._name << "  <-" << endl;
                cout << endl << "\t your ID is :  " << Acc->m_acc[i3]._id << "  <-" << endl;
                cout << endl << "\t you parole :  " << Acc->m_acc[i3]._parole << "  <-" << endl;
                cout << endl << "\nEXIT!! " << endl;
                // "выход", для регистрации новых юзеров или для входа после регистрации 
            }
        }
        int ideEnter;
        string newAcco, newPar;
        cout << "\t Let's do LOG IN!! " << endl << endl;
        cout << "\n\t input your ID : ";
        cin >> ideEnter; // вводим  ID пользователя

        cout << "\n\t input your login : ";
        cin >> newAcco; // логин-имя

        cout << "\n\t input your parole : ";
        cin >> newPar; // пароль

        // проверка логина и пароля
        if (Acc->m_acc[ideEnter]._name != newAcco || Acc->m_acc[ideEnter]._parole != newPar)
        {
            cout << "\n\t ERROR login or parole";
        }
        else // после входа в аккаунт прога показывает имя и ID пользователя
        {
            bool tr = true;
            while (tr)
            {
                cout << endl << "\n\t you are :  " << Acc->m_acc[ideEnter]._name << "  <-" << endl;
                cout << endl << "\t your ID is :  " << Acc->m_acc[ideEnter]._id << "  <-" << endl;
                // читаем сообщения, если они есть
                Acc->m_acc[ideEnter].GetMessage(Chat1);
                bool select = 0;
                cout << "Do you want write the message? 0/1 ";
                cin >> select; // пишем сообщение

                if (select)
                {
                    // для отправки всем вводим id <0, любой   -1 или -100 
                    cout << "\nInput recipient ID!  ->  Esli id < 0, to soobschenie otpravitsya vsem !!   ";
                    int id;
                    cin >> id; // пишем ID получателя
                    if (id >= 0)
                    {
                        Acc->m_acc[ideEnter].setMessage(Chat1, id);
                        // отправляем сообщение
                        cout << "\n Message sended!   By-By!! " << endl;
                        cout << "__________________________________\n\n" << endl;
                    }
                    else //  отправка сообщения всем
                    {
                        Acc->m_acc[ideEnter].setMesAll(Chat1);
                        // отправляем сообщение
                        cout << "\n Message sended to All!   By-By!! " << endl;
                        cout << "__________________________________\n\n" << endl;

                    }
                }
                cout << "\n\t\t   CONTINUE or exit from ACCOUNT? 1/0 " << endl;
                cin >> tr; // выходим из аккаунта 
            }
        }

        cout << "\n\n\t\t   CONTINUE Program or exit? 1/0 " << endl;
        cin >> prog; //выходим из программы

    }

    delete Chat1;
    delete Acc;

    return 0;
}