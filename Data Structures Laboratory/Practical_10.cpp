/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. Write C++ program using stack to check whether given expression is well parenthesized or not
*/

#include<iostream>
#include<string>
using namespace std;

struct Stack{
    int data[50];
    int top = -1;
};

bool checker(struct Stack s){
    string str;
    cout << "Enter a string: ";
    cin >> str;

    for(int i=0; i<str.length(); i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            if(s.top==50){
                cout << "\nStack Overflow!";
            }
            else{
                s.top++;
                s.data[s.top] = str[i];
            }
        }
        else if(str[i]==')' && s.data[s.top]== '(' || str[i]=='}' && s.data[s.top]== '{' || str[i]==']' && s.data[s.top]== '['){
            if(s.top==-1){
                return false;
            }
            s.top--;
        }
        else if(str[i]==')' || str[i]=='}' || str[i]=='}'){
            return false;
        }
    }
    return s.top==-1;
}
int main(){
    struct Stack s;
    
    if(checker(s)){
        cout << "String is well parenthesized\n";
    }else{
        cout << "String is not well parenthesized\n";
    }
    return 0;
}