#include<iostream>
#include<vector>
using namespace std;

void quick_sort(vector<int>& nums, int l, int r) {
    if(l >= r) return;

    int t = nums[l + (r - l) / 2];

    int i = l - 1, j = r + 1;
    while(i < j) {
        do(i++);while(nums[i] < t);
        do(j--);while(nums[j] > t);
        if(i < j) swap(nums[i], nums[j]);
    }
    // cout << i << " " << j << endl;
    quick_sort(nums, l, j);
    quick_sort(nums, j + 1, r);
}

void merge_sort(vector<int>& nums, int l, int r) {
    if(l >= r) return;

    int mid = l + (r - l) / 2;

    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);

    int i = l, j = mid + 1;
    vector<int> t;
    t.clear();
    while(i <= mid && j <= r) {
        if(nums[i] <= nums[j]) t.push_back(nums[i++]);
        else t.push_back(nums[j++]);
    }
    while(i <= mid) t.push_back(nums[i++]);
    while(j <= r) t.push_back(nums[j++]);

    for(int i = l, k = 0;i <= r; i++ ) nums[i] = t[k++];
}

vector<int> sortArray(vector<int>& nums) {
    merge_sort(nums, 0, nums.size() - 1);
    return nums;
}

int main() {
    vector<int> nums = {5,2,3,1}; 
    for(auto x : sortArray(nums)) cout << x << " ";
    cout << endl;
    return 0;
}