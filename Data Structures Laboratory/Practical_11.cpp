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

void initialize()
{
    q.front = -1; //initialize front and rear -1 for empty queue
    q.rear = -1;
}

void addJob(){
    if(q.rear==MAX-1){
        cout << "\nError! Queue is already full";
        return;
    }
    string name;
    cout << "Enter Job Name: ";
    cin >> name;
    q.rear++; //increment rear to add job
    q.job[q.rear] = name;

    if(q.front==-1){
        q.front = 0;
    }
    cout << "\nJob '" << name << "' added in the queue";
}

void delJob(){
    if(q.front == -1 || q.rear == -1){
        cout << "\nQueue is empty. No jobs to delete.";
        return;
    }
    cout << "\nJob '"<< q.job[q.front] << "' deleted from the queue";
    q.front++;

     // Reset the queue if it becomes empty after deletion
    if (q.front > q.rear) {
        q.front = q.rear = -1;
    }
}

void display(){

    if(q.front == -1 || q.rear == -1){
        cout << "\nQueue is empty. No jobs to display.";
        return;
    }
    
    cout << "\nJobs in the queue: "; 
    for(int i=q.front; i<=q.rear; i++){
        cout << "'" << q.job[i] << "'" << " ";
    }
    cout << endl;
}

int main(){
    int choice;

    initialize();

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
                delJob(); // calling delete() function
                break;
            case 3:
                display(); // calling display() function
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
