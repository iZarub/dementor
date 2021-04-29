#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using std::vector;
using std::cout;
using std::cin;
using std::string;











int main() {
    int N;
    cin >> N;
    vector<int>p;
    vector<int>shag;
    vector<int>sum;


    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        p.push_back(a);
    }
    
    sum.push_back(p[0]);
    shag.push_back(-1);
    sum.push_back(p[1]);
    shag.push_back(-1);

    for (int i = 2; i < N; ++i) {
        if (sum[i - 1] > sum[i - 2]) {
            sum.push_back(p[i] + sum[i - 2]);
            shag.push_back(i - 2);
        
        }
        else {
            sum.push_back(p[i] + sum[i - 1]);
            shag.push_back(i - 1);
        
        }
    }
    vector<int> Wag;
    int wag;
    wag = N - 1;
    while (wag != -1) {
        wag = shag[wag];
        Wag.push_back(wag);
    }
    Wag.pop_back();
    for (int i = Wag.size(); i > 0; ++i) {
        cout << Wag[i];
    }


    cout << sum[N - 1];
    

    
}
