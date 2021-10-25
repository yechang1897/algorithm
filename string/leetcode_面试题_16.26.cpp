#include<iostream>
#include<algorithm>
#include<string>
#include<sstream> 
#include<vector>
#include<stack>

using namespace std;

int calculate(string s) {
    char op = '+';
    int val;
    istringstream iss(s);
    stack<int> st;

    while(iss>>val){
        cout << val << endl;
        if(op=='+'){
            st.push(val);
        }else if(op=='-'){
            st.push(-val);
        }else{
            int val2 = st.top(); st.pop();
            if(op=='*') st.push(val*val2);
            else if(op=='/') st.push(val2/val);
        }
        iss>>op;
    }

    int res = 0;
    while(st.size()){
        res += st.top(); st.pop();
    }
    return res;
}

int main(){
    string s = "1*2-3/4+5*6-7*8+9/10";
    cout << calculate(s);
}