#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < (int)prices.size(); i++) {
        if(minPrice > prices[i]) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}

int main() {
    vector<int> nums = {7,1,5,3,6,4};
    cout << maxProfit(nums);
}