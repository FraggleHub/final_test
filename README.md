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
class stringMasive {
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
class IntArray {
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
class Chat {
public:
  stringMasive* Messenger; // Контейнер сообщений
  IntArray* Sender // Контейнер отправителей
  IntArray* Recipient // Контейнер получателей
  Chat(); // Конструктор
  ~Chat(); // Деструктор
}
```
