#include "Student.h"
#include "StudentGroup.h"


int main()
{
	setlocale(LC_ALL, "ru");
	vector<int> a{ 5, 4, 4, 3 };
	Student studen1{ "Даниил", "Шляхановв", "Александрович", a };

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
	catch (std::exception & msg)
	{
		std::cout << msg.what() << std::endl << std::endl;
	}
	
	studentgroup1.SortFIO();
	cout << studentgroup1 << endl;

	studentgroup1.Sortgrades();
	cout << studentgroup1 << endl;
	
	Student* student = studentgroup1.Find("Даниил", "Шляханов", "Александрович");
	
	cout << (*student) << endl;
	
	try
	{
		studentgroup1.Find("Иван", "Шляханов", "Александрович");
	}
	catch (std::exception& msg)
	{
		std::cout << msg.what() << std::endl << std::endl;
	}
	studentgroup1.RemoveStudent(student);
	cout << studentgroup1 << endl;

	return 0;
	
}