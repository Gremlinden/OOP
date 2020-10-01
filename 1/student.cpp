#include "Student.h"

Student::Student(const string& name, const string& surname, const string& patronymic,const vector<int>& grades) :
	m_name(name), m_surname(surname), m_patronymic(patronymic), m_grades(grades)
{}

const string& Student::getName()const
{
	return m_name;
}
const string& Student::getSurname()const
{
	return m_surname;
}
const string& Student::getPatronymic()const
{
	return m_patronymic;
}
const vector<int>& Student::getGrades()const
{
	return m_grades;
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
	os << student.m_name << "  " << student.m_surname << "  " << student.m_patronymic << "  ";
	for (auto& n : student.m_grades)
		os << n << " ";
	cout << endl;
	return os;
}