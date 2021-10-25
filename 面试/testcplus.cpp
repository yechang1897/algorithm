#include<iostream>
#include <iomanip>
#include<stdio.h>
#include<algorithm>
#include<fstream>

using namespace std;

int main() {
    // int a;
    // scanf("%d", &a);
    // long b;
    // scanf("%ld", &b);
    // float c;
    // scanf("%f", &c);
    // double d;
    // scanf("%lf", &d);
    // printf("%d, %ld, %f, %f", a, b, c, d);
    // int a;
    // cin >> a;
    // long long b;
    // cin >> b;
    // cout << a <<endl;
    // cout << b << endl;
    // float c;
    // cin >> c;
    // double d;
    // cin >> d;
    // cout <<setprecision(15) << c << endl;
    // cout <<setprecision(20) << d << endl;
    // int data[10][4];
    // ifstream file;
    // file.open("d://1.txt");
    // for(int i = 0; i < 10; i++) {
    //     for(int j = 0; j < 4; j++) {
    //         file >> data[i][j];
    //     }
    // }
    // file.close();
    // for(int i = 0; i < 10; i++) {
    //     for(int j = 0; j < 4; j++) {
    //         cout << data[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // int n = 16;
    // char buffer [33];
    // itoa(n, buffer, 2);
    // for(int i = 0; buffer[i]; i++) {
    //     cout << buffer[i] << endl;
    // }
    string s = "abcddd";
    cout << s.find("bcd") << endl;
    if(s.find("abce") == string::npos) {
        cout << "not find";
    }
}