#include<iostream>

using namespace std;

int main() {
    int ans = 1;
    for(int i = 2; i <= 20; i++) {
       ans += 4 * (i - 1);
    }
    cout << ans;
}

/*
ans = 761
*/