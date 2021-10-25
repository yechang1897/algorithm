#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool isPalindrome(int x) {
    vector<int> nums;
    while(x > 0) {
        nums.push_back(x % 10);
        x /= 10;
    }
    int i = 0, j = (int)nums.size() - 1;
    while(i < j) {
        if(nums[i] != nums[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    int x = 121;
    cout << isPalindrome(x);
}