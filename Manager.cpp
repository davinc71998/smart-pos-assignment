#include <iostream>

using namespace std;

#include "Manager.h"

Manager::Manager()
{
	password = 0;
}

int Manager::showpass()
{
	return password;
}

void Manager::setpass(int a)
{
	password = a;
	cout << a << "�� �н����尡 ���� �Ǿ����ϴ�." << endl;
}