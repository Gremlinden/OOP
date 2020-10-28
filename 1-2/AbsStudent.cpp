#include"AbsStudent.h"

AbsStudent::AbsStudent(const std::string& name, const std::string& surname, const std::string& patronymic,const std::map<std::string, std::vector<int>> &subjects_grades):
	m_name(name), m_surname(surname), m_patronymic(patronymic)
{
	for(auto &k: subjects_grades)
	{
		this->m_subjects_grades.insert(std::make_pair(k.first, new Grades{ k.second }));
	}
}
AbsStudent::~AbsStudent()
{
	for (const auto& k : m_subjects_grades)
	{
		delete k.second;
	}
}

const std::string& AbsStudent::getName()const
{
	return m_name;
}
const std::string& AbsStudent::getSurname()const
{
	return m_surname;
}
const std::string& AbsStudent::getPatronymic()const
{
	return m_patronymic;
}
const std::map<std::string, Grades*>& AbsStudent::getSubjectsGrades()const
{
	return this->m_subjects_grades;
}

void AbsStudent::setSubjectsGrades(std::map<std::string, std::vector<int>> &subjects_grades)
{
	for (const auto& k : subjects_grades)
	{
		this->m_subjects_grades.insert(std::make_pair(k.first, new Grades{ k.second }));
	}
}


std::ostream& operator<<(std::ostream& os, const AbsStudent& student)
{
	os << "FIO: " << student.m_name << "  " << student.m_surname << "  " << student.m_patronymic << "  " << std::endl;
	os << "Subjects: ";
	for (const auto& k : student.m_subjects_grades)
	{
		if ((k.second->getGradesExam() > 2 ) && (k.second->getGradesExam() <= 5))
		{
			os << "'" << k.first << "'" << " Grades for Semester [ ";
			for (const auto& k : k.second->getGrades())
				os << k << " ";
			os << "]  Grades for Exam " << k.second->getGradesExam();
		}else
		{
			os << "'" << k.first << "'" << " Grades for Semester [ ";
			for (const auto& k : k.second->getGrades())
				os << k << " ";
			os << "]  Grades for Exam - No Grades for Exam yet";
		}
		os << "\t  ";

	}

	std::cout << std::endl;
	return os;
}