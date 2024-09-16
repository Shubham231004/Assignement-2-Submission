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
    std::ifstream file("StudentData.txt");
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
        std::cerr << "Unable to open file";
    }

    // Output the students' names for verification
    for (const auto& student : students) {
        std::cout << student.firstName << " " << student.lastName << std::endl;
    }

    return 0;
}
