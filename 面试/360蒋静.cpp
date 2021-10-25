#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> before(n + 2, 0);
    vector<int> after(n + 2, 0);

    // before[0] = 0;
    // after[n - 1] = 0;
    for (int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i - 1]) {
            before[i] = before[i - 1] + 1;
        } else {
            before[i] = 0;
        }
    }

    for (int i = nums.size() - 2; i >= 0; i--) {
        if(nums[i] > nums[i + 1]) {
            after[i] = after[i + 1] + 1;
        } else {
            after[i] = 0;
        }
    }

    int res = 0;

    for (int i = 0; i < nums.size(); i++) {
        int t = after[i] + before[i] + 1;
        res = max(res, t);
    }
    cout << res << endl;
    return 0;
}