#pragma once
#include <iostream>

using namespace std;

class Users {
protected:
	string _login, _pass, _name;
	int _id;
public:
	Accounts acc;
	Users() = default;
	Users(int id, string login, string pass, string name);
	~Users();
};

class Accounts {
protected:
	int _length;
	Users* user = new Users[_length];
public:
	Accounts() = default;
	Accounts(int length);
	~Accounts();

	void resize();
	int getLength() const;

	void newUser(string login, string pass, string name);
};