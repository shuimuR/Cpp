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
		cout << "Person()" << endl;
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
		cout << "Person(char *name)" << endl;
		cout << "name is " << name << endl;	
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
	
	Person(Person &per)
	{
		cout << "Person(Person &)" << endl;
		this->name = new char[strlen(per.name) + 1];
		strcpy(this->name, per.name);	
		this->work = new char[strlen(per.work) + 1];
		strcpy(this->work, per.name);	
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

class Student
{
private:
	Person father;
	Person mother;
	int stu_id;
	
public:
	Student()
	{
		cout << "Student()"	<< endl;
	}	

	Student(int stu_id, char *father_name, char *mother_name, int FatherAge = 40, int MotherAge = 39) : mother(mother_name), father(father_name)
	{
		this->stu_id = stu_id;	
	}

	~Student()
	{
		cout << "~Student()" << endl;	
	}
};


int main(int argc, char **argv)
{
	Student stu1(36, "Tom", "Lily");
	return 0;	
}

