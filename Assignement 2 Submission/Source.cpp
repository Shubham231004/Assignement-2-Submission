#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct STUDENT_DATA {
    std::string lname; //declaring the last name variable
    std::string fname; // declaring the first name variable
    std::string email; // For pre-release mode
};

int main() {
    std::vector<STUDENT_DATA> students;

#ifdef PRE_RELEASE
    std::cout << "Running in Pre-Release mode..." << std::endl;
    std::ifstream file("D:\\Shubham 1\\Conestoga\\Semester 5\\Advanced Software Development\\Assignement 2 Submission\\StudentData_Emails.txt");
#else
    std::cout << "Running in Standard mode..." << std::endl;
    std::ifstream file("D:\\Shubham 1\\Conestoga\\Semester 5\\Advanced Software Development\\Assignement 2 Submission\\StudentData.txt");
#endif

    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            std::istringstream ss(line);
            std::string lastName, firstName, email;

            getline(ss, lastName, ',');
            getline(ss, firstName, ',');

#ifdef PRE_RELEASE
            getline(ss, email); // Read email only in pre-release mode
#endif

            STUDENT_DATA student;
            student.lname = lastName;
            student.fname = firstName;

#ifdef PRE_RELEASE
            student.email = email;
#endif

            students.push_back(student);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file" << std::endl;
    }

    // Print the student data
#ifdef _DEBUG
    std::cout << "Debug Mode: Printing student information..." << std::endl;
    for (const auto& student : students) {
        std::cout << student.fname << " " << student.lname;
#ifdef PRE_RELEASE
        std::cout << " - " << student.email; // Only print email in pre-release mode
#endif
        std::cout << std::endl;
    }
#endif

    return 0;
}
