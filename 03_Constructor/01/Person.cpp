#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class Person
{
private:
	char *name;
	int age;
	char *work;

public:	
	Person()
	{
		
	}

	Person(int age)
	{
		this->age = age;	
	}

	Person(char *name)
	{
		cout << "Using Person(Char *name)" << endl;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);	
	}
	
	Person(char *name, char *work)
	{
		this->name = name;	
		this->work = work;
	}
	
	Person(char *name, int age)
	{
		this->name = name;	
		this->age = age;
	}

	Person(char *name, int age, char *work)
	{
		this->name = name;	
		this->age = age;
		this->work = work;
	}

	void SetName(char *n)
	{
		name = n;	
	}

	void SetWork(char *n)
	{
		work = n;	
	}

	int SetAge(int a)
	{
		if(a < 0 || a > 150)
		{
			age = 0;
			return -1;	
		}
		else
			age = a;
		return 0;
	}

	void PrintInfo()
	{
		printf("name = %s, age = %d, work is %s\n", name, age, work);	
	}
};

int main(int argc, char **argv)
{
	Person per1("Zhangsan", 16);
	per1.PrintInfo();

	Person per2("Lisi", 24, "teacher");
	per2.PrintInfo();

	Person per3("wangwu");
	per3.PrintInfo();

	return 0;
}
