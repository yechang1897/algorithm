#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int ones[8] = {11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
bool check(long long n) {
    int q = n / 11;
    int p = n % 11;
    if(q >= p * 10) return true;
    else return false;    
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int res = 0;
    for(int i = 0; i < n; i++) {
       long long t; 
       cin >> t;
       if(check(t)) res++;
    }
    //cout << check(111111233) << endl;
    cout << res;
    return 0;
}