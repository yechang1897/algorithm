#include<iostream>
#include<string>

using namespace std;
typedef long long ll;

bool isOdd(string str, ll dec) {
    int sz = str.size();
    if(dec % 2 == 0) {
        if(str[sz - 1] >= '0' && str[sz - 1] <= '9') {
            if((str[sz - 1] - '0') % 2) return true;
            else return false;
        } else {
            if((str[sz - 1] - 'A') % 2) return true;
            else return false;
        }    
    } else {
        int cnt = 0;
        for(int i = 0; i < sz; i++) {
            if(str[i] >= '0' && str[i] <= '9') {
                if((str[i] - '0') % 2) cnt++;
            } else {
                if((str[i] - 'A') % 2) cnt++;
            }            
        }
        if(cnt % 2) return true;
        else return false;
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        string str;
        cin >> str;
        ll l, r;
        cin >> l >> r;
        int oddNumber = 0;
        for(int i = l; i <= r; i++) {
            if(isOdd(str, i)) oddNumber++;
        }
        if(oddNumber % 2) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}