#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

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
		name = NULL;
		work = NULL;		
	}

	Person(int age)
	{
		this->age = age;	
		name = NULL;
		work = NULL;
	}

	Person(char *name)
	{
		work = NULL;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);	
	}
	
	Person(char *name, char *work)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);	
		this->work = new char[strlen(work) + 1];
		strcpy(this->work, work);	

	}
	
	Person(char *name, int age)
	{
		work = NULL;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;	
	}

	Person(char *name, int age, char *work)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);	
		this->work = new char[strlen(work) + 1];
		strcpy(this->work, work);	
		this->age = age;
	}

	~Person()
	{
		cout << "~Person" << endl;
		if(this->name)
			delete name;
		if(this->work)
			delete work;	
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


void Test()
{
	Person *per1 = new Person("Zhangsan", 16);
	//per1.PrintInfo();

	Person *per2 = new Person("Lisi", 24, "teacher");
	//per2.PrintInfo();

	Person per3("wangwu");
	//per3.PrintInfo();\
	
	delete per1;
}


int main(int argc, char **argv)
{
	Test();
	cout << "run test over" << endl;
	sleep(5);
	return 0;	
}
