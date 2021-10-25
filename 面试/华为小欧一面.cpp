#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <sstream>

using namespace std;


int main() {
    vector<int> nums = {32, 321, 34, 5, 9};
    // vector<int> nums = {4};
    sort(nums.begin(), nums.end(), [](int & a, int& b){
        string astr = to_string(a);
        string bstr = to_string(b);
        int asz = astr.size();
        int bsz = bstr.size();
        int sz = asz < bsz ? asz : bsz;
        // cout << sz << endl;
        int flag = 0;
        for(int i = 0; i < sz; i++) {
            if(astr[i] < bstr[i]) {
                flag = -1;
                break;
            }  
            if(astr[i] > bstr[i]) {
                flag = 1;
                break;
            }
        }
        if(flag == -1) return (a < b) ? a > b : a < b; 
        if(flag == 1) return (a > b) ? a > b : a < b;
        return (asz < bsz ? a < b : a > b);
    });
    string nstr;
    for(auto x : nums) {
        nstr += to_string(x);
    }
    stringstream strIn;
    strIn<<nstr;

    long long num;
    strIn >> num;
    cout << num << endl;
    long long  x = 0, y = 1;
    long long t;
    while(y < num) {
        t = y;
        y = x + y;
        x = t;
    }
    cout << y << endl;
    return 0;
}