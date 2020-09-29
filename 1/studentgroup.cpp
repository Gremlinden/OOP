#include "studentGroup.h"

StudentGroup::StudentGroup(int studet_numbers, string studentgroupnumber) : m_studet_numbers(studet_numbers),
m_studentgroupnumber(studentgroupnumber), m_students(new list<Student>())
{}
struct compgrades
{
	bool operator()(Student& a, Student& b)
	{
		vector<int> vec1 = a.Getgrades(), vec2 = b.Getgrades();
		int sum1 = 0, sum2 = 0;
		for (auto& n : vec1)
			sum1 += n;
		for (auto& n : vec2)
			sum2 += n;
		return ((float)sum1 / vec1.size()) < ((float)sum2 / vec2.size());
	}

};
struct compFIO
{
	int comparison(string a, string b)
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
		else if (a > b)
			return 1;
		else
			return 0;
	}
	bool operator()(Student& a, Student& b)
	{
		int n = comparison(a.Getsurname(), b.Getsurname());
		if (n != 3)
			return n;
		n = comparison(a.Getname(), b.Getname());
		if (n != 3)
			return n;
		n = comparison(a.Getpatronymic(), b.Getpatronymic());
		if (n != 3)
			return n;
	}

};
void StudentGroup::AddStudent(Student student)
{
	if (m_studet_numbers > i)
	{
		this->m_students->push_front(student);
		i++;
	}
	else
		throw std::string("Group " + this->m_studentgroupnumber + " is full");
}
void StudentGroup::AddStudent(string name, string surname, string patronymic, vector<int> grades)
{
	if (m_studet_numbers > i)
	{
		Student* student = new Student(name, surname, patronymic, grades);
		this->m_students->push_front(*student);
		i++;
	}
	else
		throw std::string("Group " + this->m_studentgroupnumber + " is full");
}


void StudentGroup::RemoveStudent(list<Student>::iterator student)
{
	if (i != 0)
	{
		this->m_students->erase(student);
		i--;
	}
}

list<Student>::iterator StudentGroup::Fine(string name, string surname, string patronymic)
{
	for (list<Student>::iterator i = this->m_students->begin(); i != this->m_students->end(); i++)
	{
		if ((i->Getname() == name) && (i->Getsurname() == surname) && (i->Getpatronymic()) == patronymic)
		{
			return i;
		}
	}
	throw std::string("Student " + name + " " + surname + " " + patronymic + " is not in group " + m_studentgroupnumber);


}

void StudentGroup::SortFIO()
{
	(*m_students).sort(compFIO());
}
void StudentGroup::Sortgrades()
{
	(*m_students).sort(compgrades());
}

string Student::Getname()
{
	return m_name;
}
string Student::Getsurname()
{
	return m_surname;
}
string Student::Getpatronymic()
{
	return m_patronymic;
}
vector<int> Student::Getgrades()
{
	return m_grades;
}
ostream& operator<<(std::ostream & os, const StudentGroup & studentgroup)
{
	os << "Ãğóïïà " << studentgroup.m_studentgroupnumber << endl;
	for (list<Student>::iterator i = studentgroup.m_students->begin(); i != studentgroup.m_students->end(); i++)
	{
		os << i->Getsurname() << "  " << i->Getname() << "  " << i->Getpatronymic() << "  ";

		for (int j = 0; j < (i->Getgrades()).size(); j++)
			os << (i->Getgrades())[j] << " ";
		os << endl;
	}
	return os;
}
int StudentGroup::i = 0;