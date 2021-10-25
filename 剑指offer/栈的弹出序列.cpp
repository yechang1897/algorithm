#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;
    int i = 0;
    for(auto x : pushed) {
        stk.push(x);
        // cout << stk.size() << endl;
        while(!stk.empty()&&stk.top() == popped[i]) {
            stk.pop();
            i++;
        }
        // cout << stk.size() << endl;
    }
    return stk.empty();
}

int main() {
    vector<int> pushed = {1,2,3,4,5}, popped = {4,5,3,2,1};
    cout << validateStackSequences(pushed, popped);
    return 0;
}
