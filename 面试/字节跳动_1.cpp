#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int getMaxDis(vector<int> seats) {
    int sz = (int) seats.size();
    int temp = 0;
    int tempL = 0;
    int tempR = 0;
    int res = 0;
    for (int i = 0; i <= sz; ++i) {
        if(seats[i] == 0) {
            int left = i - 1 < 0 ? i - 1 + sz : i - 1;
            int right = i + 1 >= sz ? (i + 1) - sz: i + 1;
            cout << left << " ->   " << right << endl;
            while(left != right) {
                if(seats[left] == 1) {
                    if(left > i) {
                        tempL = i - 0 + sz - left;
                    } else {
                        tempL = i - left;
                    }
                    cout << "tempL:" << tempL <<endl;
                    break;
                }
                left--;
                // cout << tempL << " " << tempR << endl;
                // temp = min(tempL, tempR);
            }
            while(left != right) {
                if(seats[right] == 1) {
                    if(right < i) {
                        tempR = sz - i + right - 0;
                    } else {
                        tempR = right - i;
                    }
                    cout << "tempR:" << tempR <<endl;
                    break;;                   
                }
                right++;
            }
            temp = min(tempL, tempR);
            cout << "temp:"<<temp << endl;
        }
        res = max(res, temp); 
    }
    return res;
}

int getMaxDis_2(vector<int>& nums) {
    int sz = nums.size();
    int count = 0;
    for(auto item : nums) {
        if(item == 1) {
            count++;
        }
    }
    int temp = count - sz / 2;
    if(temp < 0) {
        temp += sz;
    }
    return temp % sz; 
}

int main() {
    vector<int> seats = {1, 0 ,0 ,0, 0};
    cout << getMaxDis(seats);
    // cout << (5 % 8) << endl;
}