/* Write a C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number etc) using vector container */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class PersonalRecord
{
public:
    string name;
    string dob;
    string phno;

    PersonalRecord(string n, string d, string p) : name(n), dob(d), phno(p) {}
};

// Comparator function to sort by name
bool Compare(const PersonalRecord& p1, const PersonalRecord& p2)
{
    return p1.name < p2.name;
}

// Function to search for a record by name
void searchByName(const vector<PersonalRecord>& records, const string& name) {
    bool found = false;
    for (const auto& r : records) {
        if (r.name == name) {
            cout << "Record found:\n";
            cout << "Name: " << r.name << ", DOB: " << r.dob << ", Phone Number: " << r.phno << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record not found.\n";
    }
}

int main()
{
    vector<PersonalRecord> record;
    record.emplace_back("Raj", "01-09-04", "9549585764");
    record.emplace_back("Amit", "13-10-05", "9549585764");
    record.emplace_back("Parth", "14-07-05", "9549585764");

    string name;
    int ch;
    do
    {
        cout << "\n====== Menu ======\n1. Sort the list\n2. Search by name\n3. Display\nPress any other key to exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        
        switch (ch) {
            case 1:
                sort(record.begin(), record.end(), Compare);
                cout << "List sorted by name.\n";
                break;

            case 2:
                cout << "Enter the name to search: ";
                cin >> name;
                searchByName(record, name);
                break;

            case 3:
                cout << "Displaying all records:\n";
                for (const auto& r : record) {
                    cout << "Name: " << r.name << ", DOB: " << r.dob << ", Phone Number: " << r.phno << endl;
                }
                break;

            default:
                cout << "Thank you for using the program!\n";
                exit(0);
        }
    } while(true);
    
    return 0;
}
