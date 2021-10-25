#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int majorityElement(vector<int>& nums) {
    map<int,int> m;
    for(int i = 0; i < (int)nums.size(); i++) {
        if(m.find(nums[i]) != m.end()) {
            m[nums[i]] += 1;
        } else {
            m[nums[i]] = 1;
        }
    }   
    int res = 0;
    int temp = 0;
    map<int,int>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        if(temp < it->second) {
            temp = it->second;
            res = it->first;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {3, 2, 3};
    cout << majorityElement(nums);
}