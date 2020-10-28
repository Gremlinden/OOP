#pragma once
#include "Common.h"
#include "Grades.h"


class AbsStudent
{
private:
	std::map<std::string, Grades*> m_subjects_grades;
	const std::string m_name;
	const std::string m_surname;
	const std::string m_patronymic;
public:
	AbsStudent(const std::string& name, const std::string& surname, const std::string& patronymic, const std::map<std::string, std::vector<int>> &subjects_grades);
	
	virtual ~AbsStudent();

	const std::string& getName()const;
	const std::string& getSurname()const;
	const std::string& getPatronymic()const;
	const std::map<std::string, Grades*>& getSubjectsGrades()const;

	void setSubjectsGrades(std::map<std::string, std::vector<int>> &subjects_grades);

	virtual const int GradesExam(bool LastAttempt)const = 0;

	friend std::ostream& operator<<(std::ostream& os, const AbsStudent& student);
};


