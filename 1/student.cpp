#include "student.h"


Student::Student(string name, string surname, string patronymic, vector<int> grades) :
	m_name(name), m_surname(surname), m_patronymic(patronymic), m_grades(grades)
{}

std::ostream& operator<<(std::ostream& os, const list<Student>::iterator& student)
{
	os << (*student).Getsurname() << "  " << (*student).Getname() << "  " << (*student).Getpatronymic() << "  ";
	for (int i = 0; i < ((*student).Getgrades()).size(); i++)
		os << (*student).Getgrades()[i] << " ";
	cout << endl;
	return os;
}
std::ostream& operator<<(std::ostream & os, const Student & student)
{
	os << student.m_name << "  " << student.m_surname << "  " << student.m_patronymic << "  ";
	for (int i = 0; i < student.m_grades.size(); i++)
		os << student.m_grades[i] << " ";
	cout << endl;
	return os;
}