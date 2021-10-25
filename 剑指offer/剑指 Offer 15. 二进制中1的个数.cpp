#include<iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    int res = 0;
    int temp = 1;
    while(n >= temp) {
        cout << temp << " " << res << endl;
        if(n & temp ) {
            
            res++;
        }
        temp = temp << 1;
    }
    return res;        
}

int main() {
    uint32_t n = 11;
    cout << hammingWeight(n) << endl;
    return 0;
}