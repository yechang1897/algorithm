#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;
    int i = 0;
    for(auto x : pushed) {
        stk.push(x);
        while(!stk.empty() && stk.top() == popped[i]) {
            stk.pop();
            i++;
        }
    }
    return stk.empty();
}

int main() {
    vector<int> pushed = {1, 2, 3, 4 ,5};
    vector<int> popped = {4, 5, 3, 1, 2};
    cout << validateStackSequences(pushed, popped);
    return 0;
}