#pragma once
#include"Common.h"
#include "StudentGroup.h"

class Exam
{
private:
	const int m_maxcount_attempt_exam = 3;
	const std::string m_subject;
	int m_count_attempt_exam;
	StudentGroup* m_studentgroup;

public:
	Exam(StudentGroup* studentgroup, const std::string& subject, int count_attempt_exam = 0);
	void AllowExam();
	void Examination();
};
