#include <iostream>
#include "chat.h"
using namespace std;

static int i3 = -1; // for aacount massive// element v massive
static int n3 = 1; //razmer massiva

class accMasive //
{
public:
    int acc_length;
    Account* m_acc = new Account[acc_length];

    accMasive() {};
    accMasive(int length) :acc_length(length) {};
    ~accMasive()
    {
        delete[]m_acc;
    };

    void resize(int newLength) // ресайзер из того же контейнера
    {
        Account* m1_acc = new Account[newLength];
        for (int index = 0; index < acc_length; ++index)
        {
            m1_acc[index] = m_acc[index];
        }
        delete[]m_acc;
        m_acc = m1_acc;
        acc_length = newLength;
    }

    void setAccount()			// new account
    {

        cout << "\n\t\t INPUT your login:  ";
        string Name1;
        cin >> Name1;

        cout << endl;

        m_acc[++i3];
        m_acc[i3]._name = Name1;
        m_acc[i3]._id = i3;
        resize(++n3);
    }

    void setNewAccount(string newAcc, string newPar)			// new account
    {

        //cout << "\n\t\t INPUT your login:  ";
        //string Name1;
       // cin >> Name1;

        //cout << endl;

        m_acc[++i3];
        m_acc[i3]._name = newAcc;
        m_acc[i3]._parole = newPar;
        m_acc[i3]._id = i3;
        resize(++n3);
    }

};

