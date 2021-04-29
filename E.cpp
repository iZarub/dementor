#include<iostream>
#include<vector>
#include<cmath>
#include<string>


using std::vector;
using std::cout;
using std::cin;
using std::string;


vector<int> run(vector<int>arr) {
	vector<int>value;
	value.resize(arr.size());
	value[0] = 1;
	for (int i = 0; i < arr.size() - 1; i++) {
		if ((arr[i] + i) < arr.size() and arr[i] != 1) {
			value[arr[i] + i] = (value[arr[i] + i] + value[i]) % 937;
		}
		value[i + 1] = (value[i] + value[i + 1]) % 937;
	}
	return value;
}








int main() {
	int n;
	cin >> n;
	vector<int>arr;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		arr.push_back(a);
	}


	cout << std::endl;

	cout << run(arr)[n - 1] % 937;
	


  
}
