#include <iostream>
#include <string>

#include "TimeReport.h"

std::string TimeReport::getFullName() {
    return m_fullName;
}
void TimeReport::setFullName(std::string fullName) {
    m_fullName = fullName;
}

std::string TimeReport::getEmail() {
    return m_email;
}
void TimeReport::setEmail(std::string email) {
    m_email = email;
}

std::string TimeReport::getDepartment() {
    return m_department;
}
void TimeReport::setDepartment(std::string department) {
    m_department = department;
}

std::string TimeReport::getPosition() {
    return m_position;
}
void TimeReport::setPosition(std::string position) {
    m_position = position;
}

std::string TimeReport::getProject() {
    return m_project;
}
void TimeReport::setProject(std::string project) {
    m_project = project;
}

std::string TimeReport::getTask() {
    return m_task;
}
void TimeReport::setTask(std::string task) {
    m_task = task;
}

std::string TimeReport::getDate() {
    return m_date;
}
void TimeReport::setDate(std::string date) {
    m_date = date;
}


void TimeReport::setLoggedHous(int loggedHours) {
    m_loggedHours = loggedHours;
}
int TimeReport::getLoggedHours() {
    return m_loggedHours;
}

TimeReport::TimeReport(std::string s_fullName, std::string s_email, std::string s_department, std::string s_position, std::string s_project, std::string s_task, std::string s_date, int loggedHours) {
        m_fullName = s_fullName;
        m_email = s_email;
        m_department = s_department;
        m_position = s_position;
        m_project = s_project;
        m_task = s_task;
        m_date = s_date;
        m_loggedHours = loggedHours;
}

