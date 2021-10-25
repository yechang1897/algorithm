#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums;
    while(true) {
        int t;
        cin >> t;
        nums.push_back(t);
        if(getchar() == '\n')
            break;
    }
    // cout << nums.size() << endl;
    int sorted[4] = {0, 0, 0, 0};

    for (int i = 0; i < nums.size(); i++) {
        sorted[nums[i]]++;
    }
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j < sorted[i]; j++)
        {
            cout << i << " ";
        }
    }
    return 0;
}