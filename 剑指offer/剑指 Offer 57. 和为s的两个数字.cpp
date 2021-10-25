#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_set<int> set;
    for(auto x : nums) {
        if(set.find(target - x) == set.end()) {
            set.insert(x);
        } else {
            cout << set.size() << endl;
            return vector<int>{x, target - x};
        }
    }
    cout << set.size() << endl;
    return vector<int>();
}

int main() {
    vector<int> nums = {14,15,16,22,53,60};
    int target = 76;
    vector<int> res = twoSum(nums, target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}