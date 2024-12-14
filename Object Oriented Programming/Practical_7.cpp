/*
Write a C++ program to store the name of the state and its population in the map associative container. When the user inputs the name of the state, the program should display its population
*/

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    map<string, int> mymap;
    int ch;
    string sname;
    long long spopu;

    do {
        cout << "\n======= MENU =======" << endl;
        cout << "1. Insert Record" << endl;
        cout << "2. Search Record" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore(); // To clear newline from the buffer

        switch (ch) {
            case 1: {
                cout << "Enter state name: ";
                getline(cin, sname);
                cout << "Enter state population: ";
                cin >> spopu;
                cin.ignore();
                // Convert state name to lowercase
                transform(sname.begin(), sname.end(), sname.begin(), ::tolower);
                mymap[sname] = spopu;
                cout << "\nRecord inserted successfully!" << endl;
                break;
            }

            case 2: {
                string srch;
                cout << "Enter state name to find population: ";
                getline(cin, srch);
                // Convert search term to lowercase
                transform(srch.begin(), srch.end(), srch.begin(), ::tolower);
                
                // Search for the state in the map
                auto it = mymap.find(srch);
                if (it != mymap.end()) {
                    cout << "Population of " << srch << " is: " << it->second << endl;
                } else {
                    cout << srch << " is not in the record. Please insert it first!" << endl;
                }
                break;
            }

            case 3:
                cout << "Thank you for using the program!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (ch != 3);

    return 0;
}


    return 0;
}
