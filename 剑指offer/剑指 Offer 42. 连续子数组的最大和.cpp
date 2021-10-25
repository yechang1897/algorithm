#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int sz = nums.size();
    int f[sz];
    memset(f, 0, sizeof f);
    f[0] = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        f[i] = max(f[i - 1] + nums[i], nums[i]);
    }
    int res = *max_element(f, f + sz);
    return res;        
}

int main() {
    vector<int> num = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(num) << endl;
    return 0;
}