#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int, string> map;


int change(int a, int b) {
	string sa = map[a];
    string sb = map[b];
    int res = 0;
    for(int i = 0; i < 7; i++) {
        if(sa[i] != sb[i]) res++;
    }
    return res;
}


int main() {
   map[0] = "1111110";
   map[1] = "0001100";
   map[2] = "0110111";
   map[3] = "0011111";
   map[4] = "1001101";
    map[5] = "1011011";
    map[6] = "1111011";
    map[7] = "0001110";
    map[8] = "1111111";
    map[9] = "1011111";
    int s;
    cin >> s;
    // cout << change(0, 1);
    string str = to_string(s);
    int sz = str.size();

    int temp = 0;
    for(int i = 0; i < sz - 1; i++) {
        temp += change(str[i] - '0', str[i + 1] - '0');
    }
    string ts = map[str[0] - '0'];
    for(int i = 0; i < ts.size(); i++) {
        if(ts[i] == '1') temp++;
    }
    cout << temp << " ";
    for(int i = 2; i < sz; i++) {
        int temp = 0;
    	for(int j = 0; j < sz - i; j++) {
            for(int b = j; b < j + i; b++){
                temp += change(str[b] - '0', str[b + 1] - '0');
            }
        }
        int cnt = 0;
        for(int k = 0; k < i;k++) {
            string t = map[str[k] - '0'];
            for(int a = 0; a < t.size(); a++) {
                if(t[a] == '1')cnt++;  
            }
        }
        temp += cnt;
        cout << temp << " "; 
    }
    int cnt = 0;
    for(int k = 0; k < str.size();k++) {
        string t = map[str[k] - '0'];
        for(int a = 0; a < t.size(); a++) {
            if(t[a] == '1')cnt++;  
        }
    }
    cout << cnt << " ";
    return 0;    
}