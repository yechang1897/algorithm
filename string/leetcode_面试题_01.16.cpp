#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

string compressString(string S) {
    char temp = S[0];
    int tempNum = 0;
    string res;
    S.push_back('0');
    for(int i = 0; i < (int)S.size(); i++) {
        if(temp == S[i]) {
            tempNum++;
        } else {
            res.push_back(S[i - 1]);
            res += to_string(tempNum);
            temp = S[i];
            tempNum = 1;
        }
    }
    if(res.size() >= S.size() - 1){
        S.pop_back();
        return S;
    }
    return res;
}

int main() {
    string s = "bb";
    cout << compressString(s);
}