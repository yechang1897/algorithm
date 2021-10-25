#include<iostream>
#include<stack>
#include<string>
using namespace std;

string getString(string str) {
    int sz = str.size();
    stack<char> stk;
    stack<int> num;
    int tnum = 0;
    string tstr = "";
    for (int i = 0; i < sz; i++) {
        if(str[i] == '[') {
            if(i == 0)
                stk.push(str[i]);
            else {
                
            }
        } else if(str[i] == ',') {
            num.push(tnum);
            
        } else if(str[i] >= 'a' && str[i] <= 'z') {

        }
    }
}

int main() {
    string str = "[3,ab[2, ab]g]";
    cin >> str;

    cout << str;
}