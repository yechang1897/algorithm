#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int sz = prices.size();
    vector<int> minL(sz, 0);
    vector<int> maxR(sz, 0);
    minL[0] = prices[0];
    maxR[sz - 1] = prices[sz - 1];
    for(int i = 1; i < sz; i++) {
        minL[i] = prices[i] < minL[i - 1] ? prices[i] : minL[i - 1];
    }

    for(int i = sz - 2; i >= 0; i--) {
        maxR[i] = prices[i] > maxR[i + 1] ? prices[i] : maxR[i + 1];
    }
    int res = 0;
    for(int i = 0; i < sz; i++) {
        res = max(res, maxR[i] - minL[i]);
    }

    // for(int i = 0; i < sz; i++) {
    //    cout << maxR[i] << " " << minL[i] << endl;
    // }
    return res;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}