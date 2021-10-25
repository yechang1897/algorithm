#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int N = 1e5 + 10;
int dp[N];

int getNums(int n) {
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int getNum(vector<int> nums) {
    int l = 0, r = nums.size();
    while(l < r) {
        int mid = l + r + 1>> 1;
        if(nums[mid] <= mid + 1) l = mid;
        else r = mid - 1;
    }
    return l - 1;
}

int main() {
    // int n;
    // cin >> n;
    vector<int> nums = {0, 1,3,4};
    cout << getNum(nums);
}