#include<iostream>
#include<vector>
using namespace std;

int main() {
    int m;
    cin >> m;
    while(m--) {
        int n, k;
        cin >> n >> k;
        int l = 0;
        int r = 0;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            if(temp >= k && flag == 0) {
                l = i;
                flag = 1;
            }
            if(temp < k && flag == 1) {
                r = i - 1;
                flag = 2;
            }
        }
        if(flag == 0)
            cout << "false" << endl;
        else {
            cout << "true " << l << " " << r << endl;
        }
    }
    return 0;
}