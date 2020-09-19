#include <iostream>
#include <exception>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
    	numerator = 0;
    	denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
    	if (new_denominator == 0) {
    		throw invalid_argument("");
    	}
    	if (new_numerator == 0){numerator = 0; denominator = 1;}
    	else if (new_denominator > 0) {
    		 int gcd;
    		 gcd = abs(__gcd(new_numerator, new_denominator));
    		 numerator = new_numerator / gcd;
    		 denominator = new_denominator / gcd;
    	} else {
    		 int n, m, gcd;
    		 n = - new_numerator;
    		 m = abs(new_denominator);
    		 gcd = abs(__gcd(n, m));
    		 numerator = n / gcd;
    		 denominator = m / gcd;
    	}
    }

    int Numerator() const {
        // Реализуйте этот метод
    	return numerator;
    }

    int Denominator() const {
        // Реализуйте этот метод
    	return denominator;
    }

private:
    // Добавьте поля
    int numerator;
    int denominator;
};

bool operator==(const Rational& d1, const Rational& d2){
	return (d1.Numerator() == d2.Numerator()) and (d1.Denominator() == d2.Denominator());
}

Rational operator+(Rational d1, Rational d2){
	return Rational(d1.Numerator()*d2.Denominator() + d1.Denominator()*d2.Numerator(), d1.Denominator()*d2.Denominator());
}

Rational operator-(Rational d1, Rational d2){
	return Rational(d1.Numerator()*d2.Denominator() - d1.Denominator()*d2.Numerator(), d1.Denominator()*d2.Denominator());
}

Rational operator*(Rational d1, Rational d2){
	return Rational(d1.Numerator()*d2.Numerator(),d1.Denominator()*d2.Denominator());
}

Rational operator/(Rational d1, Rational d2){
	if (d2.Numerator() == 0) {
	    		throw domain_error("");
	}
	return Rational (d1.Numerator()*d2.Denominator(),d1.Denominator()*d2.Numerator());
}

istream& operator>>(istream& istream, Rational& d){
	int n, m;
	string s;
	istream >> s;
    if (s == "") {exit(1);}
	stringstream ss(s);
	if(not (ss >> n)){
		throw invalid_argument("");
	}
	if (ss.peek() != '/') {
		throw invalid_argument("");
	}
	ss.ignore(1);
	if(not (ss >> m)){
		throw invalid_argument("");
	}
	string e;
	ss >> e;
	if(e != "") {
		throw invalid_argument("");
	}
	d = Rational(n,m);
	return istream;
}

ostream& operator<<(ostream& stream,const Rational& d){
	stream << d.Numerator();
	stream << "/";
	stream << d.Denominator();
	return stream;
}

bool operator<(Rational d1, Rational d2){
	return (d1.Numerator()*d2.Denominator() < d2.Numerator()*d1.Denominator());
}

int main() {
	Rational d1, d2;
	char c;
	cout << "To calculate something, enter an expression like: 1/2 + 1/2" << endl;
    try {
	while(cin >> d1){
	cin >> c >> d2;
	try {
		if (c == '/') {cout << d1 / d2 << endl;}
	    if (c == '+') {cout << d1 + d2 << endl;}
	    if (c == '-') {cout << d1 - d2 << endl;}
	    if (c == '*') {cout << d1 * d2 << endl;}
	} catch (domain_error&) {cout << "Division by zero"; return 0;}
	}
    } catch (invalid_argument&) {cout << "Invalid argument";return 0;}

}
