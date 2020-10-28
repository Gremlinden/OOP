#include "Common.h"
#include "AbsStudent.h"

class Student:public AbsStudent
{
public:
	Student(const std::string& name, const std::string& surname, const std::string& patronymic, const std::map<std::string, std::vector<int>> &subjects_grades);

	virtual const int GradesExam(bool LastAttempt)const;
};

