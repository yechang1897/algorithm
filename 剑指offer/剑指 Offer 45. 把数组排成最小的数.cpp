#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

string minNumber(vector<int>& nums) {
    vector<string> strs;
    for(int i = 0; i < nums.size(); i++) {
        strs.push_back(to_string(nums[i]));
    }
    sort(strs.begin(), strs.end(), [](string x, string y){return x + y < y + x;});
    string res = "";
    for(int i = 0; i < strs.size(); i++) res.append(strs[i]);
    return res;
}

int main() {
    vector<int> nums = {128, 12};
    vector<int> nums2 = {3,30,34,5,9};
    vector<int> nums3 = {824,938,1399,5607,6973,5703,9609,4398,8247};
    // cout << ("34" < "3") << endl;
    cout << minNumber(nums3) << endl;
    return 0;
}