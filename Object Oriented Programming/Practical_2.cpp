/*
Experiment Number 2 : Develop a program in C++ to create a database of
student’s information system containing the following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contactaddress, Telephone number, Driving license no. and other. Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.
*/

#include <iostream>
#include <string>
using namespace std;

class Student; // Forward declaration

class Database {
public:
    // Friend class declaration
    friend class Student;

    // Function to display student details
    void showStudentDetails(const Student& s);
};

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    string division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    long long telephoneNumber;
    string drivingLicenseNo;

    static int studentCount; // Static member variable

public:
    // Default constructor
    Student() {
        cout << "Default constructor called" << endl;
        name = "Unknown";
        rollNumber = 0;
        studentClass = "Unknown";
        division = "Unknown";
        dateOfBirth = "01-01-2000";
        bloodGroup = "Unknown";
        contactAddress = "Unknown";
        drivingLicenseNo = "None";
        studentCount++;
    }

    // Parameterized constructor
    Student(string n, int r, string c, string d, string dob, string bg, string ca, long long tel, string dl) {
        cout << "Parameterized constructor called" << endl;
        name = n;
        rollNumber = r;
        studentClass = c;
        division = d;
        dateOfBirth = dob;
        bloodGroup = bg;
        contactAddress = ca;
        telephoneNumber = tel;
        drivingLicenseNo = dl;
        studentCount++;
    }

    // Copy constructor
    Student(const Student& s) {
        cout << "Copy constructor called" << endl;
        name = s.name;
        rollNumber = s.rollNumber;
        studentClass = s.studentClass;
        division = s.division;
        dateOfBirth = s.dateOfBirth;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        telephoneNumber = s.telephoneNumber;
        drivingLicenseNo = s.drivingLicenseNo;
        studentCount++;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
        studentCount--;
    }

    // Static member function
    static int getStudentCount() {
        return studentCount;
    }

    // Friend function to display private details
    friend void displayDetails(const Student& s);

    // Inline function to update telephone number
    inline void updatePhoneNo(long long phone) {
        this->telephoneNumber = phone;
    }
};

// Definition of friend function to display student details
void displayDetails(const Student& s) {
    cout << "Student Name: " << s.name << endl;
    cout << "Roll Number: " << s.rollNumber << endl;
    cout << "Class: " << s.studentClass << endl;
    cout << "Division: " << s.division << endl;
    cout << "Date of Birth: " << s.dateOfBirth << endl;
    cout << "Blood Group: " << s.bloodGroup << endl;
    cout << "Contact Address: " << s.contactAddress << endl;
    cout << "Telephone Number: " << s.telephoneNumber << endl;
    cout << "Driving License No.: " << s.drivingLicenseNo << endl;
}

// Function to show student details using friend class
void Database::showStudentDetails(const Student& s) {
    cout << "Accessing private data of student from Database class." << endl;
    cout << "Name: " << s.name << ", Roll Number: " << s.rollNumber << endl;
}

// Initialize the static member variable
int Student::studentCount = 0;

int main() {
    try {
        // Dynamic memory allocation using new operator
        Student* s1 = new Student("James Bond", 28, "SE", "A", "12-05-2004", "AB+", "123 street", 1234567890, "DL4334544");
        Student s2("John Doe", 29, "TE", "B", "12-05-2003", "AB+", "123 street", 1234455750, "DL4334544");

        cout << "\n--- Displaying student 1 details ---\n";
        displayDetails(*s1);  // Call friend function

        cout << "\n--- Displaying student 2 details ---\n";
        displayDetails(s2);  // Call friend function

        // Copy constructor
        Student s3 = s2;
        cout << "\n--- Displaying student 3 (copy of student 2) details ---\n";
        displayDetails(s3);  // Call friend function

        cout << "\n--- Updating phone number of student 1 ---\n";
        s1->updatePhoneNo(1234334543);
        displayDetails(*s1);  // Call friend function

        // Accessing student details using friend class
        Database db;
        cout << "\n--- Accessing student 2 details using friend class ---\n";
        db.showStudentDetails(s2);

        cout << "\nTotal students: " << Student::getStudentCount() << endl;

        // Free dynamically allocated memory using delete operator
        delete s1;  // Destructor will be called
    } catch (bad_alloc& ba) {
        cout << "Memory allocation failed: " << ba.what() << endl;
    }

    cout << "\nTotal students after deletion: " << Student::getStudentCount() << endl;

    return 0;
}
