#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cx = n / 2;
    int cy = n / 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(abs(i - cx) + abs(j - cy) <= n/2) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}