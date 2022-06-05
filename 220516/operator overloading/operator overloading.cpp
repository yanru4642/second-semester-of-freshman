#include <iostream>
using namespace std;
class Complex{
public:
	Complex();
	Complex(double a, double b) :real(a),imag(b) {}
	friend Complex& const operator+(const Complex& a, const Complex& b);
	friend ostream& operator<<(ostream&, const Complex& number);
	friend Complex& operator++(Complex& number);
	friend void operator--(Complex& number,int);
	double operator[](int index);
private:
	double real;
	double imag;
};

int main(){
	Complex a(7, 2),b(3.2, 0),c(5.8,6);
	cout << a + b + c << endl;
	++a;
	cout << a << endl;
	b--;
	cout << b << endl;
	cout << c[0] << endl;
	cout << a[1] << endl;
}

Complex::Complex(){
	real = 0;
	imag = 0;
}
Complex& const operator+(const Complex& a, const Complex& b) {
	Complex* ans = new Complex;
	ans->real = a.real + b.real;
	(*ans).imag = a.imag + b.imag;
	return *ans;
}
ostream& operator<<(ostream&, const Complex& number) {
	return cout<<number.real << "+" << number.imag << "i";
}
Complex& operator++(Complex& number) {
	number.real++;
	return number;
}
void operator--(Complex& number, int) {
	number.real--;
}
double Complex::operator[](int index) {
	if (index==0){
		return real;
	}
	else if (index==1){
		return imag;
	}
	return -1;
}