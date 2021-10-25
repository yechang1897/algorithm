#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sum(n + 1);
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
        sum[i] = sum[i - 1] + t;
    }
    int res = 0;
    for(int i = 1; i <=n; i++) {
        if(nums[i] + sum[i - 1] - sum[0] > 0) res++;
    }
    cout << res << endl;
    return 0;
}