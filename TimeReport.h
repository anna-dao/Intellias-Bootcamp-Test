#ifndef TimeReport_H
#define TimeReport_H

#include <string>
#include <stdio.h>
//declaring a prototype of a class "TimeReport" from an input CSV file in header file

class TimeReport {
private:
    std::string m_fullName;
    std::string m_email;
    std::string m_department;
    std::string m_position;
    std::string m_project;
    std::string m_task;
    std::string m_date;
    int m_loggedHours;
public:
    std::string getFullName();
    void setFullName(std::string fullName);
    
    std::string getEmail();
    void setEmail(std::string email);
    
    std::string getDepartment();
    void setDepartment(std::string department);
    
    std::string getPosition();
    void setPosition(std::string position);
    
    std::string getProject();
    void setProject(std::string project);
    
    std::string getTask();
    void setTask(std::string task);
    
    std::string getDate();
    void setDate(std::string date);
    
    int getLoggedHours();
    void setLoggedHous(int loggedHours);
    
    TimeReport(std::string s_fullName="", std::string s_email="", std::string s_department="", std::string s_position="", std::string s_project="", std::string s_task="", std::string s_date="", int loggedHours=0);
};

#endif
