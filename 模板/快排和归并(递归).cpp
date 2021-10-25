#include<iostream>
#include<vector>
using namespace std;

void quick_sort(vector<int>& nums, int l, int r) {
    if(l >= r) return;

    int t = nums[(l + r) >> 1];
    int i = l - 1, j = r + 1;
    while(i < j) {
        // cout << i << " " << j << endl;
        do(i++); while(nums[i] < t);
        do(j--); while(nums[j] > t);
        if(i < j) swap(nums[i], nums[j]);
    }
    
    quick_sort(nums, l, j);
    quick_sort(nums, j + 1, r);
}

void merge_sort(vector<int>& nums, int l, int r) {
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);
    int i = l, j = mid + 1;

    vector<int> temp;
    temp.clear();
    while(i <= mid && j <= r) {
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }
    while(j <= r) {
        temp.push_back(nums[j]);
        j++;
    }

    for(int i = l, k = 0; i < r; i++) nums[i] = temp[k++];
}

int main() {
    vector<int> nums = {2,1,5,6,7,9,4};
    quick_sort(nums, 0, 6);
    // merge_sort(nums, 0, 6);
    for(auto x : nums) {
        cout << x << " ";
    }
    cout << endl;
}