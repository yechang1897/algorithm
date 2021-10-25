#include<iostream>

using namespace std;

int main() {
    int C;
    cin >> C;
    int N;
    cin >> N;
    int cur = 0;
    int f[N];
    int flag = 0;
    while(N--) {
        int P,O;
        cin >> P >> O;
        int need = (O - cur) * P;
        f[flag] = min(f[flag - 1] + need , f[flag - 1]);
        cur = 0;
        flag += 1;
    }
}