#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

// vector<int> getBeauty(vector<int> ) {

// }

int maxHappiness(vector<int> cry) {
    int sz = (int)cry.size();
    vector<int> dp (sz);
    dp[0] = cry[0] > -5 ? cry[0] : 0;
    int temp = dp[0];
    int flag = 1;
    for(int i = 1; i < sz; i++) {
        dp[i] += dp[i - 1];
        flag++; 
        if(cry[i] > 0) {
            dp[i] += cry[i];
            if(flag == 3) {
                dp[i] += 5;
                flag = 0;
                temp = 0;
            }
        } else if(cry[i] > -5) {
            temp += cry[i];
            if(flag == 3 && temp > -5) {
                cout << dp[i] << endl;
                cout << temp << endl;
                dp[i] += temp + 5;
                temp = 0;
                flag = 0;
            }
        }
    }
    for(int i : dp) {
        cout << i << endl;
    }
    return dp[sz - 1];
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> cry(n);
    for(int i = 0; i < n; ++i) {
        cin >> cry[i]; 
    }
    cout << maxHappiness(cry);
}