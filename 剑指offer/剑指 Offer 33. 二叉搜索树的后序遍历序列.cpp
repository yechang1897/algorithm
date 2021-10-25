#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool verifyPostorder(vector<int>& postorder) {
    int sz = postorder.size();
    stack<int> stk;
    stk.push(postorder[sz - 1]);
    for(int i = sz - 2; i >= 0; i--) {
        if(stk)
    }
}

int main() {
    vector<int> nums = {1, 6, 3, 2, 5};
    vector<int> nums2 = {1, 3, 2, 6, 5};
    
}