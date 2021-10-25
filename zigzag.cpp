#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

class solution{
public :
    string convert(string s, int numRows) {//数组法
        int length = s.length();
        int n = numRows;
        if (length <= 1 || n == 1) return s;
        int x = length / ((3 * n - 2) / n) + 1;
        cout << n << x << endl;
        string temp[n][x] = {{""}};
        string::iterator it = s.begin();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < n; j++)
            {   
                if(i % (n - 1) != 0){
                    int keyx = (i / (n - 1) + 1) * (n - 1) - i;
                    cout << keyx;
                    if(it != s.end()) {
                        temp[keyx][i] = *it++;
                    }
                    break;
                }
                if(it != s.end()){
                    temp[j][i] = *it++;
                }
            }
        }
        string res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < x; j++) {
                if (temp[i][j] != ""){
                    res.append(temp[i][j]);
                } 
            }
        }
        return res;
    }

};
int main(){
    solution s;
    cout << s.convert("ABC", 2);
    return 0;
}