#include <iostream>
#include <cmath>
using namespace std;

// Class for complex numbers
class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Function to calculate magnitude of the complex number
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // Function to input complex number
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    // Display the complex number
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Template function to find the greater of two complex numbers
template <typename T>
T findGreater(const T& c1, const T& c2) {
    if (c1.magnitude() > c2.magnitude()) {
        return c1;
    } else {
        return c2;
    }
}

int main() {
    Complex c1, c2;

    // Input complex numbers from the user
    cout << "Enter first complex number:\n";
    c1.input();
    cout << "Enter second complex number:\n";
    c2.input();

    cout << "\nFirst complex number: ";
    c1.display();
    cout << "Second complex number: ";
    c2.display();

    // Finding the greater complex number based on magnitude
    Complex greater = findGreater(c1, c2);

    cout << "The greater complex number is: ";
    greater.display();

    return 0;
}
