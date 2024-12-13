/*
Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.
*/

#include <iostream>
using namespace std;

int n;

template <typename T>
void selectionSort(T array[]) {
    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[index]) {
                index = j;
            }
        }
        swap(array[index], array[i]);
    }
}

int main() {
    int ch;
    float floatarr[100];
    int intarr[100];

    do {
        cout << "****** SELECTION SORT ******" << endl;
        cout << "1. Integer Array" << endl;
        cout << "2. Float Array" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter number of elements (Max 100): ";
                cin >> n;
                cout << "Enter elements:\n";
                for (int i = 0; i < n; i++) {
                    cout << "Element " << i + 1 << ": ";
                    cin >> intarr[i];
                }
                selectionSort(intarr);
                cout << "Sorted Integer Array:\n";
                for (int i = 0; i < n; i++) {
                    cout << intarr[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                cout << "Enter number of elements (Max 100): ";
                cin >> n;
                cout << "Enter elements:\n";
                for (int i = 0; i < n; i++) {
                    cout << "Element " << i + 1 << ": ";
                    cin >> floatarr[i];
                }
                selectionSort(floatarr);
                cout << "Sorted Float Array:\n";
                for (int i = 0; i < n; i++) {
                    cout << floatarr[i] << " ";
                }
                cout << endl;
                break;

            case 3:
                cout << "Thank you for using the program!" << endl;
                break;

            default:
                cout << "Invalid Choice..." << endl;
        }
    } while (ch != 3);

    return 0;
}
