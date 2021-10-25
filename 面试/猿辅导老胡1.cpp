#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums;
    while(true) {
        int i;
        cin >> i;
        nums.push_back(i);
        if(getchar() == '\n') break;
    }
    int flag = 0;
    for(int i = 0; i < nums.size() - 1;i++) {
        if(nums[i]>nums[i + 1] && flag)  {
            cout << i + 2  << " ";
        }
        if(nums[i]>nums[i + 1] && !flag){
            cout << i + 1 << " ";
            flag = 1;
        }
        
    }
    return 0;
}