#include<iostream>
#include<string>
#include<map>

using namespace std;

bool buddyStrings(string A, string B) {
    int szA = (int)A.size();
    int szB = (int)B.size();
    if(A == B) {
        if(A[0] != A[1]) {
            return false;
        }
    }
    if(szA != szB) {
        return false;
    }
    int flag = 0;
    map<int,char> m;
    for(int i = 0; i < szA; i++) {
        if(A[i] != B[i] && flag < 2) {
            m[i] = A[i];
            flag++;
        }
    }
    if(m.size() == 2) {
        A[m.begin()->first] = m.rbegin()->second;
        A[m.rbegin()->first] = m.begin()->second;
    }   
    return A == B;
}

int main() {
    string A = "abab", B = "abab";
    cout << buddyStrings(A, B);
}

