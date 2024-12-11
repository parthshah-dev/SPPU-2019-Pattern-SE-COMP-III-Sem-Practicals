/*
Write a C++ program to add jobs in the queue and delete jobs from the queue
*/

#include<iostream>
#include<string>
#define MAX 5
using namespace std;

struct Queue{
    string job[MAX];
    int front, rear;
}q;

void addJob(){
    string jobname;
    cout << "Enter Job Name: ";
    cin >> jobname;
    if(q.rear==MAX-1){
        cout << "Error! Queue is already full" << endl;
        return;
    }
    else if(q.front == -1){
        q.front = 0;
        q.rear = 0;
    }
    else{
       q.rear++; 
    }
    q.job[q.rear] = jobname;
    cout << "\nJob '" << jobname << "' added in the queue" << endl;
}

void deleteJob(){
    if(q.front == -1 || q.rear == -1){
        cout << "\nQueue is empty. No jobs to delete." << endl;
        return;
    }
    cout << "\nJob '"<< q.job[q.front] << "' deleted from the queue" << endl;
    
    if(q.front == q.rear){ //only one job is there
        q.front = q.rear = -1;
    }
    else{
        q.front++;
    }
}

void displayJobs(){
    if(q.front == -1 || q.rear == -1){
        cout << "Queue is empty. No jobs to display." << endl;
        return;
    }
    cout << "\nJobs present in the queue: "; 
    for(int i=q.front; i<=q.rear; i++){
        cout << q.job[i] << ", ";  
    }
    cout << endl;
}

int main(){
    int choice;

    q.front = q.rear = -1; //initial position of both the pointers

    do {
        cout << "\n\n======= Menu =======\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                addJob(); // calling add() function
                break;
            case 2:
                deleteJob(); // calling delete() function
                break;
            case 3:
                displayJobs(); // calling display() function
                break;
            case 4:
                cout << "Thank you for using the program!" << endl;
                break;
            default:
                cout << "Invalid choice! try again..." << endl;
        }
    } while (choice != 4);
    
    return 0;
}
