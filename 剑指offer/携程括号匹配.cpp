#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

bool isValid(string temp) {
    stack<char> stk;
    int sz = temp.size();
    for(int i = 0;i < sz; i++) {
        if(temp[i] == ')') {
            if(stk.empty()) {
                return false;
            } else {
                stk.pop();
            }
        } else {
            stk.push(temp[i]);
        }
    }
    return stk.empty();
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int num = 0;
    vector<int> nums;
    stack<char> stk;
    for(int i = 0; i < n; i++) {
        string temp = str;
        temp.erase(temp.begin() + i);
        if(isValid(temp)) {
            num++;
            nums.push_back(i + 1);
        }
    }
    cout << num << endl;
    for(auto x : nums) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}