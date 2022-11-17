#include "OfficeHour.h"
#include "Student.h"
#include <iostream>

using namespace std;

int main()
{
    Student Taylor = Student(8, "Theory");
    Student Timmy = Student(13, "MP");
    Student Billie = Student(6, "Lab");
    Student Jean = Student(7, "Theory");

    queue<Student> officeHourQueue;
    officeHourQueue.push(Taylor);
    officeHourQueue.push(Timmy);
    officeHourQueue.push(Billie);
    officeHourQueue.push(Jean);

    Staffer Wade = Staffer("Theory", 100);
    Staffer Mattox = Staffer("Lab", 100);
    vector<Staffer> onDutyStaff{Wade, Mattox};

    int expectedWaitTime = waitTime(officeHourQueue, onDutyStaff, 4);

    cout << "The expected wait time for Taylor, the fourth student in the queue, is "
         << to_string(expectedWaitTime) << " minutes." << endl;

    // Student Billy = Student(12, "POTD");
    // Student Joel = Student(15, "MP");
    // Student Jean = Student(8, "MP");
    // Student Taylor = Student(6, "LAB");
    // Student TimTim = Student(13, "POTD");

    // queue<Student> officeHourQueue;
    // officeHourQueue.push(Billy);
    // officeHourQueue.push(Joel);
    // officeHourQueue.push(Jean);
    // officeHourQueue.push(Taylor);
    // officeHourQueue.push(TimTim);

    // Staffer Wade = Staffer("LAB", 2);
    // Staffer Mattox = Staffer("MP", 0);
    // vector<Staffer> onDutyStaff {Wade, Mattox};

    // int expectedWaitTime = waitTime(officeHourQueue, onDutyStaff, 4);

    // cout << "The expected wait time for Taylor, the fourth student in the queue, is " << to_string(expectedWaitTime) << " minutes." << endl;

    // add your own tests here!

    return 0;
};
