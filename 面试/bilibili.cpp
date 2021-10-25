#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string fun(vector<int> d){
    int sz = d.size();
    sort(
        d.begin(), d.end(), [] ( int a, int b ) {
            return a > b;
        });
    int mod = 0;
    int sum = 0;
    for (int i = 0; i < sz; i++) {
        mod = (mod + d[i]) % 3;
        sum += d[i];
    }
    if(sum < 3)
        return "";
    string res = "";
    if(mod == 0) {
        for (auto x : d) {
             res.push_back(x + '0');
        }           
    } else {
        int i;
        for (i = sz - 1; i >= 0; i++) {
            if(d[i] % 3 == mod) {
                break;
            }
        }
        for (int j = 0; j < sz; j++) {
            if(j != i) {
                res.push_back(d[j] + '0');
            }                
        }
        if(res.size() == sz) {
              return "";
        }          
    }
    return res;
}

int main() {
    vector<int> d = {1, 4, 2};
    cout << fun(d) << endl;
    return 0;
}
