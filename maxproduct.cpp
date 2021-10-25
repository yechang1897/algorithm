#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int maxProduct(vector<int> &nums){
    vector<int> maxN, minN;
    int n = nums.size();
    maxN.resize(n);
    minN.resize(n);
    maxN[0] = minN[0] = nums[0];
    int res = -INT_MAX;
    for (int i = 1; i < n; i++) {
        if(nums[i] < 0) {
            maxN[i] = max(minN[i - 1] * nums[i], nums[i]);
            minN[i] = min(maxN[i - 1] * nums[i], nums[i]);
        } else {
            maxN[i] = max(maxN[i - 1] * nums[i], nums[i]);
            minN[i] = min(maxN[i - 1] * nums[i], nums[i]);
        }
        res = max(maxN[i], res);
    }
    return res;
}

int main(){
    vector<int> nums = {2, 3, -2, 4,2};
    cout << maxProduct(nums);
}