#include<iostream>
#include<cmath>
using namespace std;

int countDigitOne(int n) {
    int high = n / 10;
    int cur = n % 10;
    int low = 0;
    int digit = 0;
    int res = 0;
    while(high !=0 || cur != 0) {        
        if(cur == 0) res += high * pow(10, digit);
        else if(cur == 1) res += high * pow(10, digit) + low + 1;
        else res += (high + 1) * pow(10, digit);
        low += cur * pow(10, digit);
        cur = high % 10;
        high = high / 10;        
        digit++;
    }
    return res;        
}

int main() {
    int n = 12;
    cout << countDigitOne(n) << endl;
    return 0;
}