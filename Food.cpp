#include <iostream>

using namespace std;

#include "Food.h"

Food::Food()
{
	no = 0, category = 0, price = 0, menu = "미정", catename = "미정카테고리";
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
	cout << " 번호 : " << no << " 메뉴 : " << menu << " 가격 : " << price << endl;
}

void Food::fullmenu()
{
	cout << " 번호 : " << no << " 메뉴 : " << menu << " 가격 : " << price << " 카테고리 번호 : " << category << " 카테고리 이름 : " << catename << endl;

}


void Food::setcate(int a, int b, string c)
{
	no = a, category = b, catename = c;
}
