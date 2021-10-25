#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int bitwiseComplement(int N) {
    if(N == 0) return 1;
    int flag = 0;
    while(pow(2,flag) <= N) {
        flag++;
    }
    cout << flag << endl;
    int res = pow(2, flag) - 1;
    return res - N;
}

int main() {
    int N = 1;
    cout << bitwiseComplement(N);
}