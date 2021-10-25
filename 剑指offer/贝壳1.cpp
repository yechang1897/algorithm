#include<iostream>
#include<vector>
using namespace std;

vector<int> fun(int n, long m) {
    vector<int> nums(n * 2 - 1);
    for(int i = 1; i <= n * n - 1; i++) {
        if(i <= n)
            nums[i] = i;
        else  
            nums[i] = 2 * n - i;
    }
    int num = m / (n * 2 - 2);
    int mod = m % (n * 2 - 2);
    vector<int> res(n);
    res[0] = num;
    res[n - 1] = num;
    for(int i = 1; i < n - 1; i++) {
        res[i] = 2 * num;
    }
    for(int i = 0; i < mod; i++) {
        int index = nums[i + 1];
        res[index - 1]++;
    }
    return res;        
}

int main() {
    int n = 4, m = 8;
    for(auto x : fun(n, m)) {
        cout << x << " ";
    }
    cout << endl;
}