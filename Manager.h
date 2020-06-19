class Manager {
	int password;
public:
	Manager();
	int showpass();
	void setpass(int a);
	static int total;
	static void settotal(int a)
	{
		total += a;
	};
	static void cashsettle()
	{
		total = 0;
	};
};
#pragma once
