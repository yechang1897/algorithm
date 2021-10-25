#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int freq[256] = {0};
    int l = 0, r = -1; //滑动窗口为s[l...r]
    int res = 0;
    // 整个循环从 l == 0; r == -1 这个空窗口开始
    // 到l == s.size(); r == s.size()-1 这个空窗口截止
    // 在每次循环里逐渐改变窗口, 维护freq, 并记录当前窗口中是否找到了一个新的最优值
    while(l < (int)s.size()){
        if(r + 1 < (int)s.size() && freq[(int)s[r+1]] == 0){
            r++;
            freq[(int)s[r]]++;
        }else {   //r已经到头 || freq[s[r+1]] == 1
            freq[(int)s[l]]--;
            l++;
        }
        res = max(res, r-l+1);
    }
    return res;
}

int lengthOfLongestSubstring_2(string s) {
    int freq[256] = {0};
    int l = 0, r = -1;
    int res = 0;
    while (l < (int)s.size()) {
        if (r + 1 < (int)s.size() && freq[(int)s[r + 1]] == 0) {
            r++;
            freq[(int)s[r]]++;
        } else {            
            freq[(int)s[l]]--;
            l++;
        }
        res = max(res, r - l + 1);
    }
    return res;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring_2(s);
    return 0;
}

