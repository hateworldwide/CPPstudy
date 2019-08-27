#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <set>
#include <exception>

using namespace std;

class Rational {
	public:
	Rational() {
		nu=0;
		de=1;
	}
	Rational (int n, int d) {
		if (d==0) throw 1;
		if (n<0 && d<0) {
			n *= -1;
			d *= -1;
		}
		if (n==0) {
			d=1;
		}
		if (d<0 && n>0) {
			n *= -1;
			d *= -1;
		}
	int nod = Nod(abs(n), abs(d));
	nu = n / nod; de = d / nod;}
	int Numerator() const {return nu;}
	int Denominator() const {return de;}
	private:
		int nu;
		int de;
	int Nod(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            }
            else {
                b %= a;
            }
        }
        return a + b;
    }
};

bool operator == (Rational n, Rational m) {
	if (n.Numerator() == m.Numerator() && m.Denominator() == n.Denominator()) {
		return 1;
	} else {
		return 0;
	}
}

Rational operator + (Rational n, Rational m) {
	return (Rational(n.Numerator()*m.Denominator()+m.Numerator()*n.Denominator(), n.Denominator()*m.Denominator()));
}

Rational operator - (Rational n, Rational m) {
	return (Rational(n.Numerator()*m.Denominator()-m.Numerator()*n.Denominator(), n.Denominator()*m.Denominator()));
}

Rational operator * (Rational n, Rational m) {
	return (Rational(n.Numerator()*m.Numerator(), n.Denominator()*m.Denominator()));
}

Rational operator / (Rational n, Rational m) {
	if (m.Numerator() == 0 || n.Denominator() == 0) throw 2;
	return (Rational(n.Numerator()*m.Denominator(), n.Denominator()*m.Numerator()));
}

istream& operator >> (istream& stream, Rational& r) {
	int n, m;
	if (stream >> n && stream.ignore(1) && stream >> m) {
		r= {n, m};
	}
	return stream;
}

ostream& operator << (ostream& stream, const Rational& r) {
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}

bool operator < (Rational n, Rational m) {
	if (n.Numerator()*m.Denominator()<n.Denominator()*m.Numerator()) {
		return 1;
	} else {
		return 0;
	};
}

bool operator > (Rational n, Rational m) {
	if (n.Numerator()*m.Denominator()>n.Denominator()*m.Numerator()) {
		return 1;
	} else {
		return 0;
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
try {
	Rational a, b; char c;
	cin >> a >> c >> b;
	if (c=='+') {cout << a + b << endl;}
	if (c=='-') {cout << a - b << endl;}
	if (c=='/') {cout << a / b << endl;}
	if (c=='*') {cout << a * b << endl;}
} catch (int r) { if (r==1) {cout << "Invalid argument"<< endl;} else {
	cout << "Division by zero" << endl;
}}
    return 0;
}
