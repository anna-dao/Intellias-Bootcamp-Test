#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>

std::vector<TimeReport*> parseFile(std::string filePath, char separator);
std::string calculate(std::vector<TimeReport*> timeReport);
void saveCSVFile(std::string filePath, std::string data);

#endif
