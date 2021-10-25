#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSub = nums[0], curSum = 0;
    
    for (int n : nums) {
        if (curSum < 0)
            curSum = 0;
        curSum += n;
        maxSub = max(maxSub, curSum);
    }
    return maxSub;
}

int maxSubArray_2(vector<int>& nums) {
        vector<int> sums;
        int current_sum = 0, answer = nums[0];
        for(auto i : nums){
            current_sum += i;
            sums.push_back(current_sum);
            if(i > answer) answer = i;
        }
        for (auto i : sums) {
            cout << i << " ";
        }
        cout << endl;
        int min = 0;
        for(auto i : sums){
            if(min > i)
                min = i;
            else if(i - min > answer)
                answer = i - min;
        }
        return answer;
}

int maxSubArray_3(vector<int> nums) {
    // if (nums.size() == 0)
    //     return 0;
    
    
    // // Solution 1: 当sum为负数时，不管后面是正是负，基于负数的累加只可能小。所以一旦sum为负数时，就要移动start，直到sum为正或者start > end
    
    // int start = 0;
    // int end = 0;
    // int res = nums[0];
    // int adds = 0;
    
    // while (end < nums.size()) {
    //     adds += nums[end];
    //     res = max(res, adds);
        
    //     while (adds < 0 && start <= end) {
    //         adds -= nums[start];
    //         start ++;
    //     }
        
    //     end ++;
    // }
    
    // return res;
    
    //Solution2： O(n), 只扫描一遍，需两个变量，maxToCurrent = max (maxToCurrent + nums[index], nums[index])
    // 记录的是到当前num，当前最大的sum （因为取得的是二者最大值，如果之前的maxToCurrent为负，maxToCurrent就会被忽略掉）
    // 所以maxToCurrent一定是，走到当前num时，局部最大值。
    // 同时还需要：max = max (max, maxToCurrent)
    
   
    // int maxToCurrent = nums[0];
    // int res = nums[0];
    
    // for (int i = 1; i < (int)nums.size(); i++) {
    //     maxToCurrent = max (maxToCurrent + nums[i], nums[i]);
    //     res = max (res, maxToCurrent);
    // }
    
    // return res;

    
    // Solution3: divide and conquer
    return helper (nums, 0, nums.size() - 1);
    }
    
int helper (vector<int>& nums, int start, int end) {
    if (start == end) {
        return nums[start];
    }
    
    if (start > end) {
        return INT_MIN;
    }
    
    int middle = start + (end - start) / 2;
    int left = helper (nums, start, middle - 1);
    int right = helper (nums, middle + 1, end);
    int toLeft = 0;
    int toRight = 0;
    
    int sum = 0;
    for (int i = middle - 1; i >= start; i--) {
        sum += nums[i];
        
        if (sum > toLeft) {
            toLeft = sum;
        }
    }
    
    sum = 0;
    for (int i = middle + 1; i <= end; i++) {
        sum += nums[i];
        
        if (sum > toRight) {
            toRight = sum;
        }
    }
    
    
    return max (max (left, right), toLeft + nums[middle] + toRight);
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray_2(nums);
}