#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using std::vector;
using std::cout;
using std::cin;
using std::string;




void output(string name, string file) {
    std::ofstream resout(file, std::ios::app);
    if (resout.is_open()) {
        resout << name << std::endl;
    }
    resout.close();
}



class CIR {

protected:
    vector<double> prev;
    vector<double> pres;

public:
    CIR(int param_N) {
        prev.resize(param_N);
        pres.resize(param_N);
    }
};




class Scheme: public CIR {
    double t; // time step length
    int T; //quantity of time steps
    double h; //coord step length
    int N; //quantity of coord steps
    double c = 1; // speed

public:

    Scheme(int param_N, int param_T) : CIR (param_N){
        N = param_N;
        T = param_T;
        h = (double)1 / N;
        t = 0.5 * h / c;				// ct/h < 1, c = 1
    }



    void present_output() {
        for (int i = 0; i < N; i++) {

            output(std::to_string(pres[i]), "output.txt");
        }
        cout << std::endl;
    }


    void get_solve(vector<double> initial) {
        pres = initial;

        for (int i = 0; i < T; ++i) {
            prev = pres;
            pres.clear();


            double res_zero_x = prev[0] - c * t / h * (prev[0] - 0);
            pres.push_back(res_zero_x);
            for (int j = 1; j < N; ++j) {
                double res = prev[j] - c * t / h * (prev[j] - prev[j - 1]);
                pres.push_back(res);
            }
        }
        present_output();
    }


    void get_result() {
        for(int i = 0; i < pres.size(); ++i) {
            cout << pres[i] << " ";
        }
    }






};


int main() {
    int N = 2000;
    int T = 600;


    vector<double>initial;

    for (int i = 0; i < N; ++i) {
        if ((i > 0.2 * N) and (i < 0.4 * N)) {
            initial.push_back(0);
        }
        else {
            initial.push_back(1);
        }
    }


    for (int i = 0; i < N; ++i) {
        output(std::to_string(initial[i]), "initial.txt");
    }

    Scheme scheme(N, T);
    scheme.get_solve(initial);


}
