#include<iostream>

using namespace std;

int main() {
    int n;
    int minNum = 101;
    int maxNum = -1;
    double sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num < minNum) minNum = num;
        if(num > maxNum) maxNum = num;
        sum += num;
    }
    cout << maxNum << endl;
    cout << minNum << endl;
    printf("%.2lf", sum / n);
}