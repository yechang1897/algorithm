#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for(int i = 0; i < (int) nums.size(); i++) {
        s.insert(nums[i]);
    }     
    return (int)s.size() == (int)nums.size();
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << containsDuplicate(nums);
}