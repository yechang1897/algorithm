#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m, x, k;
    cin >> n >> m >> x >> k;
    v ector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for(int i = 0; i < m; i++) {
        int minN = INT_MAX;
        int minIndex = 0;
        for(int j = 0; j < n; j++) {
            if(minN > nums[j]) {
                minN = nums[j];
                minIndex = j;
            }
        }
        
    }
}