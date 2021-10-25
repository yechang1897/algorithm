#include<iostream>
#include<vector>

using namespace std;

// int maxProfit(vector<int>& prices) {
//     int sz = prices.size();
//     vector<int> minL(sz);
//     vector<int> maxR(sz);

//     minL[0] = 0;
//     maxR[sz - 1] = sz - 1;

//     for(int i = 1; i < sz; i++) {
//         minL[i] = prices[i] < prices[minL[i - 1]] ? i : minL[i - 1];
//     }

//     for(int i = sz - 2; i >= 0; i--) {
//         maxR[i] = prices[i] > prices[maxR[i + 1]] ? i : maxR[i + 1];
//     }

//     for(int i = 0; i < sz; i++) cout << minL[i] << " " << maxR[i] << endl;
//     int l = 0, r = 0;
//     int maxN = 0;
//     for(int i = 0; i < sz; i++) {
//         if(maxN < (prices[maxR[i]] - prices[minL[i]])) {
//             maxN = prices[maxR[i]] - prices[minL[i]];
//             l = minL[i];
//             r = maxR[i];
//         }

//     }
//     cout << l << " " << r << endl;
//     int minN = INT_MIN;
//     int maxN2 = 0;
//     for(int i = l + 1; i < r; i++) {
//         if(minN < prices[i]) {
//             minN = prices[i];
//         } else if(maxN2 < minN - prices[i]) {
//             maxN2 = minN - prices[i];
//         }
//     }
//     cout << maxN2 << endl;
//     return prices[r] - prices[l] + maxN2;
// }

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int f[n][2];
    f[0][0] = 0, f[0][1] = -prices[0];
    for(int i = 1; i < n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i]);
    }
    return f[n - 1][0];
}

int main() {
    // vector<int> prices = {1,2,3,4,5};
    vector<int> prices = {2,1,2,0,1};
    cout << maxProfit(prices);
    return 0;
}