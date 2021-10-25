#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> nums1, vector<int> nums2) {
    int flag1 = 0, flag2 = 0;
    vector<int> res;
    while(flag1  < nums1.size() && flag2 < flag2 < nums2.size()) {
        if(nums1[flag1] < nums2[flag2]) {
            res.push_back(nums1[flag1]);
            flag1++;
        } else {
            res.push_back(nums2[flag2]);
            flag2++;
        }
    }
    if(flag1 < nums1.size()) {
        for(int i = flag1; i < nums1.size(); i++) {
            res.push_back(nums1[i]);
        }
    }
     if(flag2 < nums2.size()) {
        for(int i = flag2; i < nums2.size(); i++) {
            res.push_back(nums2[i]);
        }
    }
    return res;
}

int main() {
    vector<int> nums1 = {1, 4, 5, 6};
    vector<int> nums2 = {1, 1, 8, 9};
    for(auto x : merge(nums1, nums2)) {
        cout << x << " ";
    }
    return 0;
}