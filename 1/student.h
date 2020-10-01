#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <ostream>
using namespace std;

class Student
{
private:
	const string m_name;
	const string m_surname;
	const string m_patronymic;
	const vector<int> m_grades;

public:

	Student(const string& name, const string& surname, const string& patronymic,const vector<int>& grades);

	const string& getName()const;
	const string& getSurname()const;
	const string& getPatronymic()const;
	const vector<int>& getGrades()const;

	friend ostream& operator<<(std::ostream& os, const Student& student);

};


