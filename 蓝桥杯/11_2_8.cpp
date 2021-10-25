#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N];

int n, K;

int main() {
    cin >> n >> K;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //能整除K的数
    int num = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % K == 0) num++; 
    }
    cout <<  num * (n - 1) << endl;
}