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
	//����� ������� ����� ������ ������� �������� �� ��, ��� ���� ��� ������������ ��� ���.
	//if(acc.getLength() == 0)
	//		acc.resize();
	//else
	//		Users()

	int id;
	string login, pass, name;

	id = acc.getLength();
	cout << "��� ���������� ������������ ���������:" << endl;
	cout << "������� �����";
	cin >> login;
	cout << "\n������� ������";
	cin >> pass;
	cout << "\n������� ���";
	cin >> name;
	cout << "������������ ��������." << endl;
}

void Accounts::newUser(string login, string pass, string name) {
	resize();

	cout << "������� �����";
	cin >> login;
	cout << "\n������� ������";
	cin >> pass;
	cout << "\n������� ���";
	cin >> name;
	cout << "������������ ��������." << endl;
}
