#include <iostream>
#include "OfficeHour.h"

/*
Given the current Office Hour queue and the currently on-duty staffers, return
how long the nth student will need to wait before a Staffer can reach them
Return -1 if there are no staff available to help the nth student

@param queue A queue containing the students currently waiting for help
@param onDutyStaff  A vector of Staffers currently on duty
@param nthStudent   The student for whom we are calculating a wait time
@return             How many minutes the nth student will have to wait before getting help
*/
int waitTime(queue<Student> queue, vector<Staffer> onDutyStaff, int nthStudent)
{
    // Your code here!
    int total_wait_time = 0;
    int student_idx = 1;
    int queue_time = 0;
    vector<bool> occupied(onDutyStaff.size());

    while (!queue.empty())
    {
        Student s = queue.front();
        queue.pop();

        std::cout << "Student " << student_idx << " needs " << s.getTimeNeeded()
                  << " minutes for " << s.getQuestionType() << "question"
                  << std::endl;

        if (student_idx == nthStudent)
            break;

        for (unsigned long i = 0; i < onDutyStaff.size(); i++)
        {
            std::cout << "\tStaff " << i << " has "
                      << onDutyStaff[i].getEnergyLevel() << "% of energy"
                      << std::endl;
            if (!occupied[i])
            {
                int wait_time = onDutyStaff[i].answerQuestion(s.getQuestionType(), s.getTimeNeeded());
                occupied[i] = true;

                if (wait_time <= s.getTimeNeeded())
                {
                    total_wait_time += wait_time;
                    std::cout << "\t\twait time is: " << wait_time << std::endl;
                    break;
                }
            }
        }

        queue_time += total_wait_time;
        student_idx++;
    }

    return total_wait_time;
}
