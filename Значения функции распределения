#include<iostream>
#include<vector>
#include<fstream>

int main() {
    std::ofstream resout;
    resout.open("results.txt");

    int t = 1;
    double G = 0.05;
    int T_max = 100;
    double x = 0;

    std::vector<double>initial;
    std::vector<double>value;
	

	

	for (int i = 0; i <= 9; ++i) {
		double f = std::exp(-x*x/2 + 2.5);
		initial.push_back(f);
		x = x + 1;
	}
	initial.push_back(0);

	for (double& f : initial) {
		resout << f << " ";
	}
	resout << std::endl << std::endl;



	while (t <= T_max) {
		for (int i = 0; i < 9; i++) {
			value.push_back(initial[i] - G * (initial[i + 1] - initial[i]));
		}
		value.push_back(initial[9] - G * (initial[10] - initial[9]));
		value.push_back(0);


		for (double& v : value) {
			resout << v << " " << std::endl;
		}
		initial.swap(value);
		value.clear();
		resout << std::endl << std::endl;
		t = t + 1;
	}
	
	
	resout.close();
}
