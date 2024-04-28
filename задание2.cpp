#include <iostream>
#include <Windows.h>
#include <random>
#include <vector>
using namespace std;
const int n = 12;
//cортировка возраствния
void sorting1(int* arr, int b, int e) {
	for (int i = b; i < e; ++i) {
		for (int j = i + 1; j < e; ++j) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
//cортировка убывание
void sorting2(int* arr, int b, int e) {
	for (int i = b; i < e; ++i) {
		for (int j = i + 1; j < e; ++j) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
//Соединение 
void conect(int* arr1, int* arr2) {
	for (int i = 0; i < n; i++) {
		if (i >= 0 && i <= 5) {
			int temp = arr1[i];
			arr1[i] = arr2[i+(n/2)];
			arr2[i + (n / 2)] = temp;
		}else{
			int temp = arr1[i];
			arr1[i] = arr2[i];
			arr2[i] = temp;
		}
	}
}
//Вывод
void conclusion(int arr[]) {
	for (int i = 0; i< n; i++) {
		cout << arr[i] << " ";
	}
}
//решета Эратосфена
void sieveEratosthenes(vector<int>& numberProst) {
	numberProst.push_back(2);
	//Поставила до 30 тк иначе ничего бы не вывело
	for (int i = 3; i <=30; i++)
	{
		int k = 0;
		for (int j = 0; j < numberProst.size(); j++) {
			if ((i % numberProst[j]) == 0) k++;
		}
		if (k == 0) {
			numberProst.push_back(i);
		}
	}
}
//Проверка
void examination(int arr[], vector<int> numberProst) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < numberProst.size(); j++) {
			if (arr[i] == numberProst[j]) {
				cout << arr[i] << " ";
			}
		}
	}
}
//Повтор
int repeat(int* arr1, int* arr2) {
	int j = 0;
	int x[4] = { 0,0,0,0 };
	for (int i = 0; i < n; i++) {
		int c = arr1[i];
		int kol = 0;
		while (c > 0) {
			x[kol] = c % 10;
			c /= 10;
			kol++;
		}
		int counter = 0;
		for (int z = 0; z < 3; z++) {
			for (int y = z+1; y < 4; y++) {
				if (x[z] == x[y]) {
					counter++;
					break;
				}
			}
			if (counter > 0) {
				break;
			}
		}
		if (counter == 1) {
			arr2[j] = arr1[i];
			j++;
		}
	}
	return j;
}
//Замена
void Replacement(char* arr) {
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 'A' && arr[i] <= 'Z') {
			arr[i] += 32;
		}
		else if (arr[i] >= 'a' && arr[i] <= 'z') {
			arr[i] -= 32;
		}
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int arr1[n];
	int arr2[n];
	random_device ran;
	uniform_int_distribution<> dist(10, 100); 

	//1 задание
	for (int i = 0; i < n; i++) {
		arr1[i] = dist(ran);
		arr2[i] = dist(ran);
	}
	cout << "arr1: ";
	conclusion(arr1);
	cout <<endl<< "arr2: ";
	conclusion(arr2);


	//Задание 2
	cout << endl << "Поиск простых элементов от 0-30: ";
	vector<int> numberProst;
	sieveEratosthenes(numberProst);
	cout << endl << "arr1: ";
	examination(arr1, numberProst);
	cout << endl << "arr2: ";
	examination(arr2, numberProst);


	//Задание 3
	cout << endl << "Отсортерованные массивы: ";
	// Сортировка первой половины массива arr1 по возрастанию
	sorting1(arr1, 0, n / 2);
	// Сортировка второй половины массива arr2 по убыванию
	sorting2(arr2, n/2, n);
	cout << endl<< "arr1: ";
	conclusion(arr1);
	cout << endl << "arr2: ";
	conclusion(arr2);
	conect(arr1,arr2);
	// Замена сортируемых на не сорт
	cout << endl << "Смена отсортированных элементов: ";
	cout << endl << "arr1: ";
	conclusion(arr1);
	cout << endl << "arr2: ";
	conclusion(arr2);


	// 4 задание
	char str[n];
	random_device rand1;
	uniform_int_distribution <> distr('A', 'z');
	char symbol;
	for (int i = 0; i < n; i++) {
		str[i] = distr(rand1);
	}
	cout << endl << "str: ";
	for (char i : str) {
		cout << i << " ";
	}
	cout << endl << "Замена: ";
	Replacement(str);
	cout << endl << "str: ";
	for (char i : str) {
		cout << i << " ";
	}

	// 5 задание
	int arr3[n];
	random_device sluch;
	uniform_int_distribution<> dist_sl(1000, 2000);
	for (int i = 0; i < n; i++) {
		arr3[i] = dist_sl(sluch);
	}
	cout << endl<< "arr3: ";
	conclusion(arr3);
	//Сортировка по убыванию
	sorting2(arr3, 0, n);
	cout << endl << "Отсортерованный массив: ";
	cout << endl << "arr3: ";
	conclusion(arr3);
	int newArr[n];
	int k = repeat(arr3, newArr);
	cout << endl << "C повторяющимися цифрами: ";
	cout << endl << "newArr: ";
	for (int i = 0; i < k; i++) {
		cout << newArr[i] << " ";
	}
}
