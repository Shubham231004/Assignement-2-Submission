#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>     // To use the std::vector container
#include <string>

// Struct to store student data
struct STUDENT_DATA {
    std::string lname;  // Declaring the last name variable
    std::string fname;  // Declaring the first name variable
    std::string email;  // Email variable (only used in pre-release mode)
};

int main() {
    std::vector<STUDENT_DATA> students;  // Vector to store student data

    // Check for pre-release mode and open the corresponding file
#ifdef PRE_RELEASE
    std::cout << "Running in Pre-Release mode..." << std::endl;  // Notify user of pre-release mode
    std::ifstream file("D:\\Shubham 1\\Conestoga\\Semester 5\\Advanced Software Development\\Assignement 2 Submission\\StudentData_Emails.txt");  // Open file with email data
#else
    std::cout << "Running in Standard mode..." << std::endl;  // Notify user of standard mode
    std::ifstream file("D:\\Shubham 1\\Conestoga\\Semester 5\\Advanced Software Development\\Assignement 2 Submission\\StudentData.txt");  // Open file without email data
#endif

    std::string line;  // Variable to hold each line of the file

    // Check if file was successfully opened
    if (file.is_open()) {
        // Loop through each line in the file
        while (getline(file, line)) {
            std::istringstream ss(line);  // Create a string stream to parse the line
            std::string lastName, firstName, email;  // Variables to store parsed data

            // Extract last name and first name, delimited by a comma
            getline(ss, lastName, ',');
            getline(ss, firstName, ',');

#ifdef PRE_RELEASE
            getline(ss, email);  // Read email if in pre-release mode
#endif

            STUDENT_DATA student;  // Create a new STUDENT_DATA object
            student.lname = lastName;  // Assign last name to the object
            student.fname = firstName;  // Assign first name to the object

#ifdef PRE_RELEASE
            student.email = email;  // Assign email to the object in pre-release mode
#endif

            // Add the student object to the vector
            students.push_back(student);
        }
        file.close();  // Close the file after reading
    }
    else {
        std::cerr << "Oops! Error opening the file" << std::endl;  // Print error message if file can't be opened
    }

    // Check if the program is not in debug mode and is in pre-release mode
#if !defined(_DEBUG) && defined(PRE_RELEASE)
    // Loop through the vector of students and print only the email addresses
    for (const auto& student : students) {
        std::cout << student.email << std::endl;  // Output the student's email
    }
#endif


    // If in debug mode, print the student data for verification
#ifdef _DEBUG
    for (const auto& student : students) {
        // Print first name and last name
        std::cout << student.fname << " " << student.lname;

#ifdef PRE_RELEASE
        std::cout << " - " << student.email;  // Print email only in pre-release mode
#endif
        std::cout << std::endl;  // Print a new line after each student's data
    }
#endif

    return 0;  // Exit the program successfully
}
