#include<iostream>
#include<vector>
#include<algorithm>
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
    vector<int> nums2;
    while(true) {
        int t;
        cin >> t;
        nums2.push_back(t);
        if(getchar() == '\n')
            break;
    }

    sort(nums.begin(), nums.end());
    sort(nums2.begin(), nums2.end());
    int sz = nums2.size();
    int cnt = 0;

    vector<pair<int, int>> rag;
    int flag = 1;
    while(true) {
        for (int i = 0; i < nums2.size(); i++) {
            int l = nums2[i] - flag;
            if(l < 0) {
                l = 0;
            }
            int r = nums2[i] + flag;
            rag.push_back({l, r});
        }

        int j = 0;
        int i;
        for (i = 0; i < nums.size();) {
            int l = rag[j].first;
            int r = rag[j].second;

            if(nums[i] <= r && nums[i] >= l) {
                i++;
            } else {
                j++;
            }
            if(j == rag.size()) {
                break;
            }
        }

        if(i != nums.size()) {
            flag++;
        } else {
            break;
        }

    }
    cout << flag << endl;
    return 0;
}