#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
};

int main() {
    std::vector<STUDENT_DATA> students;
    std::ifstream file("D:\\Shubham 1\\Conestoga\\Semester 5\\Advanced Software Development\\Assignement 2 Submission\\StudentData.txt");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            std::istringstream ss(line);
            std::string lastName, firstName;

            getline(ss, lastName, ',');
            getline(ss, firstName);

            STUDENT_DATA student;
            student.lastName = lastName;
            student.firstName = firstName;

            students.push_back(student);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file" << std::endl;
    }

    // This code block will only run in Debug mode
#ifdef _DEBUG
    std::cout << "Debug Mode: Printing student information..." << std::endl;
    for (const auto& student : students) {
        std::cout << student.firstName << " " << student.lastName << std::endl;
    }
#endif

    return 0;
}
