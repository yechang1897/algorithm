#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
    }    
    int res = 0;
    int cur = nums[0];
    int t = 0;
    for(int i = 0; i < n; i++) {
        if(cur == nums[i]) t++;
        else {
            if(i != n - 1 && cur == nums[i + 1]) {
                res = max(res, t + 1);
                t = 1;
                cur = nums[i];
            } else {
                res = max(res, t);
                t = 1;
                cur = nums[i];
            }
        }
    }
    // cout << t << endl;
    cout << res << endl;

}