#include<iostream>
#include<vector>
#include<string>

using namespace std;

int findString(vector<string>& words, string s) {
    int left = 0;
    int right = (int)words.size() - 1;
    while(words[left] == "") {
        left++;
    }
    while(words[right] == "") {
        right--;
    }
    // cout << left << " " << right << endl;
    while(left <= right) {
        int mid = (left + right) / 2;
        // cout << left << " " << mid << " " << right << endl;
        while(words[mid] == "") {
            mid--;
        }
        if(mid == left) {
            if(words[left] == s) {
                return left;
            } else if(words[right] == s) {
                return right;
            } else {
                return -1;
            }
        }
        if(words[mid] == s) {
            return mid;
        } else if(words[mid] < s){
            left = mid;
        } else {
            right = mid;
        }
    }
    return - 1;
}

int main() {
    vector<string> words = {"CitZMIXZKoFbxvOlaza", "hBlKXdKJfBD"};
    string s = "hBlKXdKJfBD";
    cout << findString(words, s);
}