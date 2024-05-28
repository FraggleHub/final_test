# Chat in C++

### Группа SF-40
FraggleHub - занимался сообщениями пользователям и всем пользователям.<br>
DionFikins - занимался отладкой, тимлид, тестирование приложения, класс пользователей.<br>
Autodefe21 - главное меню и класс пользователей.<br>

Chat.h stringMasive <br>

``` C++
class stringMasive { // класс сообщений
public:
  int m_length; // размер массива
  string* m_chat = new string[m_length]; // массив сообщений

  stringMasive(); // Конструктор
  stringMasive(int length);
  ~stringMasive(); // Деструктор

  void resize(); // Изменение размера массива
}
```
<br>

Chat.h IntArray <br> 

``` C++
class IntArray { // класс размерности
public:
  int m_length10; // размер массива
  int* m_data = new int[m_length10]; // массив пользователей отправителей-получателей
  IntArray(); // Конструктор
  IntArray(int length);
  ~IntArray(); // Деструктор

  void resizeSender(); // Изменение размера массива
  void resizeRecipient(); // Изменение размера массива отправителя-получателя
}
```
<br>

Chat.h Chat <br> 
``` C++
class Chat { // класс структуры
public:
  stringMasive* Messenger; // Контейнер сообщений
  IntArray* Sender // Контейнер отправителей
  IntArray* Recipient // Контейнер получателей
  Chat(); // Конструктор
  ~Chat(); // Деструктор
}
```
<br>

Chat.h Account <br>
``` C++
class Account { // Класс пользователей
public:
  bool _currentUser; // 
  string _name, _parole; // Имя, Пароль
  short _id; // id пользователя
  Account(); // Конструктор
  Account(string name); // Конструктор аккаунта с именем
  Account(string name, short id); // Конструктор
  Account(string name, string parole);
  ~Account(); // Деструктор

  void setLogin(string newLogin); // Новый логин
  void setPassword(string newPassword); // Новый пароль
  void setMessage(Chat* T, int UserID); // Написать конкретному пользователю по его id
  void setMesAll(Chat* T); // Написать в чат всем

  void GetMessage(Chat* T); // Прочитать сообщение
  void changeUser(string newLogin, string newPassword); // добавление прользователя
}
```
<br>

Chat.h <br>
``` C++
class accMassive {
public:
  int acc_length; // размер массива
  Account* m_acc = new Account[acc_length]; // массив пользователей

  accMassive(); // конструктор
  accMassive(int length); // конструктор с заданным размером массива
  ~accMassive(); // деструктор

  void resize(int newLength); // изменение размерности массива пользователей
  void setNewAccount(string newAcc, string newPar); // создать новый аккаунт
  void showAllUsers(); // показать всех пользователей в программе
  void updateCurrentUser(int Id); // обновление текущего пользователя
}
```
<br>

Chat.h <br>
``` C++
void Menu(); // главное меню программы
```
<br>
