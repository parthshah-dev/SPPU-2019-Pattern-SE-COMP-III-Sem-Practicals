/*
A palindrome is a string of character that's the same forward and backward. Typically, droop" is a palindrome, as can be seen by examining the characters "poor danisina punctuation, capitalization, and spaces are ignored. For example, "Poor Dan is in a droop" and observing that they are the same forward and backward. One way to check for a palindrome is to reverse the characters in the string and then compare with them the original-in a palindrome, the sequence will be identical. Write C++ program with functions-

a) To print original string followed by reversed string using stack
b) To check whether given string is palindrome or not
*/

#include <iostream>
#include <algorithm> // for transform()
#include <string>
using namespace std;

struct Stack{
    char data[50];
    int top;
}s;

//Function to push characters onto the stack
void create(string str){
    for(int i=0; i<str.length(); i++){
        if(s.top < 50){
            s.top++;
            s.data[s.top] = str[i];
        }
    }
}

// Function to reverse the string using the stack
string reverse_str(){
    string str = ""; //store the reversed string

    if(s.top==-1){
        cout << "Stack Underflow!\n";
    }
    else{
        for(int i=s.top; i>=0; i--){
            str += s.data[i];
        }
    }
    return str;
}

// Function to check if the string is a palindrome
void isPalindrome(string str){
    create(str); //push string onto stack

    string reversed_str = reverse_str();

    // Convert both original and reversed strings to lowercase 
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    transform(reversed_str.begin(), reversed_str.end(), reversed_str.begin(), ::tolower);
    
    if(reversed_str == str){
        cout << str << " is a Palindrome!";
    }else{
        cout << str << " is not a Palindrome!";
    }
}

int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << "\nYour string: " << str;
    s.top = -1;

    int ch;

    do {
        cout << "\n======= Menu =======\n1. Show Reverse String\n2. Check if Palindrome\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch){
            case 1: 
                create(str); // Push string onto stack
                cout << "Reversed string: " << reverse_str() << endl;
                break;

            case 2:
                isPalindrome(str); // Check palindrome
                break;

            case 3:
                break;
            
            default: 
                cout << "Invalid choice! try again...";
        }
    }while (true);
    
    return 0;
}
