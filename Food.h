class Food {
	int no, price, category;
	string menu, catename;

public:
	Food();
	Food(int a, int b, int c, string d, string e);
	void regimenu(int a, int b, int c, string d, string e);
	int reshowno();
	string reshowmenu();
	string reshowcatename();
	int reshowcate();
	int reshowprice();
	void showcate();
	void showcatemenu();
	void fullmenu();
	void setcate(int a, int b, string c);
	static int money;
	static void summoney(int a)
	{
		money += a;
	};
	static void moneyreset()
	{
		money = 0;
	}

	static void cashpay(int a)
	{
		cout << money << "�� �� �����˴ϴ�." << endl;
		cout << "�� �� : " << a - money << "��" << endl;
	};
	static void cardpay()
	{
		cout << money << "���� �����˴ϴ�." << endl;
	};

};
#pragma once
