#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

string reformatNumber(string number) {
    int flag = 0;
    while(flag < (int)number.size()) {
        if(number[flag] > '9' || number[flag] < '0') {
            cout << flag << endl;
            number.erase(number.begin() + flag);
            continue;
        }
        flag++;
    }
    cout << number;
    cout << endl;
    int sz = (int)number.size();
    string res;
    if(sz <= 4) {
        if (sz == 4) {
            number.insert(2, "-"); 
        } 
    } else if(sz >= 7){
        if(sz % 3 == 1) {
            for(int i = 3; i < (int)number.size() - 3; i += 3) {
                number.insert(i++, "-");
            }
            number.insert((int)number.size() - 2, "-"); 
        } else {
            for(int i = 3; i < (int)number.size() ; i += 3) {
                number.insert(i++, "-");
            }
        }
    } else {
        cout << "hello" <<endl;
        for(int i = 3; i < (int)number.size(); i += 3) {
            number.insert(i++, "-");
        }
    }
    cout << number;
    return number;
}

int main() {
    string number = "--17-5 229 35-39475 ";
    reformatNumber(number);
}