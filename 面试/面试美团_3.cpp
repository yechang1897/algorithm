#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<unordered_map>

using namespace std;

int getMost(unordered_map<int, int>& nums) {
    unordered_map<int, int>::iterator it;
    int i = it->second;
    int num = 0;
    int max1 = 0;
    int max2 = 0;
    int res = 0;
    int res1 = 0;
    for (it = nums.begin(); it != nums.end(); ++i) {
        if(i == it->second) {
            num++;
        }
        if(max1 < it->second) {
            max1 = it->second;
            res = it->first;
        }
    }
    for (it = nums.begin(); it != nums.end(); ++i) {
        if(max2 > it->second) {
            max2 = it->second;
            res1 = it->first;
        }
    }
    if(num == (int)nums.size()) {
       return res1; 
    }
    cout << res << endl;
    return res;
}

vector<int> getMostNum(vector<int>& nums, int K) {
    vector<int> res;
    for(int i = 0; i < (int)nums.size() - K; ++i) {
        cout << "hello2" << endl;
        unordered_map<int, int> m;
        for(int j = i; j < K; ++j) {
            if(m.find(nums[j]) == m.end()) {
                m[nums[j]] = 1;
            } else {
                m[nums[j]]++;
            }
        }
        res.push_back(getMost(m));
    }
    cout << "hello3" << endl;
    return res;
}



int main () {
    vector<int> nums = {1, 2, 2, 1, 3};
    for(int i : getMostNum(nums, 3)) {
        cout << i << endl;
    }
}