#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::string;


int main() {
	vector<int>dano;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		dano.push_back(k);
	}

	vector<vector<double>>maxrating;
	for (int i = 0; i < 10; i++) {
		maxrating[0][i] = 0;
	}
	
	for (int j = 1; j < 10; j++) {
		for (int i = 0; i < 10; i++) {
			maxrating[j][i] = std::max(maxrating[j - 1][i] + i / 1, maxrating[j - 1][i] + i / 2, maxrating[j - 1][i] + i / 3, maxrating[j - 1][i] + i / 4, maxrating[j - 1][i] + i / 5,
				maxrating[j - 1][i] + i / 6, maxrating[j - 1][i] + i / 7, maxrating[j - 1][i] + i / 8, maxrating[j - 1][i] + i / 9, maxrating[j - 1][i] + i / 10);
		}
	}



}
