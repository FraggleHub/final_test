#include "Accounts.h"

Accounts::Accounts(int length) : _length(length) { }
Accounts::~Accounts() {	delete[] user; }
int Accounts::getLength() const {
	return _length;
}
void Accounts::newUser(string login, string pass, string name)
{
}
void Accounts::resize() { _length++; }

Users::Users() {
	//перед вызовом этого метода сделать проверку на то, что есть там пользователи или нет.
	//if(acc.getLength() == 0)
	//		acc.resize();
	//else
	//		Users()

	int id;
	string login, pass, name;

	id = acc.getLength();
	cout << "Для добавления пользователя требуется:" << endl;
	cout << "Введите логин";
	cin >> login;
	cout << "\nВведите пароль";
	cin >> pass;
	cout << "\nВведите имя";
	cin >> name;
	cout << "Пользователь добавлен." << endl;
}

void Accounts::newUser(string login, string pass, string name) {
	resize();

	cout << "Введите логин";
	cin >> login;
	cout << "\nВведите пароль";
	cin >> pass;
	cout << "\nВведите имя";
	cin >> name;
	cout << "Пользователь добавлен." << endl;
}
