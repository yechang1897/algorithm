#include<iostream>
#include<cmath>
using namespace std;

bool check(int t) {
    while(t) {
        if(t % 10 == 2 || t % 10 == 0 || t % 10 == 1 || t % 10 == 9) {
            return true;
        }
        t /= 10;
    }
    return false;
}


int main() {
    long long int ans = 0;
    int res = 0;
    for(long long int i = 1; i <= 2019; i++) {
        long long int  t = i;
        while(t) {
            if(t % 10 == 2 || t % 10 == 0 || t % 10 == 1 || t % 10 == 9) {
                res ++;
                ans += i * i * i;
                // cout << "t: " << t << "ans: " << ans << endl;
                break;
            }
            t /= 10;
        }
    }
    long long int ans2 = 0;
    for(long long int i = 1; i <= 2019; i++) {
        if(check(i)){
            ans2 += i * i * i;
            // cout << "i: " << i << "ans2: " << ans2 << endl;      
        }        
    }
    cout << ans << endl;
    cout << ans2 << endl;
}

/*
res = 4097482414389
res = 4097482414389
*/