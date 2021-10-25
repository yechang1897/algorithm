#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {
    string str;
    cin >> str;
    stringstream ss(str);
    vector<int> nums;
    while(getline(ss, str, ',')) {
        int num = stoi(str);
        nums.push_back(num);    
    }
    int  n;
    cin >> n;
    for(int i = n; i <= nums.size(); i++) {
        for(int j = 0; j < n - i + 1; j++) {
            int t = j + i;
            if(nums[j] == nums[t]) {
                cout << true;
                return 0;
            }
        }
    }
    cout << false << endl;
    return 0;
}