#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
    string str;
    cin >> str;
    int sz = str.size();
    stack<char> stk;
    long long count = 0;
    int temp = 1;
    for(int i = 0; i < sz;) {
        if(str[i] == '['){
            stk.push(str[i]);
            i += 1;
        }
        else if(str[i] == ']'){ 
            stk.pop();
            int num = i + 1 < sz ? (str[i + 1] - '0') : 1;
            if(str[i - 1] != '[') {
                temp = temp * num + num;
            } else {
                temp = temp * num;
            }       
            i += 2;
            if(stk.empty()) {
                count += temp;
                temp = 1;
            }
        }
    }
    cout << count;
    return 0;
}