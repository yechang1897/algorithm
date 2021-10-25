#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>

using namespace std;

int main() {
    vector<int> nums;
    int N;
    while(N) {
        scanf("%d\n", &N);
        nums.push_back(N);
    }
    for(int i = 0; i < nums.size(); i++) {
        for(int j = 1; j <= nums[i]; j++) {
            for(int k = 1; k <= nums[i]; k++) {
                int up = i, down = nums[i] - i + 1;
                int left = j, right = nums[i] - j + 1;
                cout << min(min(up, down), min(left, right)) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}