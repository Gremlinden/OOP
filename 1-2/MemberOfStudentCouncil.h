#pragma once
#include"Student.h"
#include "Common.h"

class MemberOfStudentCouncil: public Student
{
public:
	MemberOfStudentCouncil(const std::string& name, const std::string& surname, const std::string& patronymic, const std::map<std::string, std::vector<int>> &subjects_grades);
	virtual const int GradesExam(bool LastAttempt)const;
};


