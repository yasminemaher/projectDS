#pragma once
#include <string.h>
#include <iostream>
using namespace std;
class account
{
private: 
	double balance;
public:
	account() { balance = 0;  }
	
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

	friend class client;
};
class client
{
private:
	account a;
	string name;
	bool vip;
public:
	
	client() {a.setBalance(0); }
	client(string s, bool importance) { name = s; a.setBalance(0); vip = importance; }
	//void closeAccount(){ ~a; }
	void transfer(client c, double amount)
	{
		if (amount<a.balance)
			cout << "Can't complete operation: balance doesn't cover amount";
		else
		{
			a.balance -= amount;
			c.a.balance += amount;
		}
	}
};
