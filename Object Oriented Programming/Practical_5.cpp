/*
Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.
*/

#include<iostream>
#define size 5
using namespace std;
int n;

template<typename T>
void selecSort(T arr[]){
    int i, j, min;
    T temp;
    for(i=0;i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    //printing sorted array
    cout << "Sorted Array: ";
    for(i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int int_array[size];
    float float_array[size];
    int ch;
    do{
        cout<<"\n* * * * * SELECTION SORT SYSTEM * * * * *";
		cout<<"\n--------------------MENU-----------------------";
		cout<<"\n1. Integer Values";
		cout<<"\n2. Float Values";
		cout<<"\n3. Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>ch;

        switch (ch)
        {
            case 1:
                cout << "Enter total number of integer elements: ";
                cin >> n;
                for(int i=0; i<n; i++){
                    cout << "Enter "<< i+1 << " element: ";
                    cin >> int_array[i];
                }
                selecSort(int_array);
                break;

            case 2:
                cout << "Enter total number of float elements: ";
                cin >> n;
                for(int i=0; i<n; i++){
                    cout << "Enter "<< i+1 << " element: ";
                    cin >> float_array[i];
                }
                selecSort(float_array);
                break;

            case 3:
                cout << "Thank you for using the program!";
                exit(0);

            default:
                cout << "Invalid choice!";
                break;
        }
    }while (ch!=3);
    
    return 0;
}