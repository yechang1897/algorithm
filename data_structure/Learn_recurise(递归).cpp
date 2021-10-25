#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
// #include<bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;
// vector<int> nums(6);
vector<bool> visit(6);

//所有子集
void subset(int k) {
    if(k == n + 1) {
        for(int i = 0; i < (int)nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return;
    }
    //不选择这个数
    subset(k + 1);

    //选择这个数
    nums.push_back(k);
    subset(k + 1);
    nums.pop_back();
    
}

//组合枚举 全排列一个数组中的k个数。
//选择或者不选，当数组长度大于m个数直接退出，剩下的数字小于 （m - nums.size()）也直接返回
void enmueration(int k, int m) {
    if((int)nums.size() > m || (nums.size() + (n - k + 1)) < m) 
        return;
    if(k == n + 1) {
        for(int i = 0; i < m; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return;
    }
    enmueration(k + 1, m);
    nums.push_back(k);
    enmueration(k + 1, m);
    nums.pop_back();
}

//全排列
void fullPermutation1(int k) {
    // cout << "test" << endl;
    if(k == n + 1) {
        for(int i = 1; i <= n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!visit[i]) {
            nums[k] = i;
            visit[i] = true;

            fullPermutation1(k + 1);
            
            // nums[k] = -1;
            visit[i] = false; 
        }
    }
}


int main() {
    // cout << "hello" << endl;
    n = 5;
    subset(1);
    // enmueration(1,3);
    // fullPermutation1(1);
}