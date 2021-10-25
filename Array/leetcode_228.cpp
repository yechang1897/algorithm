#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//负数和大于10的不能直接通过+'0'的方式将其转换为字符串
vector<string> summaryRanges(vector<int>& nums) {
    int start = 0;
        vector<string> res;
        if(nums.size() == 0) return res;
        if(nums.size() == 1) {
            char s = nums[0] + '0';
            char tempC[2] = {s};
            res.push_back(tempC);
            return res;
        }
        int i = 1;
        while(i <= (int) nums.size()) {
        if(nums[i] != nums[i - 1] + 1) {
            if(i == start + 1) {
                char s = nums[start] + '0';
                char tempC[2] = {s};
                res.push_back(tempC);
                start = i;
            } else {
                    char s = nums[start] + '0';
                    char e = nums[i - 1] + '0';
                    char tempC[5] = {s , '-', '>', e};
                    string temp = tempC;
                    res.push_back(temp);
                    start = i;
                }
            }
            i++;
        }
        return res;
}

string trans(vector<int> nums) {
    int sz = (int)nums.size();
    if (sz == 1) {
        return to_string(nums[0]);
    }
    string start = to_string(nums[0]);
    string end = to_string(nums[sz - 1]);
    return start + "->" + end;
}

vector<string> summaryRanges_2(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    temp.push_back(nums[0]);
    for(int i = 1; i < (int)nums.size(); i++) {
        if (nums[i] == nums[i - 1] + 1) {
            temp.push_back(nums[i]);
        } else {
            res.push_back(temp);
            temp.clear();
            temp.push_back(nums[i]);
        }
    }
    res.push_back(temp);
    vector<string> ans;
    for (vector<int> v: res) {
        string s = trans(v);
        ans.push_back(s);
    }
    return ans;
}

int main() {
    vector<int> nums = {0,2,3,4,6,8,9};
    //summaryRanges_2(nums);
    for(auto s : summaryRanges_2(nums)) {
        cout << s << " ";
    }
}