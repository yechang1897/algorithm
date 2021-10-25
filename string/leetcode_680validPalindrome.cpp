#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool validPalindrome(string s) {
    bool flag = true;
    int left = 0, right = (int)s.size() - 1;  
    while(left < right) {
        cout << s[left] << " " << s[right] << endl;
        if(s[left] != s[right]) {
            if(flag) {
                flag = false;
                if(left == right - 1) {
                    return true;
                }
                if(s[left] == s[right - 1] && s[right] == s[left + 1]) {
                    if(s[left + 2] == s[right - 1]) {
                        left += 2;
                        right -= 1;
                        continue;
                    }
                    if(s[left + 1] == s[right - 2]) {
                        left += 1;
                        right -= 2;
                        continue;
                    }
                }
                if(s[left] == s[right - 1]) {
                    right--;
                    continue;
                } else if(s[right] == s[left + 1]) {
                    left++;
                    continue;
                } else {
                    return false;
                } 
                
            } else {
                cout << "t";
                return false;
            }
        }
        left++;
        right--;
    }
    return true;
}
//答案中的这种情况代码行数更简单
bool isPalindromeRange(string s, int i, int j) {
    for (int k = i; k <= i + (j - i) / 2; k++) {
            if (s[k] != s[j - k + i]) return false;
    }
    return true;
}

bool validPalindrome_2(string s) {
    for (int i = 0; i < (int)s.size() / 2; i++) {
            if (s[i] != s[(int)s.size() - 1 - i]) {
                int j = s.size() - 1 - i;
                return (isPalindromeRange(s, i+1, j) ||
                        isPalindromeRange(s, i, j-1));
            }
        }
    return true;
}

int main() {
    string str = "ebcbbececabbacecbbcbe";
    cout << validPalindrome_2(str) << endl;
}