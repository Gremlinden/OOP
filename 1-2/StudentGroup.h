#pragma once
#include "AbsStudent.h"
#include "Botanist.h"
#include "MemberOfStudentCouncil.h"
#include "Common.h"

class StudentGroup
{
private:
	std::vector<AbsStudent*> m_students;
	const int m_studet_numbers;
	const std::string m_studentgroupnumber;

public:
	StudentGroup(const int studet_numbers, const std::string& studentgroupnumber);

	void AddStudent(AbsStudent& student);
	std::vector<AbsStudent*>::iterator BeginStudentGroup();
	std::vector<AbsStudent*>::iterator EndStudentGroup();

	void SortFIO();
	void Sortgrades(const std::string subject);
	AbsStudent* Find(const std::string&, const std::string& surname, const std::string& patronymic)const;
	void RemoveStudent(AbsStudent* student);

	friend std::ostream& operator<<(std::ostream& os, const StudentGroup& students);
};

