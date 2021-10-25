#include<iostream>
#include<vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> nums;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        bool flag = true;
        for(int i = 1; i < n; i++) {
            if((nums[i] - nums[0]) % 2) flag = false;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}