# Intellias-Bootcamp-Test
Solution for test task

TASK:

Test assignment: Time tracking report 
Goal: test basic C++ skills with something more sophisticated than "Hello World" 
Language: C++ 
Approximate time needed: 2 to 8 hours 
Send your task here: bootcamps@intellias.com
Requirements. 
It is needed to create a console C++ application which would take time report of all employees and generate monthly report. Input and output. 
Data is supplied in text file in CSV format. First line of the file is columns names. Separator is semicolon (;). It is assumed that the file is not malformed.  Date is in YYYY-MM-DD format. 
Input data example: 
Name;email;department;position;project;task;date;logged hours 
John Doe;john.doe@company.com;Delivery;Software Engineer;Mars;MRS-2240;2021-10-19;5 
John Doe;john.doe@company.com;Delivery;Software Engineer;Mars;MRS-2241;2021-10-20;8 
Jane Doe;jane.doe@company.com;Delivery;Manager;Venus;VNS-1111;2021-10-20;4 
...... 
It is expected to receive output in CSV format, containing person name, month and total hours logged 
Output data example: 
Name;Month;Total hours 
John Doe;October 2021;13 
Jane Doe;October 2021;4 
Optional nice-to-haves. 
An example of data validation. Anything, actually, even some made up case like "name can't be John". Error messages can be sent to standard output. Handling different CSV separators. Or any other (meaningful!) generalization. 
Async parsing. 
Measuring parsing time. 
Logging class with output to separate file. 
Cross-platform solution. 
Anything else. The list above is just an example, be creative in how to improve this application.