int main()
{
    accMasive* Acc = new accMasive(n3);
    bool prog = 1;
    bool account = 0;
    Chat* Chat1 = new Chat;

    while (prog == true)
    {
        while (account == false)
        {
            cout << endl << "\t\t Hello! it's CHAT! \n" << endl;
            cout << " Do you have an account? 0/1 " << endl;
            // short account;
            cin >> account;
            if (account == false)
            {
                cout << "\t Let's do registrating!! " << endl << endl;
                cout << "\t input your name / login : ";
                string newAccount, newParole;
                cin >> newAccount;

                cout << endl << "\t input your parole : ";
                cin >> newParole;

                Acc->setNewAccount(newAccount, newParole);
                cout << endl << " \n\tThat's GOOD!! You have registrated!! " << endl << endl;

                cout << endl << "\t you are :  " << Acc->m_acc[i3]._name << "  <-" << endl;
                cout << endl << "\t your ID is :  " << Acc->m_acc[i3]._id << "  <-" << endl;
                cout << endl << "\t you parole :  " << Acc->m_acc[i3]._parole << "  <-" << endl;
                cout << endl << "EXIT!! Let's go on!! " << endl;
            }
        }
        int ideEnter;
        string newAcco, newPar;
        cout << "\t Let's do LOG IN!! " << endl << endl;
        cout << "\n\t input your ID : ";
        cin >> ideEnter;

        cout << "\n\t input your login : ";
        cin >> newAcco;

        cout << endl << "\n\t input your parole : ";
        cin >> newPar;

        if (Acc->m_acc[ideEnter]._name != newAcco || Acc->m_acc[ideEnter]._parole != newPar)
        {
            cout << "ERROR login or parole";
        }
        else
        {

            bool tr = true;
            while (tr)
            {
                cout << endl << "\t you are :  " << Acc->m_acc[ideEnter]._name << "  <-" << endl;
                cout << endl << "\t your ID is :  " << Acc->m_acc[ideEnter]._id << "  <-" << endl;
                //int hero;
               // cout << "\n\tInput USER id from 0 to 15 \t" << endl;
                //  cout << "\n USER # 1 is " DIMA, \n\n USER # 2 is LENA, \n\n USER # 3 is THE_CLOWN  " << endl;
                //cin >> hero;
                //cout << endl << "you are " << Acc->m_acc[hero]._name << endl;

                Acc->m_acc[ideEnter].GetMessage(Chat1);
                bool select = 0;
                cout << "Do you want write the message? 0/1 ";
                cin >> select;
                if (select)
                {
                    cout << "\nInput recipient ID from 0 to 2!    ";
                    int id;
                    cin >> id;
                    Acc->m_acc[ideEnter].setMessage(Chat1, id);
                    cout << "\n Message sended!   By-By!! " << endl;
                    cout << "__________________________________\n\n" << endl;
                }
                cout << "\n\t\t   CONTINUE or exit from ACCOUNT? 1/0 " << endl;
                cin >> tr;

            }


            //accMasive *Acc = new accMasive(n3);

            /*short accountPlus = 0;

            while (accountPlus < 3)
            {
                Acc->setAccount();

                //cout << "\n\t\t   CONTINUE or exit? 1/0 " << endl;
                //cin >> accountPlus;
                accountPlus++;
            }
            */
            /*Acc.resize(++n3);
            Account Dima("dima", i3+1);
            Acc.m_acc[++i3] = Dima;

            Acc.resize(++n3);
            Account Lena("lena", i3+1);
            Acc.m_acc[++i3] = Lena;

            Acc.resize(++n3);
            Account Itt("The_clown", i3+1);
            Acc.m_acc[++i3] = Itt;*/

            /*for (int z = 0; z < Acc->acc_length - 1; ++z)
            {
                cout << endl << Acc->m_acc[z]._name << " \t id " << Acc->m_acc[z]._id;
            }
            //cout << endl << Acc.m_acc[0]._name << " \t id " << Acc.m_acc[0]._id;
            //cout << endl << Acc.m_acc[1]._name << " \t id " << Acc.m_acc[1]._id;
            //cout << endl << Acc.m_acc[2]._name << " \t id " << Acc.m_acc[2]._id;

            //Acc.m_acc[0] = Dima;
            //Acc.m_acc[1] = Lena;
            */
            //----------------------------------------------------
                /*Account* He = new Account("DIMA", 1);
               Account* She = new Account("LENA", 2);
                Account* It = new Account("THE_CLOWN", 3);
               Chat* Chat1 = He->createChat();*/

               // Chat* Chat1 = new Chat;
        }
        /* bool tr = true;
         while (tr)
         {
             int hero;
             cout << "\n\tInput USER id from 0 to 2 \t" << endl;
             //  cout << "\n USER # 1 is " DIMA, \n\n USER # 2 is LENA, \n\n USER # 3 is THE_CLOWN  " << endl;
             cin >> hero;
             cout << endl << "you are " << Acc->m_acc[hero]._name << endl;

             Acc->m_acc[hero].GetMessage(Chat1);
             bool select = 0;
             cout << "Do you want write the message? 0/1 ";
             cin >> select;
             if (select)
             {
                 cout << "\nInput recipient ID from 0 to 2!    ";
                 int id;
                 cin >> id;
                 Acc->m_acc[hero].setMessage(Chat1, id);
                 cout << "\n Message sended!   By-By!! " << endl;
                 cout << "__________________________________\n\n" << endl;
             }
     */
     /*      switch (hero)
           {
               case 1:
                   {
                       cout << "\n\t**   YOU are " << He->_name << "  **" << endl << endl;
                       He->GetMessage(Chat1);

                       bool select = 0;
                       cout << "Do you want write the message? 0/1 ";
                       cin >> select;
                       if (select)
                           {
                           cout << "\nInput recipient ID = 2 or 3!    ";
                           int id;
                           cin >> id;
                           He->setMessage(Chat1, id);
                           cout << "\n Message sended!   By-By!! " << endl;
                           cout << "__________________________________\n\n" << endl;
                           }
                       break;
                   }

               case 2:
               {
                   cout << " \n\t**   YOU are " << She->_name << "  **" << endl << endl;
                   She->GetMessage(Chat1);

                   bool select = 0;
                   cout << "Do you want write the message? 0/1 ";
                   cin >> select;
                   if (select)
                   {
                       cout << "\nInput recipient ID = 1 or 3!  ";
                       int id;
                       cin >> id;
                       She->setMessage(Chat1, id);
                       cout << "\n Message sended!   By-By!! " << endl;
                       cout << "__________________________________\n\n" << endl;
                   }

                   break;
               }

               case 3:
               {
                   cout << "\n\t**      YOU are " << It->_name << "  **" << endl << endl;
                   It->GetMessage(Chat1);

                   bool select = 0;
                   cout << "Do you want write the message? 0/1 " ;
                   cin >> select;
                   if (select)
                   {
                       cout << "\n\nInput recipient ID = 1 or 2!   ";
                       int id;
                       cin >> id;
                       It->setMessage(Chat1, id);
                       cout << "\n Message sended!   By-By!! " << endl;
                       cout << "__________________________________\n\n" << endl;
                   }
                   break;
               }

               default:
               {break; }
           } */
        cout << "\n\t\t   CONTINUE or exit? 1/0 " << endl;
        cin >> prog;

    }

    // delete He;
    // delete She;
    // delete It;
    delete Chat1;
    delete Acc;

    return 0;
}