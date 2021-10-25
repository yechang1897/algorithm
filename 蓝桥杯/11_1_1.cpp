#include<iostream>

using namespace std;

int getTwo(int n) {
    int res = 0;
    while(n) {
        if(n % 10 == 2) res++;
        n /= 10;
    }
    return res;
}

int main() {
    int ans = 0;
    for(int i = 1; i <= 2020; i++) {
        ans += getTwo(i);
    }
    cout << getTwo(2222) << endl;
    cout << ans << endl;
}

/*
ans = 624
*/