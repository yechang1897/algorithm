#include<iostream>

using namespace std;

int main() {
    double t;
    cin >> t;
    string tar = to_string(t);
    // cout << t << endl;
    int len = 0;
    for(int i = 0; i < tar.size(); i++) {
        if(tar[i] == '.') {
            len = i + 3;
        }
    }
    for(int i = 100; i <= 3000; i += 100) {
        for(int j = 1; j <= 30; j++) {
            double x = i / (double)j;
            string t = to_string(x);
            int k;
            for(k = 0; k < len; k++) {
                if(tar[k] != t[k]) break; 
            }
            if(k == len) {
                cout << (i / 100) <<"/" << j << endl;
                return 0;
            }
        }
    }
    return 0;    
}