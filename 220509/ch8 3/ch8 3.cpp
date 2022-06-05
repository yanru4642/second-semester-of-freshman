#include <iostream>
#include <cmath>
using namespace std;

class Complex{
public:
    Complex();
    Complex(double realPart);
    Complex(double realPart, double imaginaryPart);
    friend ostream& operator <<(ostream& outStream, const Complex& complexNumber);
    friend istream& operator >>(istream& inStream, Complex& complexNumber);
    friend const Complex operator +(const Complex& number1, const Complex& number2);
    friend const Complex operator -(const Complex& number1, const Complex& number2);
    friend const Complex operator *(const Complex& number1, const Complex& number2);
    friend const Complex operator /(const Complex& number1, const Complex& number2);
    friend const bool operator ==(const Complex& number1, const Complex& number2);

private:
    double real;
    double imaginary;
};



int main(void){
    const Complex i(0, 1);
    Complex num1;
    Complex num2;
    double realPart;
    double imaginaryPart;

    //constructor overloading according to the input
    cout << "Enter real part and imaginary part of the number(ex:enter 5 6 means 5+6i)> ";
    cin >> realPart >> imaginaryPart;
    if (realPart==0 && imaginaryPart == 0){
        num1 = Complex();
    }else if (imaginaryPart==0){
        num1 = Complex(realPart);
    }else {
        num1 = Complex(realPart, imaginaryPart);
    }
    cout << "Enter real part and imaginary part of the number(ex:enter 5 6 means 5+6i)> ";
    cin >> num2;

    //operator testing
    cout << "---------------------" << endl;
    cout << "cout << num1: " << num1 << endl;
    cout << "cout << num2: " << num2 << endl;
    cout << "num1 == num2: ";
    if (num1==num2){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    cout << "num1 + num2: " << num1 + num2 << endl;
    cout << "num1 - num2: " << num1 - num2 << endl;
    cout << "num1 * num2: " << num1 * num2 << endl;
    cout << "num1 / num2: " << num1 / num2 << endl;

    system("pause");
    return 0;
}

Complex::Complex() 
    :real(0), imaginary(0){}
Complex::Complex(double realPart) 
    :real(realPart), imaginary(0){}
Complex::Complex(double realPart, double imaginaryPart)
    :real(realPart),imaginary(imaginaryPart) {}

ostream& operator <<(ostream& outStream, const Complex& complexNumber) {
    cout << complexNumber.real << " + " << complexNumber.imaginary << "i";
    return cout;
}
istream& operator >>(istream& inStream, Complex& complexNumber) {
    cin >> complexNumber.real;
    cin >> complexNumber.imaginary;
    return cin;
}
const Complex operator +(const Complex& number1, const Complex& number2) {
    Complex answer;
    answer.real = number1.real + number2.real;
    answer.imaginary = number1.imaginary + number2.imaginary;
    return answer;
}
const Complex operator -(const Complex& number1, const Complex& number2) {
    Complex answer;
    answer.real = number1.real - number2.real;
    answer.imaginary = number1.imaginary - number2.imaginary;
    return answer;
}
const Complex operator *(const Complex& number1, const Complex& number2) {
    Complex answer;
    answer.real = (number1.real * number2.real)-(number1.imaginary * number2.imaginary);
    answer.imaginary = (number1.real * number2.imaginary)+(number1.imaginary * number2.real);
    return answer;
}
const Complex operator /(const Complex& number1, const Complex& number2) {
    Complex answer;
    answer.real = (number1.real * number2.real + number1.imaginary * number2.imaginary) / (pow(number2.real, 2) + pow(number2.imaginary, 2));
    answer.imaginary = (-number1.real * number2.imaginary + number1.imaginary * number2.real) / (pow(number2.real, 2) + pow(number2.imaginary, 2));
    return answer;
}
const bool operator ==(const Complex& number1, const Complex& number2) {
    return number1.real == number2.real && number1.imaginary == number2.imaginary;
}