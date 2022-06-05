#include <iostream>
using namespace std;
class father
{
public:
	father();
	father& operator=(father& oldFather);
	double const getNum() { return num; }
	void setNum(const double& inNum) { num = inNum; }
	void output();
private:
	double num;
};
father::father():num(0) {}
father& father::operator=(father& oldFather) {
	num = oldFather.getNum()+1;
	return *this;
}
void father::output() {
	cout << "num:" << num << "    ";
}


class child:father{
public:
	child();
	child& operator=(child& oldChild);
	double const getCh() { return ch; }
	void setCh(const char& inCh) { ch = inCh; }
	void output();
private:
	char ch;
};
child::child():ch('A') {}
child& child::operator=(child& oldChild){
	father::operator=(oldChild);
	//(*this).father::operator=(oldChild);
	//以上兩者皆可
	ch = oldChild.ch + 3;
	return *this;
}
void child::output() {
	cout << "_num:" << this->getNum() << "  _ch:" << this->ch << "    ";
}


int main() {
	father a, b;
	a.output();
	b.output();
	cout << endl;
	b = a;
	a.output();
	b.output();
	cout << endl;
	child c, d;
	c.output();
	d.output();
	cout << endl;
	d = c;
	c.output();
	d.output();
	cout << endl;

	return 0;
}