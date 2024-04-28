#include <iostream>
#include <Windows.h>
#include <random>
#include <vector>
using namespace std;
void algorithm1(int round_number, vector<bool>& own, vector<bool>& enemy) {
	if (round_number == 0) {
		// Сотрудничаем в первом раунде
		own.push_back(1); 
	}else {
		// Предаем в остальных раундах
		own.push_back(0); 
	}
}
void algorithm2(int round_number, vector<bool>& own, vector<bool>& enemy) {
	random_device r;
	uniform_int_distribution<> d(0, 1);
	own.push_back(d(r));
}
void algorithm3(int round_number, vector<bool>& own, vector<bool>& enemy) {
	if (own.size() > 0 && !enemy[own.size() - 1]) {
		// Если противник предал в предыдущем раунде, сотрудничаем
		own.push_back(1);
	}
	else {
		// Иначе предаем
		own.push_back(0);
	}
}
int main() {
	random_device ran;
	uniform_int_distribution<> dist(100, 200);
	int n = dist(ran);
	vector<bool> first;
	vector<bool> second;
	int check1 = 0;
	int check2 = 0;
	for (int i = 0; i < n; i++) {
		// 3 и 2 алгоритм
		algorithm3(i, first, second);
		algorithm2(i, second, first);
		// 2 и 1 алгоритм
		//algorithm2(i, first, second);
		//algorithm1(i, second, first);

		// 1 и 3 алгоритм
		//algorithm3(i, first, second);
		//algorithm2(i, second, first);

		if (first[i] && second[i]) {
			check1 += 24;
			check2 += 24;
		}else if(first[i] && !(second[i])){
			check1 += 0;
			check2 += 20;
		}else if (!first[i] && (second[i])) {
			check1 += 20;
			check2 += 0;
		}else if (!first[i] && !(second[i])) {
			check1 += 4;
			check2 += 4;
		}
		cout << first[i] << " " << second[i] << " " << check1 << " " << check2 << endl;
	}

}
