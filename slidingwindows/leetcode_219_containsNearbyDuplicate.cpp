#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if((int)nums.size() < k) return false;
    if(k < 0) return false;
    unordered_set<int> record;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (record.find(nums[i]) != record.end()) {
            return true;
        } 
        record.insert(nums[i]);
        if ((int)record.size() == k + 1) {
            record.erase(nums[i - k]);
        }
    }
    return false;
}

bool containsNearbyDuplicate2(vector<int>& nums, int k) {
    unordered_set<int> record;
    for (size_t i = 0; i < nums.size(); i++) {
        if(record.find(nums[i]) != record.end()) {
            return true;
        }
        record.insert(nums[i]);
        if ((int)record.size() == k + 1) {
            record.erase(nums[i - k]);
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int k = 15;
    cout << containsNearbyDuplicate2(nums, k);
}