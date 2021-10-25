#include<iostream>
#include<vector>
#include<sstream>

using namespace std;
int main() {
    vector<int> nums;
    int t;
    while(cin >> t) {
        nums.push_back(t);
        if(getchar() == '\n')
            break;
    }
    //cout << str << endl;
    for(auto x : nums) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

// 1 2 3 4 5 