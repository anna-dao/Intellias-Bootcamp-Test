#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <future>
#include <thread>

#include "TimeReport.h"
#include "DataManager.h"

std::string inputFilePath() {
    std::string csv_file;
    std::cout << "Enter the file path: ";
    getline(std::cin, csv_file);
    return csv_file;
}

int main() {
    auto totalStart = std::chrono::high_resolution_clock::now();
    
// std::string filePath = inputFilePath();
    std::string filePath = "";
    std::cout << "File path: " << filePath << std::endl;
    if (filePath.empty()) {
        filePath = "/Users/mac/Desktop/coding/test/test/2022.csv";
    }
    
// time parsing and async 
    auto parseStart = std::chrono::high_resolution_clock::now();
    std::future <std::vector<TimeReport*>> timeReport = std::async(parseFile, filePath, ';');
    
    auto parseStop = std::chrono::high_resolution_clock::now();
    std::string data = calculate(timeReport.get());
    saveCSVFile(filePath, data);
    
    auto totalStop = std::chrono::high_resolution_clock::now();
    auto totalDuration = std::chrono::duration_cast<std::chrono::microseconds>(totalStop - totalStart);
    auto parseDuration = std::chrono::duration_cast<std::chrono::microseconds>(parseStop - parseStart);
    std::cout << "Parsing time: " << parseDuration.count() << std::endl;
    std::cout << "Total time: " << totalDuration.count() << std::endl;
    
    return 0;
}

