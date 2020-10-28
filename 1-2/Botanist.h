#pragma once
#include"AbsStudent.h"
#include "Common.h"

class Botanist: public AbsStudent
{
public:
	Botanist(const std::string& name, const std::string& surname, const std::string& patronymic, const std::map<std::string,  std::vector<int>> &subjects_grades);
	virtual const int GradesExam(bool LastAttempt)const;

};

