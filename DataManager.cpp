#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>

#include "TimeReport.h"
#include "DataManager.h"

// Formating date from CSV file which returns only month and year without the day
std::string formatDate(std::string date) {
    const int dateCount = 2;
    std::string s_word, s_formatDate;
    std::vector <std::string> v_formatDate;
    std::stringstream lineStream(date);
    
    for (int i = 0; i < dateCount; i++) {
        std::getline(lineStream, s_word, '-');
        v_formatDate.push_back(s_word);
        if (i == 0) {
            v_formatDate.push_back("-");
        }
    };
    
    for (std::string s_word: v_formatDate) {
        s_formatDate += s_word;
    }
    return s_formatDate;
}

// Reading information from an input CSV file and writing it to the [TimeReport]
std::vector<TimeReport*> parseFile(std::string filePath, char separator) {
    if (separator == '-') {
        throw std::invalid_argument("Separator is not valid");
    }
    int wordCount = 0;
    std::string line, word;
    std::vector<TimeReport*> timeReport;
    
    std::fstream file(filePath, std::ios::in);
    if (file.fail()) {
        throw std::invalid_argument("File not found");
    }
    
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        
        TimeReport* report = new TimeReport;
        wordCount = 0;
        while(std::getline(lineStream, word, separator)) {
            switch(wordCount) {
                case 0:report->setFullName(word); break;
                case 1:report->setEmail(word); break;
                case 2:report->setDepartment(word); break;
                case 3:report->setPosition(word); break;
                case 4:report->setProject(word); break;
                case 5:report->setTask(word); break;
                case 6:report->setDate(word); break;
                case 7:report->setLoggedHous(stoi(word)); break;
            }
            wordCount++;
        };
        timeReport.push_back(report);
    };
    file.close();
    return timeReport;
}

// Calculate the quantity of logged hours for every TimeReport monthly
std::string calculate(std::vector<TimeReport*> timeReport) {
    std::string data;
    
    for (int i=0; i < timeReport.size(); i++) {
        std::string fullName = timeReport[i]->getFullName();
        std::string date = timeReport[i]->getDate();
        std::string email = timeReport[i]->getEmail();
        int loggedHours = timeReport[i]->getLoggedHours();
        
        int totalHours = loggedHours;
        // Check if user isExists in result data
        if ((data.find(fullName) == std::string::npos) || (data.find(formatDate(date)) == std::string::npos)) {
            
            for (int j=0; j < timeReport.size(); j++) {
                std::string tempFullName = timeReport[j]->getFullName();
                std::string tempDate = timeReport[j]->getDate();
                std::string tempEmail = timeReport[j]->getEmail();
                int tempLoggedHours = timeReport[j]->getLoggedHours();
                
                if (i != j && formatDate(date) == formatDate(tempDate) && email == tempEmail) {
                    totalHours += tempLoggedHours;
                }
            }
            
            std::cout << fullName << " | " << formatDate(date) << std::endl;
            std::stringstream report;
            report << fullName << ";" << date << ";" << totalHours << "\n";
            std::string s = report.str();
            data.append(s);
        }
    }
    return data;
}

void saveCSVFile(std::string filePath, std::string data) {
    filePath = std::regex_replace(filePath, std::regex(".csv"), "");
    std::string outputFilePath = filePath.append("_result.csv");
    std::ofstream outFile(outputFilePath);
    for (const auto &e : data) outFile << e;
    outFile.close();
}
