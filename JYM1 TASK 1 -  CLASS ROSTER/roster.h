#pragma once
#include "student.h"

class Roster {
private:
    const static int numberOfStudents = 5;
    int lastIndex = -1;
    

public:
    Student* classRosterArray[numberOfStudents];
    void parse(string row);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDaysToCompleteCourse1, int numberOfDaysToCompleteCourse2, int numberOfDaysToCompleteCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
   

    ~Roster();
};