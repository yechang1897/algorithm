#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end(), nums.end()));
        for(auto x : nums) {
            cout << x << " ";
        }
        cout << endl;
        for(int i = 1; i <= n; i++) {
            if(i > nums[k]) {
                cout << "YES" << endl;
                cout << i << endl;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}