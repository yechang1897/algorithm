#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

int calculate(string s) {
    stack<char> oper;
    stack<int> num;
    s += "+0";
   for(int i = 0; i < s.size(); i++) {
       if(s[i] == ' ') continue;
       if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') oper.push(s[i]);
       else {
           int j = i;
           while(j < s.size() && s[j] >= '0' && s[j] <= '9') j++;
           num.push(atoi(s.substr(i, j - i).c_str()));          
           i = j - 1;
           if(!oper.empty()) {
               if(oper.top() == '*' || oper.top() == '/') {
                    int num1 = num.top(); num.pop();
                    int num2 = num.top(); num.pop();
                    cout << num2 * num1 << endl;
                    if(oper.top() == '*') num.push(num2 * num1);
                    else num.push(num2 / num1);
                    oper.pop();
                } else if(oper.size() >= 2) {
                    int num1 = num.top(); num.pop();
                    int num2 = num.top(); num.pop();
                    int num3 = num.top(); num.pop();
                    char op2 = oper.top(); oper.pop();
                    char op1 = oper.top(); oper.pop();
                    if(op1 == '+') num.push(num3 + num2);
                    else num.push(num3 - num2);
                    num.push(num1);
                    oper.push(op2);
                }
           }
       }
   }
   num.pop();
   return num.top();
}

int main() {
    string s = "3+2*2";
    cout << calculate(s);
}