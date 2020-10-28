#include "Grades.h"

Grades::Grades(const std::vector<int>& grades):m_grades(grades)
{}

const std::vector<int>& Grades::getGrades()const
{
	return m_grades;
}
const int Grades::getGradesExam()const
{
	return m_gradesExam;
}
void Grades::setGradesExam(int gradesExam)
{
	m_gradesExam = gradesExam;
}
const bool Grades::getAllowExam()const
{
	return m_allowExam;
}
void Grades::setAllowExam(bool allowExam)
{
	m_allowExam = allowExam;
}