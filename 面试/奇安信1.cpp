#include<iostream>
#include<deque>

using namespace std;

int calculate(string s) {
    int n = s.size(), num = 0, curRes = 0, res = 0;
    char op = '+';
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            num = num * 10 + c - '0';
        } else if (c == '(') {
            int j = i, cnt = 0;
            for (; i < n; ++i) {
                if (s[i] == '(') ++cnt;
                if (s[i] == ')') --cnt;
                if (cnt == 0) break;
            }
            num = calculate(s.substr(j + 1, i - j - 1));
        }
        if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
            switch (op) {
                case '+': curRes += num; break;
                case '-': curRes -= num; break;
                case '*': curRes *= num; break;
                case '/': curRes /= num; break;
            }
            if (c == '+' || c == '-' || i == n - 1) {
                res += curRes;
                curRes = 0;
            }
            op = c;
            num = 0;
        }
    }
    return res;
}

int main() {
    string str = "2 + (4 * 3)";
    cout << calculate(str) << endl;
    return 0;
}

/**
2 171.78 67.03
3 255.45 98.74
4 322.93 131.49
5 469.36 194.40
6 540.78 219.45
7 631.72 247.30
8 706.67 285.79
9  774.12 347.51
10 830.04 355.21
11 935.77 375.37
*/

/**
2 172.88 65.92
3 249.28 95.56 
4 327.07 136.67 
5  405.66 162.58
6 481.54 192.70
7 568.16 228.15
8 636.75 256.08
9 707.10 288.04
10 797.00 320.67
11 850.51 345.08
*/
