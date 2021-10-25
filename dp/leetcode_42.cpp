#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
//dp方法，维持两个数组，一个保存当前下标左边最大的数字，一个保存当前下标右边最大的数字。
int trap(vector<int>& height) {
    int sz = height.size();
    if(sz == 0) {
        return 0;
    }
    vector<int> leftMax(sz);
    leftMax[0] = height[0];
    for(int i = 1; i < sz; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    vector<int> rightMax(sz);
    rightMax[sz - 1] = height[sz - 1];
    for(int i = sz - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }
    int res = 0;
    for(int i = 0; i < sz; i++) {
        res += min(leftMax[i], rightMax[i]) - height[i];
    }
    return res;
}
//单调栈
int trap_2(vector<int>& height) { 
    int ans = 0;
    stack<int> stk;
    int n = height.size();
    for (int i = 0; i < n; ++i) {
        /**
        *在栈中元素大于2之后，小于当前栈顶数字直接进栈，大于当前栈顶的数字需要计算当前能够盛多少水。
        *且计算方式是分层计算的。
        */
        while (!stk.empty() && height[i] > height[stk.top()]) {
            int top = stk.top();
            stk.pop();
            if (stk.empty()) {
                break;
            }
            int left = stk.top();
            int currWidth = i - left - 1;
            int currHeight = min(height[left], height[i]) - height[top];
            ans += currWidth * currHeight;
        }
        stk.push(i);
    }
    return ans;
}

int trap_3(vector<int>& height) {
    int res = 0;
    stack<int> sta;
    for(int i = 0; i < height.size(); i++) {
        int level = 0;
        while(!sta.empty() && height[sta.top()] < height[i]) {
            res += (height[sta.top()] - level) * (i - sta.top() - 1);
            level = height[sta.top()];
            sta.pop();
        }
        if(!sta.empty()) {
            res += (height[i] - level) * (i - sta.top() - 1);
        }
        sta.push(i);
    }
    return res;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap_3(height);
}