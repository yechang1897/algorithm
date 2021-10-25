#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

double PI = 3.14159;

int main() {
    // double R;
    // cin >> R;
    // cout <<fixed <<setprecision(4) << (R * R * PI) << endl;
    // int a = -10;
    // cout << a << endl;
    // double b = -10.21111;
    // cout << abs(b) << endl;
    // cout << fixed << setprecision(5) << abs(b) << endl;
    // cout << log(4) << endl;
    // int c = log(9) / log(3);
    // cout << c << endl;
    // cout << pow(2, 10) << endl;
    // cout << sqrt(4) << endl;
    // cout << rand() << endl;
    // string str = "2.1111";
    // double strd = atof(str.data());
    // cout << strd << endl;
    // string strI = "111111";
    // int strInt = atoi(strI.data());
    // cout << strInt << endl;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> nums2(5);
    rotate_copy(nums.begin(), nums.begin() + 1, nums.end(), nums2.begin());
    for(auto x : nums2) {
        cout << x << " ";
    }
    cout << endl;
}