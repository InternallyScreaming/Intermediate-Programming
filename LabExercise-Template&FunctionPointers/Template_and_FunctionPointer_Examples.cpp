//Tiffany Wiebe
//101005848
//Lab Exercises for Templates and Function Pointers

#include<iostream>

using namespace std;

//Templates Part 3
template<typename T>
class MyClass{
	T X;
	T Y;
public:
	MyClass(T x, T y) : X(x), Y(y) {}
	
	void printOut() {
		cout << "Your values are: " << X << ", " << Y << endl;
	}
};

//Templates Part 1
template<typename T>
T multiplication(T x, T y) {
	return x * y;
}

//Templates Part 2
template<typename T1, typename T2>
T2 addition(T1 x, T2 y) {
	return x + y;
}

//Function Pointers
double multiply(double x, double y) {
	return x * y;
}
void pointToFunc(double x, double y, double(*point)(double, double)) {
	cout << "The product of " << x << " and " << y << " is: " << point(x, y) << endl;
}

int main() {
	int a = 6;
	int b = 2;
	float pi = 3.14159;
	float eu = 2.71828;
	double d = 89;
	double f = .1;

	double x = 5;
	double y = 33;

	cout << "*********************************************************************************" << endl;
	cout << "*                               First Template                                  *" << endl;
	cout << "*********************************************************************************" << endl;
	cout << multiplication(a, b) << endl;
	cout << multiplication(pi, eu) << endl;
	cout << multiplication(d, f) << endl;

	cout << "*********************************************************************************" << endl;
	cout << "*                               Second Template                                 *" << endl;
	cout << "*********************************************************************************" << endl;
	cout << addition(a, pi) << endl;
	cout << addition(b, d) << endl;
	cout << addition(eu, f) << endl;

	MyClass<char> myClass('y', 'o');
	cout << "*********************************************************************************" << endl;
	cout << "*                                Template Class                                 *" << endl;
	cout << "*********************************************************************************" << endl;
	myClass.printOut();

	cout << "*********************************************************************************" << endl;
	cout << "*                              Function Pointers                                *" << endl;
	cout << "*********************************************************************************" << endl;
	pointToFunc(x, y, multiply);

	system("pause");
	return 0;
}