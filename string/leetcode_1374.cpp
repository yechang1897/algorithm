#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string generateTheString(int n) {
    string s = "";
    if(n % 2 == 0) {
        for(int i = 0; i < n - 1; i++) {
            s.push_back('a');
        }
        s.push_back('b');
    } else {
        for(int i = 0; i < n - 2; i++) {
            s.push_back('a');
        }
        s.push_back('b');
        s.push_back('c');
    }
    return s;
}

int main() {
    int n = 27;
    cout << generateTheString(n);
}