#include <iostream>
#include <Windows.h>
#include  "chat.h"

using namespace std;

int main()
{
#pragma region setting russian chat
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#pragma endregion

    Menu();
}