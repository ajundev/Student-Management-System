#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
	const static int numberOfCourses = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numberOfDaysToCompleteCourse[numberOfCourses];
	DegreeProgram degreeProgram;

public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDaysToCompleteCourse[], DegreeProgram degreeProgram);
	~Student();

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getNumberOfDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setNumberOfDaysToCompleteCourse(int numberOfDaysToCompleteCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();
};