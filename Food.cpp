#include <iostream>

using namespace std;

#include "Food.h"

Food::Food()
{
	no = 0, category = 0, price = 0, menu = "����", catename = "����ī�װ�";
}

Food::Food(int a, int b, int c, string d, string e)
{
	no = a, category = b, price = c, menu = d, catename = e;

}

void Food::regimenu(int a, int b, int c, string d, string e)
{
	no = a, category = b, price = c, menu = d, catename = e;
}
int Food::reshowno()
{
	return no;
}
string Food::reshowmenu()
{
	return menu;
}

string Food::reshowcatename()
{
	return catename;
}

int Food::reshowcate()
{
	return category;
}

int Food::reshowprice()
{
	return price;
}

void Food::showcate()
{
	cout << category << ". " << catename;
}

void Food::showcatemenu()
{
	cout << " ��ȣ : " << no << " �޴� : " << menu << " ���� : " << price << endl;
}

void Food::fullmenu()
{
	cout << " ��ȣ : " << no << " �޴� : " << menu << " ���� : " << price << " ī�װ� ��ȣ : " << category << " ī�װ� �̸� : " << catename << endl;

}


void Food::setcate(int a, int b, string c)
{
	no = a, category = b, catename = c;
}
