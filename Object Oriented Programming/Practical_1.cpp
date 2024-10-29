/* 
Implement a class Complex which represents the Complex Number data type. Implement the following
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overload operator+ to add two complex numbers.
3.	Overload operator* to multiply two complex numbers.
4.	Overload operators << and >> to print and read Complex Numbers
*/

#include<iostream>
using namespace std;

class Complex{
    public:
        double real;
        double imag;

    public: 
        Complex(){
            real = 0;
            imag = 0;
        }
    //overloading + operator
    Complex operator + (Complex obj){
        Complex result;
        result.real = real + obj.real;
        result.imag = imag + obj.imag;
        return result;
    }

    //overloading * operator
    Complex operator * (Complex obj){
        Complex result;
        result.real = real * obj.real;
        result.imag = imag * obj.imag;
        return result;
    }

    friend istream & operator >> (istream &, Complex &); // Input 
    friend ostream & operator << (ostream &, const Complex &); // Output
};
//overloading >> operator
istream & operator >> (istream &, Complex & i){
    cin >> i.real >> i.imag;
    return cin;
}

//overloading << operator
ostream & operator << (ostream &, Complex & o){
    cout << o.real << "+" << o.imag << "i" << endl;
    return cout;
}

int main(){
    Complex c1, c2, c3, c4;
    int flag = 1;

    cout << "Enter real and imaginary part of complex number 1: ";
    cin >> c1;
    cout << "\nEnter real and imaginary part of complex number 2: ";
    cin >> c2;

    while(flag==1){
        cout << "Complex number 1: " << c1 << endl;
        cout << "Complex number 2: " << c2 << endl;
        cout << "***********MENU***********" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Multiplication" << endl;
        cout << "3. Exit\n" << endl;
        int ch;
        cout<< "Enter choice (1 to 3): ";
        cin >> ch;

        switch (ch)
        {
            char c;
            case 1:
                c3 = c1+c2;
                cout << "Addition of Complex number 1 and 2 is: " << c3 << endl;
                cout << "Do you want to continue?(y/n): ";
                cin >> c;
                if(c=='y' || c=='y'){
                    flag = 1;
                }
                else{
                    flag=0;
                    cout << "Thank you for using the program!" << endl;
                    break;
                }
                break;

            case 2:
                c3 = c1*c2;
                cout << "Multiplication of Complex number 1 and 2 is: " << c3 << endl;
                cout << "Do you want to continue?(y/n): ";
                cin >> c;
                if(c=='y' || c=='y'){
                    flag = 1;
                }
                else{
                    flag=0;
                    cout << "Thank you for using the program!" << endl;
                    break;
                }
                break;
                
            case 3:
                flag = 0;
                cout << "Thank you for using the program!" << endl;
                break;
            
            default:
                cout << "Invalid choice" << endl;
                cout << "Do you want to continue?(y/n): ";
                cin >> c;
                if(c=='y' || c=='y'){
                    flag = 1;
                }
                else{
                    flag=0;
                    cout << "Thank you for using the program!" << endl;
                    break;
                }
                break;
        }
    }
    return 0;
}