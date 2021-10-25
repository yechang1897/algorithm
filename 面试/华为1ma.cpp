#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int> nums;
    for(int i = 0; i < k; i++) {
        string str;
        cin >> str;
        stringstream ss(str);
        while(getline(ss, str, ',')) {
            int f = stoi(str);
            nums.push_back(f);
        }
    }
    int a;
    cin >> a;
    
}