#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<vector<int>> nums = {{1,3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> nums2 = {{1,4}, {4, 5}};
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    
    for(int i = 0; i < nums.size(); i++) {
        int L = nums[i][0], R = nums[i][1];
        if(res.empty() || res.back()[1] < L) {
            res.push_back({L, R});
        } else {
            res.back()[1] = max(res.back()[1], R);
        }        
    }
    for(int i = 0; i < res.size(); i++) {
       cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}