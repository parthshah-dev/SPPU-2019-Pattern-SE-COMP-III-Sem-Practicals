#include <iostream>
#define MAX 5 // Maximum number of orders
using namespace std;

class Pizza {
    int arr[MAX]; // Array to hold orders
    int front = -1; // Front index
    int rear = -1; // Rear index

public:
    // Function to insert an order into the queue
    void insert() {
        int order;
        cout << "Enter number of pizzas: ";
        cin >> order;

        // Check if the queue is full
        if ((rear + 1) % MAX == front) {
            cout << "\nOrder queue is full! No more orders can be placed." << endl;
            return; // Exit the function
        }

        // If this is the first order
        if (front == -1) {
            front = 0; // Set front to 0
        }

        rear = (rear + 1) % MAX; // Circular increment
        arr[rear] = order; // Store the order
        cout << "\nOrder placed: " << order << " pizza(s)." << endl;
    }

    // Function to serve (delete) an order from the queue
    void serve() {
        if (front == -1) { // Check if the queue is empty
            cout << "No orders to serve!" << endl;
            return; // Exit the function
        }

        cout << "Serving order: " << arr[front] << " pizza(s)." << endl;

        // If this was the last order
        if (front == rear) {
            front = -1; // Reset both indices
            rear = -1;
        } else {
            front = (front + 1) % MAX; // Circular increment
        }
    }
};

int main() {
    Pizza p; // Create an instance of the pizza parlor
    int choice;

    do {
        cout << "\n======= Pizza Parlor Menu =======\n";
        cout << "1. Place an Order\n";
        cout << "2. Serve an Order\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.insert(); // Place an order
                break;
            case 2:
                p.serve(); // Serve an order
                break;
            case 3:
                cout << "Thank you for visiting!" << endl; // Exit the program
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
