#include "StudentGroup.h"


int main()
{
	setlocale(LC_ALL, "ru");

	Student studen1{ "Даниил", "Шляхановв", "Александрович", { 5, 4, 4, 3 } };
	cout << studen1 << endl;

	StudentGroup studentgroup1{ 7, "8091" };

	studentgroup1.AddStudent("Даниил", "Аляханов", "Александрович", { 5, 4, 4, 3 });
	studentgroup1.AddStudent("Даниил", "Шляххнов", "Александрович", { 2, 4, 4, 3 });
	studentgroup1.AddStudent("Даниил", "Шляханов", "Александровиа", { 5, 2, 2, 2 });
	studentgroup1.AddStudent("Даниил", "Шляхановвв", "Александрович", { 5, 5, 4, 3 });
	studentgroup1.AddStudent("Ааниил", "Шляханов", "Александрович", { 3, 2, 3, 2 });
	studentgroup1.AddStudent("Даниил", "Шляханов", "Александрович", { 5, 2, 2, 2 });
	studentgroup1.AddStudent(studen1);
	cout << studentgroup1 << endl;
	try
	{
		studentgroup1.AddStudent("Даниил", "Шляханов", "Александрович", { 5, 2, 2, 2 });
	}
	catch (std::string & msg)
	{
		std::cout << msg << std::endl << std::endl;
	}

	studentgroup1.SortFIO();
	cout << studentgroup1 << endl;

	studentgroup1.Sortgrades();
	cout << studentgroup1 << endl;

	list<Student>::iterator student = studentgroup1.Fine("Даниил", "Шляханов", "Александрович");
	cout << student << endl;
	try
	{
		studentgroup1.Fine("Иван", "Шляханов", "Александрович");
	}
	catch (std::string & msg)
	{
		std::cout << msg << std::endl << std::endl;
	}
	studentgroup1.RemoveStudent(student);
	cout << studentgroup1 << endl;

	return 0;
}