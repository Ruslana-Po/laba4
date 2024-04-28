#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <Windows.h>
using namespace std;
const float E = 0.0001;
//𝑥 𝑙𝑛( 𝑥 + 1) = 1
float f(float x) {
	return (x * log(x + 1) - 1);
}
float f1(float x) {
	return x / (x + 1) + log(x + 1);
}
//методом половинного деления
void halfDivision(float a, float b) {
	if (f(a) * f(b) >= 0.0) {
		cout << "Неверный интервал" << endl;
		return;
	}
	int k = 0;
	float c = 0;
	while (abs(b - a) >= E) {
		cout << setw(7) << k << "|" << setw(8) << fixed << setprecision(4) << a << " | " << setw(8) << b << "|" << b - a << endl;
		c = (a + b) / 2;
		if (f(c) == 0.0) {
			break;
		}
		else if (f(c) * f(a) < 0) {
			b = c;
		}
		else {
			a = c;
		}
		k++;
	}

	cout << "Корень " << c << " с " << k << " итерациями" << endl;
}
//Метод Ньютона
void newtonMethod(int a, int b, float x0) {
	if (f(a) * f(b) >= 0.0) {
		cout << "Неверный интервал" << endl;
		return;
	}
	int k = 0;
	float x1 = x0 - f(x0) / f1(x0);
	while (abs(x1 - x0) >= E) {
		cout << setw(7) << k << "|" << setw(8) << fixed << setprecision(4) << x0 << " | " << setw(8) << x1 << "|" << x1 - x0 << endl;
		x0 = x1;
		x1 = x0 - f(x0) / f1(x0);
		k++;
	}
	cout << "Корень " << x0 << " с " << k << " итерациями" << endl;
}
//метода простых итераций
void simpleIterations(float x0) {
	int k = 0;
	float x1 = 1 / log(x0 + 1);
	while (abs(x1 - x0) > E) {
		cout << setw(7) << k << "|" << setw(8) << fixed << setprecision(4) << x0 << " | " << setw(8) << x1 << "|" << x1 - x0 << endl;
		x0 = x1;
		x1 = 1 / log(x0 + 1);
		k++;
	}
	cout << "Корень " << x0 << " с " << k << " итерациями" << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "программу уточнения корня методом половинного деления с точностью до E" << endl;
	halfDivision(-1, 1);
	cout << endl << "программу уточнения корня Ньютоном с точностью до E" << endl;
	newtonMethod(-10, 10, 10);
	cout << endl << "метода простых итераций" << endl;
	simpleIterations(2);
}

