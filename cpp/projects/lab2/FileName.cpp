#include <iostream>
using namespace std;
unsigned km;
unsigned metr = 0;
unsigned i = 0;

int main() {
	setlocale(LC_ALL, "RU");
	cout << "¬ведите м: ";
	cin >> km;
	metr += km % 1000;
	km /= 1000;
	cout << "\n" << km << " километра и " << metr << " метров \n";
	system("pause");
}