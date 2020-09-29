#include "StudentGroup.h"


int main()
{
	setlocale(LC_ALL, "ru");

	Student studen1{ "������", "���������", "�������������", { 5, 4, 4, 3 } };
	cout << studen1 << endl;

	StudentGroup studentgroup1{ 7, "8091" };

	studentgroup1.AddStudent("������", "��������", "�������������", { 5, 4, 4, 3 });
	studentgroup1.AddStudent("������", "��������", "�������������", { 2, 4, 4, 3 });
	studentgroup1.AddStudent("������", "��������", "�������������", { 5, 2, 2, 2 });
	studentgroup1.AddStudent("������", "����������", "�������������", { 5, 5, 4, 3 });
	studentgroup1.AddStudent("������", "��������", "�������������", { 3, 2, 3, 2 });
	studentgroup1.AddStudent("������", "��������", "�������������", { 5, 2, 2, 2 });
	studentgroup1.AddStudent(studen1);
	cout << studentgroup1 << endl;
	try
	{
		studentgroup1.AddStudent("������", "��������", "�������������", { 5, 2, 2, 2 });
	}
	catch (std::string & msg)
	{
		std::cout << msg << std::endl << std::endl;
	}

	studentgroup1.SortFIO();
	cout << studentgroup1 << endl;

	studentgroup1.Sortgrades();
	cout << studentgroup1 << endl;

	list<Student>::iterator student = studentgroup1.Fine("������", "��������", "�������������");
	cout << student << endl;
	try
	{
		studentgroup1.Fine("����", "��������", "�������������");
	}
	catch (std::string & msg)
	{
		std::cout << msg << std::endl << std::endl;
	}
	studentgroup1.RemoveStudent(student);
	cout << studentgroup1 << endl;

	return 0;
}