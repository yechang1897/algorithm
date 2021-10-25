#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int first = 0;
    int last = 0;
    vector<int> temp(m, 0);
    for(int i = 0; i < m; i++) {
        temp[i] = nums1[i];
    }
    for(int i = 0; i < (int)nums1.size(); i++) {
        if(first < m && last < n) {
            nums1[i] = temp[first] < nums2[last] ? temp[first] : nums2[last];\
            if(temp[first] < nums2[last]) first++;
            else last++;
        } else if(first == m){
            nums1[i] = nums2[last];
            last++;
        } else if(last == n) {
            nums1[i] = temp[first];
            first++;
        }
    }
}

int main() {
    vector<int> nums1 = {4, 0, 0, 0, 0, 0};
    int m = 1;
    vector<int> nums2 = {1, 2, 3, 5, 6};
    int n = 5;
    merge(nums1, m, nums2, n);
    for(int i : nums1) {
        cout << i << " ";
    }
}