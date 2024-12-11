#include <iostream>
#define SIZE 10
using namespace std;

class Deque {
private:
    int arr[SIZE];
    int front;
    int rear;
    int count;

public:
    Deque() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert at the front" << endl;
            return;
        }
        if (front == -1) { // Empty deque
            front = 0;
            rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }
        arr[front] = value;
        count++;
        cout << value << " added at the front of deque" << endl;
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert at the rear" << endl;
            return;
        }
        if (front == -1) { // Empty deque
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        count++;
        cout << value << " added at the rear of deque" << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from the front" << endl;
            return;
        }
        cout << "Deleted from front: " << arr[front] << endl;

        if (front == rear) { // Only one element was present
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        count--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from the rear" << endl;
            return;
        }
        cout << "Deleted from rear: " << arr[rear] << endl;

        if (front == rear) { // Only one element was present
            front = -1;
            rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);
        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice, value;

    do {
        cout << "\n******* Deque Operations *******\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display Deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                dq.insertFront(value);
                break;
            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                dq.insertRear(value);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                cout << "Thank you for using the program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
