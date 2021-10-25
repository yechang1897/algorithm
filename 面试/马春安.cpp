#include<iostream>
#include<string>
using namespace std;

string decrypt(string cip, int x) {
    string res = cip;
    for(int i = 1; i < cip.size(); i++) {
        if(cip[i] > cip[i - 1]){
            res[i] = (cip[i] - cip[i - 1]) + 'a';
        } else {
            res[i] = cip[i] - cip[i - 1] + 26 + 'a';
        }        
    }
    res[0] -= x % 26;
    return res;
}

string crypt(string cip, int x) {
    string res = cip;
    int c[cip.size()];
    c[0] = (cip[0] - 'a' + x) % 26;
    for(int i = 1; i < cip.size(); i++) {
       c[i] = (cip[i] - 'a' + c[i - 1]) % 26;
    }
    for(int i = 0; i < cip.size(); i++) {
        res[i] = c[i] + 'a' ;
    }
    return res;
}

// int N , M , T;
// int a, b, c, d;
// int s[55];
// int 
// int dp[55][1005][50005];

// int main() {
//     cin >> N >> M >> T;
//     while(N--) {
//         cin >> a >> b >> c >> d;
//     }
// }



int main() {
    string str;
    int x;
    cin >> str;
    cin >> x;
    cout << crypt(str, x) << endl;
    cout << decrypt(crypt(str, x), x);

    return 0;


}