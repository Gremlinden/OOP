#include "Exam.h"


int main()
{
	setlocale(LC_ALL, "ru");

	Student studen1{ "abd", "aa", "�������������", { {"aa", {5,5}}} };
	Student studen2{ "abc", "aa", "�������������",{{"qq", {2,5}}, {"aa", {5,5}}} };
	Student studen3{ "asc", "a�", "�������������",{{"qq", {5,5}}, {"aa", {5,5}}} };
	Botanist studen4{ "asc", "a�", "�������������",{{"qq", {1}}, {"aa", {5,5}}}  };
	Botanist studen5{ "asc", "��", "�������������",{{"qq", {5,5,3,2}}, {"aa", {5,5}}} };
	Botanist studen6{ "asc", "��������", "�������������",{{"qq", {5,5,3,2}}, {"aa", {5,5}}} };
	MemberOfStudentCouncil studen7{ "a", "��������", "�������������", { {"qq", {5,5,2}}, {"aa", {5,5}}} };
	MemberOfStudentCouncil studen8{ "a", "��������", "�������������", { {"qq", {5,5,2}}, {"aa", {5,5}}} };
	MemberOfStudentCouncil studen9{ "a", "��������", "�������������",{ {"qq", {5,5,2}}, {"aa", {5,5}}} };
	
	studen1.gGrades("qq")->AddGrades({ 5,5,2 });
	
	//std::cout << studen1 << std::endl;

	StudentGroup rrrr{ 9, "8091"};
	rrrr.AddStudent(studen1);
	rrrr.AddStudent(studen2);
	rrrr.AddStudent(studen3);
	rrrr.AddStudent(studen4);
	rrrr.AddStudent(studen9);
	rrrr.AddStudent(studen5);
	rrrr.AddStudent(studen6);
	rrrr.AddStudent(studen7);
	rrrr.AddStudent(studen8);
	//std::cout << rrrr << std::endl;
//	rrrr.RemoveStudent(&studen1);
	//std::cout << *rrrr.Find("abd", "aa", "�������������") << std::endl;
    //	rrrr.SortFIO();
//	rrrr.Sortgrades("qq");
  std::cout << rrrr << std::endl;

	Exam ex{ &rrrr, "qq" };
	ex.AllowExam();
	ex.Examination();
	std::cout << rrrr << std::endl;
	ex.Examination();
	std::cout << rrrr << std::endl;
	ex.Examination();
	std::cout << rrrr << std::endl;
	
  	return 0;

}