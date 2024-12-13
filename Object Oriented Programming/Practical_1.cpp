/* 
Implement a class Complex which represents the Complex Number data type. Implement the following
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overload operator+ to add two complex numbers.
3.	Overload operator* to multiply two complex numbers.
4.	Overload operators << and >> to print and read Complex Numbers
*/

#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    // Constructor with default parameters
    Complex(float r = 0, float i = 0){
        real = r;
        imag = i;
    }

    // Overloaded addition operator
    Complex operator+(const Complex& obj) {
        Complex result;
        result.real = real + obj.real;
        result.imag = imag + obj.imag;
        return result;
    }

    // Overloaded multiplication operator
    Complex operator*(const Complex& obj) {
        Complex result;
        result.real = (real * obj.real) - (imag * obj.imag);
        result.imag = (real * obj.imag) + (imag * obj.real);
        return result;
    }

    // Friend function for input
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Friend function for output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2;

    // Input two complex numbers
    cout << "Enter complex number 1:\n";
    cin >> c1;
    cout << "\nEnter complex number 2:\n";
    cin >> c2;

    cout << "\nComplex number 1: " << c1 << endl;
    cout << "Complex number 2: " << c2 << endl;

    int ch;
    do {
        cout << "\n*********** MENU ***********" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Multiplication" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice (1 to 3): ";
        cin >> ch;

        Complex c3; // For storing results of operations
        switch (ch) {
            case 1:
                c3 = c1 + c2;
                cout << "Result of addition: " << c3 << endl;
                break;

            case 2:
                c3 = c1 * c2;
                cout << "Result of multiplication: " << c3 << endl;
                break;

            case 3:
                cout << "Thank you for using the program!" << endl;
                break;

            default:
                cout << "Invalid Choice! Please try again." << endl;
        }
    } while (ch != 3);

    return 0;
}
