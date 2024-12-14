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

int main(){
    string rname, rdob, rphno;
    int n;
    vector<PersonalRecord> record;
    cout << "How many records do you want to insert?: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Enter details of record " << i+1 << endl;
        cout << "Enter name: ";
        cin >> rname;
        cout << "\nEnter Date of Birth (dd/mm/yyyy): ";
        cin >> rdob;
        cout << "\nEnter Phone Number: ";
        cin >> rphno;
        cout << endl;
        record.emplace_back(rname, rdob, rphno);
    }
    
    string name;
    int ch;
    
    do{
        cout << "\n====== Menu ======\n1. Sort the list\n2. Search by name\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        
        switch(ch){
            case 1: sort(record.begin(), record.end(), Compare);
                    cout << "List sorted by name!" << endl;
                    break;
            case 2: cout << "Enter name to search: ";
                    cin >> name;
                    searchByName(record, name);
                    break;
            case 3: for(auto& r : record){
                        cout << "Name: " << r.name << endl;
                        cout << "DOB: " << r.dob << endl;
                        cout << "Phone Number: " << r.phno << endl;
                        cout << endl;
                    }
            case 4: cout << "Thank you!" << endl;
                    break;
            default: cout << "Invalid choice!" << endl;
                    break;
        }
    }while(ch!=4);
    return 0;
}
