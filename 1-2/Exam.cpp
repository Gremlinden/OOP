#include "Exam.h"

Exam::Exam(StudentGroup* studentgroup, const std::string& subject, int count_attempt_exam): m_studentgroup(studentgroup), m_subject(subject), m_count_attempt_exam(count_attempt_exam)
{
	if (count_attempt_exam >= 3)
		throw std::exception(std::string("Group pass in the exam was not carry out").c_str());
}

void Exam::AllowExam()
{
	for(auto student: *m_studentgroup)
	{
		Grades* grades = student->gGrades(m_subject);
		if (grades == nullptr)
			continue;

		if (!((grades->getGradesExam() > 2) && (grades->getGradesExam() <= 5)))
		{
			int sum = 0;
			for (const auto m : grades->getGrades())
			{
				sum += m;
			}

			if (((float)sum / grades->getGrades().size()) >= 3.0)
			{
				grades->setAllowExam(true);
			}
			else
				grades->setAllowExam(false);
		}
	}
	
}
void Exam::Examination()
{

	if (m_count_attempt_exam == m_maxcount_attempt_exam)
		throw std::exception(std::string("Exam for this group was ended").c_str());
	m_count_attempt_exam++;
	for (auto student : *m_studentgroup)
	{
		Grades* grades = student->gGrades(m_subject);
		if (grades == nullptr)
			continue;

		if (grades->getAllowExam())
		{
			if (m_count_attempt_exam == m_maxcount_attempt_exam)
			{
				grades->setGradesExam(student->GradesExam(true));
			}
			else grades->setGradesExam(student->GradesExam(false));

			if (grades->getGradesExam() >= 3)
			{
				grades->setAllowExam(false);
			}
			else if (m_count_attempt_exam == m_maxcount_attempt_exam)
			{
				grades->setAllowExam(false);
				m_studentgroup->RemoveStudent(student);
			}
		}
	}
}
