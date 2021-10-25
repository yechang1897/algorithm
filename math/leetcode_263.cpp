#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isUgly(int num) {
    while (num > 1) {
        int last = num;
        if(num % 2 == 0) {
            num /= 2;
            continue;
        }
        if(num % 3 == 0) {
            num /= 3;
            continue;
        }
        if(num % 5 == 0) {
            num /= 5;
            continue;
        }
        if (last == num) {
            return false;
        }
    }
    return num == 1 ? true : false;
}

int main () {
    int num = 8;
    cout << isUgly(num);
}