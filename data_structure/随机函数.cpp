#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int select(vector<int>& nums) {
    int sz = nums.size();
    //假设从1开始,等差数列求和。
    int sum = sz + (sz *(sz - 1)) / 2;
    int randNum = rand() % sum + 1;
    vector<int> temp(sum);
    int flag = 0;
    for(int i = 0; i < (int)nums.size(); i++) {
        for(int j = 0; j <= i; j++) {
            temp[flag++] = nums[i];
        }
    }
    return temp[randNum];
}

int main() {
    vector<int> nums = {2, 1, 3, 4, 6, 8, 5};
    cout << select(nums);
    return 0;
}