#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

int main() {
    
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 011579438" << endl; 
    cout << "Amaechi Oghor" << endl; 
    cout << endl;

    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Amaechi,Oghor,aoghor@wgu.edu,25,20,40,32,SOFTWARE"
    };
   
    Roster classRoster;
    
    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }

    cout << "Display all students:" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Displaying invalid emails: " << endl;
    cout << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl;

    cout << "Showing students in degree program: SOFTWARE" << endl;
    cout << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Removing A3:" << endl;
    cout << endl;
    classRoster.remove("A3");
    classRoster.printAll();
    cout << endl;

    cout << "Removing A3 again" << endl;
    cout << endl;
    classRoster.remove("A3");

    cout << "DONE." << endl;
    
    return 0;
}