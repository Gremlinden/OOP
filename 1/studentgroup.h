#pragma once
#include "student.h"

class StudentGroup
{
private:
	list<Student>* m_students;
	const int m_studet_numbers;
	string m_studentgroupnumber;
	static int i;
public:

	StudentGroup(int studet_numbers, string studentgroupnumber);

	void AddStudent(Student student);

	void AddStudent(string name, string surname, string patronymic, vector<int> grades);

	void RemoveStudent(list<Student>::iterator student);

	void SortFIO();

	void Sortgrades();

	list<Student>::iterator Fine(string name, string surname, string patronymic);

	friend string Student::Getname();
	friend string Student::Getsurname();
	friend string Student::Getpatronymic();
	friend vector<int> Student::Getgrades();
	friend ostream& operator<<(std::ostream& os, const StudentGroup& students);

};


