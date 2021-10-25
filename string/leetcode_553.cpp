#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

string optimalDivision(vector<int>& nums) {
    int sz = (int)nums.size();
    if(sz == 1) {
        return to_string(nums[0]);
    } else if (sz == 2) {
        return to_string(nums[0]) + "/" + to_string(nums[1]);
    }
    string res = "";
    for (int i = 0; i < sz; ++i) {
        if(i == 0) {
            res += to_string(nums[0]);
        } else if(i == 1) {
            res += "/(" + to_string(nums[i]);
        } else {
            res += "/" + to_string(nums[i]);
        }
    }
    res += ")";
    return res;
}

int main() {
    vector<int> nums = {100, 1000, 10, 2};
    cout << optimalDivision(nums);
}

