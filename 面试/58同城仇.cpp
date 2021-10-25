#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 5};
    int target = 11;

    vector<int> f(target + 1, target + 1);
    f[0] = 0;
    for (int i = 0; i < nums.size(); i++){
        for (int j = 1; j <= target; j++) {
            if(nums[i] <= j) {
                f[j] = min(f[j], f[j - nums[i]] + 1);
            }
            //cout << f[j] << endl;
        }
    }

    // for(auto x : f) {
    //     cout << x << " ";
    // }
    // cout << endl;
    if(f[target] == target + 1)
        cout << -1 << endl;
    else 
        cout << f[target] << endl;
    return 0;
}