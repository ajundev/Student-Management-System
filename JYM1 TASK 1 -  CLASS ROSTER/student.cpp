#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numberOfCourses; i++) this->numberOfDaysToCompleteCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDaysToCompleteCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < numberOfCourses; i++) this->numberOfDaysToCompleteCourse[i] = numberOfDaysToCompleteCourse[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int* Student::getNumberOfDaysToCompleteCourse() {
	return numberOfDaysToCompleteCourse;
}
DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setNumberOfDaysToCompleteCourse(int numberOfDaysToCompleteCourse[]) {
	for (int i = 0; i < numberOfCourses; i++) 
		this->numberOfDaysToCompleteCourse[i] = numberOfDaysToCompleteCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << "\t";
	cout << this->getNumberOfDaysToCompleteCourse()[0] << ',';
	cout << this->getNumberOfDaysToCompleteCourse()[1] << ',';
	cout << this->getNumberOfDaysToCompleteCourse()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}