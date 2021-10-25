#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int findNthDigit(int n) {
    int digit = 1;
    long long start = 0;
    while(start < n) {
        start += 9 * pow(10, digit - 1) * digit++;
        // cout << start << endl;
    }
    digit--;
    start -=  9 * pow(10, digit - 1) * digit;
    int dis = n - start - 1;
    // cout << start << " " << digit <<  endl;
    // cout << dis << endl;
    int numstart = pow(10, digit - 1);
    int num = numstart + (dis / digit);
    int mod = dis % digit;
    if(mod == 0) return to_string(num)[0] - '0';
    else return to_string(num)[mod] - '0';  
}

int main() {
    int n = 1000; 
    cout << findNthDigit(n) << endl;
    return 0;
}