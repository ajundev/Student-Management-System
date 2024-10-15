#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

void Roster::parse(string row) {
    size_t rhs = row.find(",");
    string studentID = row.substr(0, rhs);

    size_t lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string firstName = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string lastName = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string emailAddress = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int age = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string degreeprogram = row.substr(lhs, rhs - lhs);

    DegreeProgram dp;
    if (degreeprogram == "SECURITY") {
        dp = SECURITY;
    }
    else if (degreeprogram == "NETWORK") {
        dp = NETWORK;
    }
    else {
        dp = SOFTWARE;
    }

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, dp);

    return;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

    int NumCourseDays[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    lastIndex++;

    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, NumCourseDays, degreeprogram);

    return;
}

void Roster::remove(string studentID) {
    bool found = false;
    int i = 0;

    while (found != true && i < numberOfStudents) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            found = true;
            for (int j = i; j < numberOfStudents - 1; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
           
        }
        else {
            i++;
        }
    }

    if (found != true) {
        cout << "The student with the ID: " << studentID << " was not found." << endl;
    }

    return;
}

void Roster::printAll() {
    for (int i = 0; i < numberOfStudents; i++) {
        classRosterArray[i]->print();
    }

    return;
}

void Roster::printAverageDaysInCourse(string studentID) {
    int totalCourseDays = 0;
    int averageCourseDays;

    for (int i = 0; i < numberOfStudents; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            totalCourseDays = classRosterArray[i]->getNumberOfDaysToCompleteCourse()[0] + classRosterArray[i]->getNumberOfDaysToCompleteCourse()[1] + classRosterArray[i]->getNumberOfDaysToCompleteCourse()[2];
        }
    }

    averageCourseDays = totalCourseDays / 3;

    cout << "Student ID: " << studentID << ", average days in course is: ";
    cout << averageCourseDays << endl;
    return;
}

void Roster::printInvalidEmails() {
    string test;

    for (int i = 0; i < numberOfStudents; i++) {
        test = classRosterArray[i]->getEmailAddress();
        if (test.find(' ') != string::npos) {
            cout << test << " - is invalid." << endl;
        }
        if (test.find('.') == string::npos) {
            cout << test << " - is invalid." << endl;
        }
        if (test.find('@') == string::npos) {
            cout << test << " - is invalid." << endl;
        }
    }

    return;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < numberOfStudents; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }

    return;
}

Roster::~Roster() {
    for (int i = 0; i < numberOfStudents; i++) {
        delete classRosterArray[i];
    }

    return;
}