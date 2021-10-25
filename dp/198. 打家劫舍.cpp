#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
    int sz = nums.size();
    vector<int> f(sz + 1);
    f[0] = 0;
    f[1] = nums[0];
    for(int i = 2; i <= sz; i++) {
        f[i] = max(f[i - 2] + nums[i - 1], f[i - 1]);
    }
    return f[sz];
}

int main() {
    vector<int> nums;
    while(true) {
        int n;
        cin >> n;
        nums.push_back(n);
        if(getchar() == '\n') break;
    }
    cout << rob(nums);
}