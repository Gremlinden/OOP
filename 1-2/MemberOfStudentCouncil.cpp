#include "MemberOfStudentCouncil.h"


MemberOfStudentCouncil::MemberOfStudentCouncil(const std::string& name, const std::string& surname, const std::string& patronymic, const std::map<std::string, std::vector<int>> &subjects_grades):
 Student(name, surname, patronymic, subjects_grades)
{}

const int MemberOfStudentCouncil::GradesExam(bool LastAttempt)const
{
	if(LastAttempt == true)
	{
		return 3;
	}
	return this->Student::GradesExam(LastAttempt);
}

