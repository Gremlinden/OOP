#pragma once
#include "Common.h"
class Grades
{
private:
	const std::vector<int> m_grades;
	int m_gradesExam;
	bool m_allowExam;
public:
	Grades(const std::vector<int>& grades);
	const std::vector<int>& getGrades()const;
	const int getGradesExam()const;
	void setGradesExam(int gradesExam);
	const bool getAllowExam()const;
	void setAllowExam(bool allowExam);
};


