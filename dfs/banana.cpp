#include <iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

// int begins = 6;
// int res = 0;

// int allocations(int b, int round) {
    
//     if(b % 5 == 1){
//         round++;
//         b = b - (b - 1) / 5 - 1;
//         if (round == 5){
//             return b;
//         } else {
//             return allocations(b, round + 1);
//         }
//     } else {
//         return 0;
//     }
// }

// int banana() {
//     int res = 0;
//     while(true) {
//         res = allocations(begins, 1);
//         if((int)res == res) {
//             break;
//         } else {
//             begins++;
//         }
//     }
//     return res;
// }

vector<string> res;

void dfs(string s, int i) {
    if(i == (int)s.size()) {
        res.push_back(s);  
        return;
    }
    dfs(s, i + 1);//未修改的分支
    //修改后的分支
    if('9' < s[i]) {
        s[i] ^= 32; 
        dfs(s, i + 1);       
    }
   
}

vector<string> letterCasePermutation(string s) {
    dfs(s, 0);
    return res;
}

void change(string& s) {
    if((int)s.size() == 1) {
        return;
    }
    int i = 1;
    while(i < (int)s.size()) {
        s.insert(i, "->");
        i += 3;
    }
}

int main(){
    // // cout << banana() << " "<< begins << endl;
    // // return 0;
    // // cout << 'A' - 'a' << endl;
    // // cout << ('0' < 'A') << endl;
    // string s = "3z4";
    // vector<string> temp = letterCasePermutation(s);
    // for(auto item : temp) {
    //     cout << item << " ";
    // }
    string s = "1";
    change(s);
    cout << s << endl;
    cout << to_string(12);
}