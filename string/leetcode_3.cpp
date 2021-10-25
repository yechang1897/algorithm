#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

// int lengthOfLongestSubstring(string s) {
//     string tempLongest = "";
//     string longeststr = "";
//     longeststr.append(s.substr(0, 1));
//     tempLongest.append(s.substr(0, 1));
//     for (int i = 1; i < (int)s.length(); i++) {
//         int j;
//         for (j = tempLongest.length() - 1; j >= 0; j--) {
//             if(s[i] == tempLongest[j]) {
//                 break;
//             }
//         }
//         tempLongest.push_back(s[i]);
//         if (j == -1) {
//             if(tempLongest.length() > longeststr.length()) {
//                 longeststr = tempLongest;
                
//             }
//         } else {
//             tempLongest = tempLongest.substr(j + 1, tempLongest.length() - j);
//         }
//         cout << tempLongest << " " << longeststr << endl;
//     }
//     return longeststr.length();
// }

int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int ans = 0, i = 0, j = 0;
    while (i <(int) s.length() && j <(int) s.length()) {
        if(!set.count(s[j])) {
            set.insert(s[j++]);
            ans = max(ans, j - i);
        } else {
            set.erase(s[i++]);
        }
    }
    return ans;
}

int main() {
    // string s = "aab";
    // string s = "pwwkew";
    string s = "abba";
    // cout << s.substr(0, 1) << endl;
    cout << lengthOfLongestSubstring(s);
}