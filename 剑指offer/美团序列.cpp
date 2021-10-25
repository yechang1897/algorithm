#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int nums[n + 1];
        memset(nums, 0, sizeof nums);
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            nums[a] = 1;
        }
        int k;
        for(k = 1; k <= n; k++) {
            if(nums[k] == 0) {
                cout << "No" << endl;
                break;
            }
        }
        if(k == n + 1) cout << "Yes" << endl;
    }
    return 0;
}