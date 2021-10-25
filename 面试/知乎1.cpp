#include<iostream>
#include<vector>
using namespace std;

vector<int> fib(int n) {
    vector<int> nums(n);
    nums[0] = 1;
    nums[1] = 1;
    for(int i = 2; i < n; i++) {
        nums[i] = nums[i - 1] + nums[i - 2];
    }

    return nums;
}

int main() {
    int n = 5;
    for(auto x : fib(n)) cout << x << " ";
    cout << endl;
    return 0;
}