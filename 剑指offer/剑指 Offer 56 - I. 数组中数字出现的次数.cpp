#include<iostream>
#include<vector>
using namespace std;
//分组，分为两组，把两个不重复的分到不同的组里面。
vector<int> singleNumbers(vector<int>& nums) {
    int t = 0;
    for(int x : nums) {
        t ^= x;
    }
    int div = 1;
    while((div & t) == 0) {
        div <<= 1;
    }
    int a = 0, b = 0;
    for(int x : nums) {
        if(x & div) {
            a ^= x;
        } else {
            b ^= x;
        }
    }
    return vector<int>{a, b};
}

int main() {
    vector<int> nums = {4, 1, 4, 6};
    cout << singleNumbers(nums)[0]<< " " << singleNumbers(nums)[1] << endl;
    return 0;
}