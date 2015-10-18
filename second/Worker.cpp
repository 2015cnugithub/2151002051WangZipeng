// Worker.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Worker
{
private:
	string name;
	char sex;
	int age;
	int pay_per_hour;
public:
	Worker(){}
	Worker(string n, char s, int a, int pay);
	virtual void Compute_pay(double hours){}
	friend ostream &operator<<(ostream &out, Worker &worker);
	int getPay_per_hour() { return pay_per_hour; }
	void set(string n, char s, int a, int pay);
	void show();
	~Worker(){}

};
Worker::Worker(string n, char s, int a, int pay)
{
	name = n;
	sex = s;
	age = a;
	pay_per_hour=pay;

}
void Worker::set(string n, char s, int a, int pay)
{
	name = n;
	sex = s;
	age = a;
	pay_per_hour = pay;
}

void Worker::show()
{
	cout << "Name:" << name << endl;
	cout << "Sex:" << sex << endl;
	cout << "Age:" << age << endl;
	cout << "Pay Per Hour:" <<pay_per_hour << " US$" << endl;
}
ostream &operator<<(ostream &out, Worker &worker)
{
	cout << "Name:" << worker.name << endl;
	cout << "Sex:" << worker.sex << endl;
	cout << "Age:" << worker.age << endl;
	cout << "Pay Per Hour:" << worker.pay_per_hour <<" US$"<< endl;
	return out;
}

class HourlyWorker :public Worker
{
public :
	HourlyWorker(){}
	HourlyWorker(string n, char s, int a, int pay) :Worker(n, s, a, pay) {}
	void Compute_pay(double hours);
};

void HourlyWorker::Compute_pay(double hours)
{
	double pays=0;
	if (hours <= 40) pays = hours*getPay_per_hour();
	if (hours > 40) pays = 40 * getPay_per_hour(), pays += 1.5*(hours - 40)*getPay_per_hour();
	cout << "Pay:" << pays << " US$" << endl;
}
class SalariedWorker :public Worker
{
public:
	SalariedWorker(){}
	SalariedWorker(string n, char s, int a, int pay) :Worker(n, s, a, pay) {}
	void Compute_pay(double hours);
};

void SalariedWorker::Compute_pay(double hours)
{
	double pays = 0;
	if (hours>=35) pays = 40*getPay_per_hour();
	if (hours<35) pays = hours * getPay_per_hour(), pays += 0.5*(35-hours)*getPay_per_hour();
	cout << "Pay:" << pays << " US$" << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string s; 
	char f;
	int a;
	int pay_hour;
	int i;
	HourlyWorker *hourlyworkers = new HourlyWorker[3];
	for (i = 0; i < 3; i++)
	{
		cout << "Input Hourlyworker!" << endl;
		cout << "NAME:"; cin >> s;
		cout << "SEX"; cin >> f;
		cout << "AGE"; cin >> a;
		cout << "PAY PER HOUR"; cin >> pay_hour;
		(hourlyworkers + i)->set(s, f, a, pay_hour);

	}
	SalariedWorker *salariedworkers = new SalariedWorker[2];
	for (i = 0; i < 2; i++)
	{
		cout << "Input Salariedworker!" << endl;
		cout << "NAME:"; cin >> s;
		cout << "SEX"; cin >> f;
		cout << "AGE"; cin >> a;
		cout << "PAY PER HOUR"; cin >> pay_hour;
		(salariedworkers + i)->set(s, f, a, pay_hour);

	}
	Worker *workers[5];
	for (i = 0; i < 3; i++)
	{
		workers[i] = (hourlyworkers + i);
	}
	for (i = 3; i < 5; i++)
	{
		workers[i] = (salariedworkers + i - 2);
	}
	for (i = 0; i < 5; i++)
	{
		cout << "Nomber " << i << endl;
		workers[i]->show();
	}

	cout << "Choose Which one?Input NO.(1-5)" << endl;
	cin >> i;
	cout << "Input worker hours" << endl;
	int hours;
	cin >> hours;
	workers[i]->Compute_pay(hours);
	delete[] workers;
	return 0;
}

