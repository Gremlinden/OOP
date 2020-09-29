#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <ostream>
using namespace std;

class Student
{
private:
	string m_name, m_surname, m_patronymic;
	vector<int> m_grades;

public:

	Student(string name, string surname, string patronymic, vector<int> grades);
	string Getname();
	string Getsurname();
	string Getpatronymic();
	vector<int> Getgrades();
	friend ostream& operator<<(std::ostream& os, const list<Student>::iterator& student);
	friend ostream& operator<<(std::ostream& os, const Student& student);

};


