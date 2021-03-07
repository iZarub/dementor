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

    double initial[11];
    double value[11];


	for (int i = 0; i <= 9; ++i) {
		double f = std::exp(-x*x/2 + 2.5);
		initial[i] = f;
		x = x + 1;
	}
	initial[10] = 0;

	for (double& f : initial) {
		resout << f << " ";
	}
	resout << std::endl << std::endl;



	while (t <= T_max) {
		for (int i = 0; i < 9; i++) {
			value[i] = (initial[i] - G * (initial[i + 1] - initial[i]));
		}
		value[9] = (initial[9] - G * (initial[10] - initial[9]));
		value[10] = (0);


		for (double& v : value) {
			resout << v << " " << std::endl;
		}

		for (int i=0; i < 11; i++) {
            initial[i] = value[i];
        }

		resout << std::endl << std::endl;
		t = t + 1;
	}


	resout.close();
}
