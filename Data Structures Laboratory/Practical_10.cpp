/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. Write C++ program using stack to check whether given expression is well parenthesized or not
*/

#include <iostream>
#include <string>
using namespace std;

struct Stack {
    char data[50];
    int top;
}s; 

bool checker() {
    string str;
    cout << "Enter an expression: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        // Push opening delimiters onto the stack
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            if (s.top >= 49) { // Stack is full
                cout << "Stack overflow!" << endl;
                return false;
            }
            s.top++;
            s.data[s.top] = str[i];
        }
        // Check for closing delimiters
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (s.top == -1) { // Stack is empty
                return false;
            }
            char topChar = s.data[s.top];
            s.top--; // Pop the stack
            if ((str[i] == ')' && topChar != '(') ||
                (str[i] == '}' && topChar != '{') ||
                (str[i] == ']' && topChar != '[')) {
                return false; // Mismatched delimiters
            }
        }
    }
    return s.top == -1; // Stack should be empty if balanced
}

int main() {
    s.top = -1; // Initialize stack with top as -1
    
    if (checker()) {
        cout << "The expression is well-parenthesized." << endl;
    } else {
        cout << "The expression is not well-parenthesized." << endl;
    }
    return 0;
}
