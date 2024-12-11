/*
The ticket booking system of Cinemax theater has to be implemented using C++ program There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats at rows. Assume some random booking to start with. Use array to store pointers (Head pointer) to each row. On demand
a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be cancelled.
*/

#include<iostream>
using namespace std;

struct Node
{
    int seat;
    bool isBooked;
    Node* next;
    Node* prev;
};

//head node for each row
Node* head[10];

//function to create 7 seats in 10 rows
void create(){
    for(int i=0; i<10; i++){
        head[i] = NULL;
        Node* current = NULL;
        for(int j=0; j<7; j++){
            Node* newNode = new Node;
            newNode->seat = j+1;
            newNode->isBooked = false;
            newNode->next = NULL;
            newNode->prev = NULL;

            if(head[i] == NULL){
                head[i] = newNode;
                current = newNode;
            }
            else{
                newNode->prev = current;
                current->next = newNode;
                current = newNode;
            }
        }
    }
}

//function to display available seats
void display_seats(){
    for(int i=0; i<10; i++){
        Node* temp = head[i];
        cout << "Row " << i+1 << ": \n";
        while (temp!=NULL)
        {
            if(!temp->isBooked){
                cout << "Seat Number " << temp->seat << " is available\n";
            }
            temp = temp->next;
        }
        cout << endl;
    }
}

//function to book seats
void book_seat(){
    int row, seat;
    cout << "Enter Row Number: ";
    cin >> row;
    cout << "\nEnter Seat Number: ";
    cin >> seat;

    Node* temp = head[row-1];
    for(int i=1; i<seat; i++){
        temp = temp->next;
    }
    if(temp->isBooked){
        cout << "Seat is already booked" << endl;
    }
    else{
        temp->isBooked = true;
        cout << "Hurray! Seat " << seat << " booked successfully" << endl;
    }
}

//function to cancel a booking
void cancel_seat(){
    int row, seat;
    cout << "Enter Row Number: ";
    cin >> row;
    cout << "\nEnter Seat Number: ";
    cin >> seat;

    Node* temp = head[row-1];
    for(int i=1; i<seat; i++){
        temp = temp->next;
    }
    if(temp->isBooked){
        temp->isBooked = false;
        cout << "Seat " << seat << " cancelled successfully!" << endl;
    }
    else{
        cout << "Seat " << seat << " was not booked!" << endl;
    }
}

int main(){
    int choice;

    create();

    do {
        cout << "\n\n======= Menu =======\n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel a booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                display_seats();  // Display available seats
                break;
            case 2:
                book_seat();         // Book a seat
                break;
            case 3:
                cancel_seat();       // Cancel a booking
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

