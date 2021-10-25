#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cmath>

using namespace std;

bool isGood(int N) {
    int i = 0;
    while(pow(10, i) < N) {
        i++;
    }
    unordered_set<int> nums = {0, 1, 2, 5, 6, 8, 9};
    vector<int> digits;
    while(N > 0) {
        digits.push_back(N % 10);
        N /= 10;
    }
    vector<int> temp = digits;
    for (int i = 0; i < (int)digits.size(); ++i) {
        if (nums.find(digits[i]) == nums.end()) {
            return false;
        } else {
            if(digits[i] == 2) {
                digits[i] = 5;
            }
             else if(digits[i] == 5) {
                digits[i] = 2;
            }
            else if(digits[i] == 6) {
                digits[i] = 9;
            }
            else if(digits[i] == 9) {
                digits[i] = 6;
            }
        }
    }
    for(int i = 0; i < (int)digits.size(); ++i) {
        if (temp[i] != digits[i]) {
            return true;
        }
    }    
    return false;    
}

int rotatedDigits(int N) { 
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        if(isGood(i)) {
            res++;
        }
    }
    return res;
}

int main() {
    int N = 10;
    // cout << isGood(8) << endl;
    cout << rotatedDigits(N);
}