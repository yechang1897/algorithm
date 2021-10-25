#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums){
    int temp = nums[0];
    vector<int>::iterator it = nums.begin();
    it++;
    while(it != nums.end()){
        if (temp == *it){
            cout << *it << endl;
            nums.erase(it);
        } else {
            temp = *it++;
        }
    }
    return nums.size();
}

int removeDuplicates_2(vector<int>& nums){
    nums.erase(std::unique(nums.begin(), nums.end()),nums.end());
    return nums.size();
}

int removeDuplicates_3(vector<int>& nums) {
    return std::unique(nums.begin(), nums.end()) - nums.begin();
}

int main(){
    vector<int> vec = {1,1,2};
    cout << removeDuplicates_3(vec) << endl;
    vector<int>::iterator itor;
    for (itor = vec.begin(); itor < vec.end(); itor++){
        cout << *itor;
    }
}