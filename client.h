#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class client
{
private:
	double balance;
	string name;
	bool vip;
public:
	
	client() {b=0; }
	client(string s, bool importance) { name = s; b=0 ; vip = importance; }
	//void closeAccount(){ ~a; }
	void transfer(client c, double amount)
	{
		if (amount<balance)
			cout << "Can't complete operation: balance doesn't cover amount";
		else
		{
			balance -= amount;
			c.balance += amount;
		}
	}
	
	
	void setBalance(double b) { balance = b; }
	double getBalance() { return balance; }
	void withdraw(double w) 
	{
		if (w<balance)
			cout << "Can't complete operation: balance doesn't cover request";
		else
			balance -= w;
	}
	void depose(double d) { balance += d; }
};
