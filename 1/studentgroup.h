#pragma once
#include "Student.h"

class StudentGroup
{
private:
	vector<Student*> m_students;
	const int m_studet_numbers;
	const string m_studentgroupnumber;
	int i = 0;
public:

	StudentGroup(const int studet_numbers, const string& studentgroupnumber);

	void AddStudent(const Student& student);
	
	void AddStudent(const string& name, const string& surname, const string& patronymic, const vector<int>& grades);
	
	void RemoveStudent(Student* student);

	void SortFIO();
	void Sortgrades();
	
	Student* Find(const string& name, const string& surname, const string& patronymic);

	friend ostream& operator<<(std::ostream & os, const StudentGroup & students);
};


