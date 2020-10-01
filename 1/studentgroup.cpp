#include "StudentGroup.h"

StudentGroup::StudentGroup(const int studet_numbers, const string& studentgroupnumber) : m_studet_numbers(studet_numbers),
m_studentgroupnumber(studentgroupnumber)
{}
void StudentGroup::AddStudent(const Student& student)
{
	if (m_studet_numbers > i) {
		this->m_students.push_back(new Student(student));
		i++;
	}else 
		throw std::exception(std::string("Group " + this->m_studentgroupnumber + " is full").c_str());
	
}
void StudentGroup::AddStudent(const string& name, const string& surname, const string& patronymic, const vector<int>& grades)
{
	if (m_studet_numbers > i)
	{
		const Student& student { name, surname, patronymic, grades };
		this->m_students.push_back(new Student(student));
		i++;
	}else
		throw std::exception(std::string("Group " + this->m_studentgroupnumber + " is full").c_str());
}
void StudentGroup::RemoveStudent(Student* student)
{
	if (i != 0)
	{
		this->m_students.erase(find(this->m_students.begin(), this->m_students.end(), student));
		i--;
	}
}
Student* StudentGroup::Find(const string& name, const string& surname, const string& patronymic)
{

	for (vector<Student*>::iterator i = this->m_students.begin(); i != this->m_students.end(); i++)
	{
		if (((*i)->getName() == name) && ((*i)->getSurname() == surname) && ((*i)->getPatronymic()) == patronymic)
		{
			return *i;
		}
	}
	throw std::exception(std::string("Student " + name + " " + surname + " " + patronymic + " is not in group " + m_studentgroupnumber).c_str());
}
auto compGrades{

	[](Student  *a, Student  *b) {
	vector<int> vec1 = a->getGrades(), vec2 = b->getGrades();
		int sum1 = 0, sum2 = 0;
		for (auto& n : vec1)
			sum1 += n;
		for (auto& n : vec2)
			sum2 += n;
		return ((float)sum1 / vec1.size()) < ((float)sum2 / vec2.size());
}
};
const int comparison(const string a, const string b)
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
auto compFIO{

	[](Student* a, Student* b) {
	int n = comparison(a->getSurname(), b->getSurname());
		if (n != 3)
			return n;
		n = comparison(a->getName(), b->getName());
		if (n != 3)
			return n;
		n = comparison(a->getPatronymic(), b->getPatronymic());
		if (n != 3)
			return n;
    }
};

void StudentGroup::SortFIO()
{
	sort(this->m_students.begin(), this->m_students.end(), compFIO);
}
void StudentGroup::Sortgrades()
{
	sort(this->m_students.begin(), this->m_students.end(), compGrades);

}

ostream& operator<<(std::ostream& os, const StudentGroup& studentgroup)
{
	os << "Group " << studentgroup.m_studentgroupnumber << endl;
	for (const auto n : studentgroup.m_students)
	{
		os << n->getSurname() << "  " << n->getName() << "  " << n->getPatronymic() << "  ";
		for (const auto& k : n->getGrades())
			os << k << " ";
		os << endl;
	}
	return os;
}
