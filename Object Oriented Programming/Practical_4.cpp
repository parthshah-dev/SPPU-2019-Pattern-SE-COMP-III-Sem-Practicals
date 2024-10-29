/*
Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file.
*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Employee{
    private: 
        string name;
        int emp_id;
        double salary;
    
    public:
        void getData(){
            cout << "Enter Employee Name: ";
            cin >> name;
            cout << "Enter Employee ID: ";
            cin >> emp_id;
            cout << "Enter Employee Salary: ";
            cin >> salary;
        }
        void dispData(){
            cout << "Employee Name: " << name;
            cout << "Enter Employee ID: " << emp_id;
            cout << "Enter Employee Salary: " << salary;
        }
};
int main(){
    Employee emp[5];
    fstream f;
    int num;

    f.open("employee.txt", ios::out);
    cout << "Enter number of employees you want to store(max 5): ";
    cin >> num;
    for(int i=0; i<num; i++){
        cout << "*****Enter Employee " << i+1 << " Information*****" << endl;
        emp[i].getData();
        f.write((char*)&emp[i], sizeof(emp[i]));
    }
    f.close();

    //reopening the file to read information from it
    f.open("employee.txt", ios::in);
    cout << "----------Employee Information----------";
    for(int i=0; i<num; i++){
        cout << "\nEmployee " << i+1;
        f.write((char*)&emp[i], sizeof(emp[i]));
         emp[i].dispData();
    }
    f.close();
    return 0;
}