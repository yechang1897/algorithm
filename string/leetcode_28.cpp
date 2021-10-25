#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int strStr(string haystack, string needle) {
    if((int)needle.size() == 0) return 0;
    int flag = 0;
    while (flag < (int)haystack.size()) {
        int temp = flag;
        for (int i = 0; i < (int)needle.size(); i++) {
            if (haystack[temp] == needle[i]) {
                temp++;
            } else {
                break;
            }
        }
        if (temp - flag != (int)needle.size()) {
            flag++;
        } else {
            return flag;
        }
    }
    return -1;    
}

int main() {
    string haystack = "mississippi";
    string needle = "issip";
    cout << strStr(haystack, needle);
}