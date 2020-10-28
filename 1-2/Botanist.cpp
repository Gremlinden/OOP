#include "Botanist.h"

Botanist::Botanist(const std::string& name, const std::string& surname, const std::string& patronymic, const std::map<std::string, std::vector<int>> &subjects_grades):
	AbsStudent(name, surname, patronymic, subjects_grades) {}

const int Botanist::GradesExam(bool LastAttempt)const
{
	std::random_device rd;
	std::mt19937 mersenne(rd());
	return mersenne() % 2 + 4;
}

