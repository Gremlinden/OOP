#include "StudentGroup.h"


StudentGroup::StudentGroup(const int studet_numbers, const std::string& studentgroupnumber) : 
	m_studet_numbers(studet_numbers), m_studentgroupnumber(studentgroupnumber)
{}

void StudentGroup::AddStudent(AbsStudent& student)
{
	if (m_studet_numbers > this->m_students.size()) {
		this->m_students.push_back(&student);
	}
	else
		throw std::exception(std::string("Group " + this->m_studentgroupnumber + " is full").c_str());
}

void StudentGroup::RemoveStudent(AbsStudent* student)
{
	this->m_students.erase(find(this->m_students.begin(), this->m_students.end(), student));
}

AbsStudent* StudentGroup::Find(const std::string & name, const std::string & surname, const std::string & patronymic)const
{
	for(const auto& k: this->m_students)
	{
		if ((k->getName() == name) && (k->getSurname() == surname) && (k->getPatronymic() == patronymic))
		{
			return k;
		}
	}
}

const int comparison(const std::string a, const std::string b)
{
	if (a.length() == b.length())
	{
		int n;
		if (a.length() >= b.length())
			n = b.length();
		else
			n = a.length();
		for (int i = 0; i < n; i++)
		{
			if (tolower(a[i]) < tolower(b[i]))
				return 1;
			else if (tolower(a[i]) > tolower(b[i]))
				return 0;
		}
		if (a < b)
			return 0;
		else if (a > b)
			return 1;
		return 3;
	}
	else if (a.length() > b.length())
		return 1;
	else
		return 0;
}

void StudentGroup::SortFIO()
{
	sort(this->m_students.begin(), this->m_students.end(), [](AbsStudent * a, AbsStudent * b) {
		int n = comparison(a->getName(), b->getName());
		if (n != 3) {
			return n;
		}
		n = comparison(a->getSurname(), b->getSurname());
		if (n != 3) {
			return n;
		}
		n = comparison(a->getPatronymic(), b->getPatronymic());
		if (n != 3) {
			return n;
		}
		return 0;
		});
}
void StudentGroup::Sortgrades(const std::string subject)
{

	sort(this->m_students.begin(), this->m_students.end(), [&](AbsStudent * a, AbsStudent * b)
		{
			if ((a->gGrades(subject) == nullptr) || (b->gGrades(subject) == nullptr))
			{
				return false;
			}
			else
			{				
				std::vector<int> vec1 = a->gGrades(subject)->getGrades();
				std::vector<int> vec2 = b->gGrades(subject)->getGrades();
				int sum1 = 0, sum2 = 0;
				for (const auto& n : vec1)
					sum1 += n;
				for (const auto& n : vec2)
					sum2 += n;
				return ((float)sum1 / vec1.size()) < ((float)sum2 / vec2.size());
			}
       }
	);
}

std::ostream& operator<<(std::ostream & os, const StudentGroup & studentgroup)
{
	os << "Group " << studentgroup.m_studentgroupnumber << std::endl;
	for (const auto student : studentgroup.m_students)
	{
		os << *student <<std::endl;
	}
	return os;
}
