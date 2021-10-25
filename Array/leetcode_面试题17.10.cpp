#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//摩尔投票O(N)
int majorityElement(vector<int>& nums) {
    int count = 0, major = 0;
    for (int e : nums) {
        if(count == 0) {
            major = e;
            count = 1;
        } else {
            if (major == e) {
                count++;
            } else {
                count--;
            }
        }
    }
    int C = 0;
    for(int e : nums) {
        if(major == e) {
            C++;
        }
    }
    if(C <= (int)nums.size() / 2)
        return -1;
    return major;
}
//位运算O(32 * N)
int majorityElement_2(vector<int>& nums) {
    int res = 0;
    int n = (int)nums.size();
    for (int i = 0; i < 32; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] & (1 << i)) {
                count++;
            }
        }
        if (count > n / 2) {
            res ^= (1 << i);
        }
    }
    int C = 0;
    for(int e : nums) {
        if(e == res) {
            C++;
        }
    }
    if(C <= n / 2) {
        return -1;
    }
    return res;
}

int main() {
    // vector<int> nums = {1, 2, 5, 9, 5, 9, 5, 5, 5};
    vector<int> nums = {1, 2, 3};
    cout << majorityElement_2(nums);
}