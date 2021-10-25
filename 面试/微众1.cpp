#include<iostream>

using namespace std;

bool isLeap(int a) {
    if(a % 4 == 0) {
        if(a % 100 == 0 && a % 400 != 0) return false;
        return true;
    }
    return false;
}

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

int main() {
    int a, b;
    cin >> a >> b;
    int year = 2021;
    int month = 1;
    int day = 1;
    int p = 5;
    int ans = 0;
    while(year != a || month != 1 || day != 1) {
        if(day == 1) {
            if(month == 1) {
                year--;
                month = 12;
            } else {
                month--;
            }
            day = months[month];
            if(isLeap(year) && month == 2) day = 29;            
        } else {
            day--;            
        }
        p = p - 1;
        if(p == 0) p = 7; 
        // cout << year << " " << month << " " << day << " " << p <<endl;
        if(day == 1 && p == 1){ 
            ans++;
            cout << year << " " << month << " " << day << " " << p <<endl;
        }
    }
    // cout << ans << endl;
    year = 2021;
    month = 1;
    day = 1;
    p = 5;
    while(year != b || month != 12 || day != 31) {
        if(isLeap(year) && month == 2 && day == 29) {
            day = 1; 
            month++;
            p = p + 1;
            if(p == 8) p = 1;           
        } else if(day == months[month]) {
            day = 1;
            month++;
            if(month == 13) {
                month = 1;
                year++;
            }
            p = p + 1;
            if(p == 8) p = 1; 
        } else {
            day++;
            p = p + 1;
            if(p == 8) p = 1;
        }
        
        if(day == 1 && p == 1){ 
            ans++;
            cout << year << " " << month << " " << day << " " << p <<endl;
        }
    }
    cout << ans << endl;
}