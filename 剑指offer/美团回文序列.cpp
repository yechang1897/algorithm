#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int getLPS(string s, vector<int>& lps){
    // i是后缀末尾的指针，j是前缀末尾的指针
    int j = 0, i = 1;
    // 从j=0，i=1开始找，错开了一位
    while(i < s.length()){
        // 如果字母相等，则继续匹配，最长相同前后缀的长度也加1
        if(s[i] == s[j]){
            lps[i] = j + 1;
            i ++;
            j ++;
        // 如果不同
        } else {
            // 如果前缀末尾指针还没退回0点，则找上一个子前缀的末尾位置
            if(j != 0){
                j = lps[j - 1];
            // 如果退回0点，则最长相同前后缀的长度就是0了
            } else {
                lps[i] = 0;
                i ++;
            }
        }
    }
    return lps[lps.size() - 1];
}

int shortestPalindrome(string s) {
    // 将字符串反转后拼接到后面
    string rev(s);
    reverse(rev.begin(), rev.end());;
    string combine = s + "#" + rev;
    
    // 计算LPS表值
    vector<int> lps(combine.length(), 0);
    int remove = getLPS(combine, lps);
    
    // 去掉后缀后，将反转字符串拼回前面
    string prepend = rev.substr(0, rev.length() - remove);
    return (int)prepend.size();
}

int main() {
    string str;
    cin >> str;
    cout << shortestPalindrome(str) << endl;
}