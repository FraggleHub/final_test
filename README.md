# Chat in C++

### Группа SF-40
FraggleHub - занимался сообщениями пользователям и всем пользователям.<br>
DionFikins - занимался отладкой, тимлид, тестирование приложения, класс пользователей.<br>
Autodefe21 - главное меню и класс пользователей.<br>

Class.h static int <br>

``` C++
static int i3 = -1; // начальный элемент id пользователя
static int n3 = 1; // начальный размер массива пользователей
```

<br>

Class.h stringMasive <br>

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

Class.h IntArray <br> 

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

Class.h Chat <br> 
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

Class.h Account
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
  void changeUser(string newLogin, string newPassword);
}
```
