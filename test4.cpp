#include "iostream"
using std::cout;
using std::cin;
using std::endl;
int fact(int);
void tran(int *, int *);
void reset(int &);
void tran2(int &, int &);
int main () {
    // int num;
    // cin >> num;
    // // cout << fact(num) << endl;
    // cout << abs(num) << endl;
    // int a = 10, b = 15;
    // cout << a << b << endl;
    // tran(&a, &b);
    // cout << a << b << endl;
    // int val = 10;
    // cout << val << endl;
    // reset(val);
    // cout << val << endl;
    // int val = 10, val2 = 20;
    // cout << val << val2 << endl;
    // tran2(val, val2);
    // cout << val << val2 << endl;
    
    return 0;
}

int fact (int val) {
    int i;
    int res = 1;
    for (i = val; i > 0; i--)
        res *= i;
    return res;
}

void tran(int *a, int *b){
    int *temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}

void reset (int & a) {
    a = 1;
}

void tran2(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}