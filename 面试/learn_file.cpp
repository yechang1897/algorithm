#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int a[305][305];
int main() {
    ifstream fin("d:\\find2020.txt");
    int flagX = 0;
    int flagY = 0;
    cout << flagX << flagY << endl;
    if(fin) {
        string temp;
        while(getline(fin, temp)) {
            int sz = temp.size();
            flagY = sz;
            for(int i = 0 ; i < sz; i++) {
                a[flagX][i] = (temp[i] - '0');
            }
            flagX++;
        }
    } else {
        cout << " file open fail" << endl;
    }
    cout << flagX << flagY << endl;
    // for(int i = 0; i < flagX; i++) {
    //     for(int j = 0; j < flagY; i++) {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    cout << a[299][297] << endl;
    fin.close();
}