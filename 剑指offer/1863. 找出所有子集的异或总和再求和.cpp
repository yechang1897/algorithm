#include<iostream>
#include<vector>
using namespace std;

int subsetXORSum(vector<int>& nums) {
    int sz = nums.size();
    vector<int> f(sz + 1);
    for(int i = 1; i <= nums.size(); i++) {
        f[i] = f[i - 1] ^ nums[i];
    }
    for(auto x : f) cout << x << " ";
    cout << endl;
    int res = 0;
    for(int i = 2; i <= sz; i++) {
        for(int j = 0; j < sz - i + 1; j++) {
            int k = j + i - 1;
            cout << (f[k] ^ f[j - 1]) << endl;
            res += f[k] ^ f[j - 1];
        }
    }
    return res;
}

int main() {
    vector<int> nums = {5,1,6};
    cout << subsetXORSum(nums);
    return 0;
}

