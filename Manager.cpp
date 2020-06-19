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
	cout << a << "로 패스워드가 설정 되었습니다." << endl;
}