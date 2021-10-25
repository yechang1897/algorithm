#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int partition(vector<int>& a, int start, int end) {
    int point = a[start];
    while(start < end)
    {
        while(start < end && a[end] >= point)
            end--;
        a[start] = a[end];
        while(start < end && a[start] <= point)
            start++;
        a[end] = a[start];
    }
    a[start] = point;
    return start;

}

vector<int> quickSort(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    stack<int> stk;
    if(start < end)
    {
        stk.push(end);
        stk.push(start);
        while(!stk.empty())
        {
            int l = stk.top();
            stk.pop();
            int r = stk.top();
            stk.pop();
            int index = partition(nums,l,r);
            if(l < index-1)
            {
                stk.push(index-1);
                stk.push(l);
            }
            if(r > index+1)
            {
                stk.push(r);
                stk.push(index+1);
            }
        }
    }
    return nums;
}

int main() {
    vector<int> nums = {2, 3, 1, 5, 8, 19};
    vector<int> res = quickSort(nums);
    for(auto x : res) cout << x << " ";
    return 0;
}