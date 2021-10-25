#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

bool containZero(int n) {
    while(n > 0) {
        if(n % 10 == 0) {
            return false;
        }
        n /= 10;
    }
    return true;;
}

vector<int> getNoZeroIntegers(int n) {
    vector<int> res;
    for(int i = 1; i < n; ++i) {
        if(containZero(i) && containZero(n - i)) {
            res.emplace_back(i);
            res.emplace_back(n - i);
            break;
        }
    }
    return res;
}

int main() {
    int n = 11;
    cout << containZero(1) << endl;
    for(int i : getNoZeroIntegers(n)) {
        cout << i << endl;
    }
}
