#include<bits/stdc++.h>

using namespace std;

int nums[9];

bool check() {
    for(int i = 0; i <= 9; i++) {
        if(nums[i] == 2021)
            return false;
    }
    return true;
}

int main() {
    int num = 0;
    while(check()) {
        int t = num;
        while(t) {
            int digit = t % 10;
            nums[digit]++;
            t /= 10;
        }
        num++;
    }
    cout << num;
}