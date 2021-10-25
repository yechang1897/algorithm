#include<iostream>
#include<string>
using namespace std;

int N;

bool isleap(int year) {
    bool flag = false;
    if(year % 4 == 0) flag = true;
    if(year % 100  == 0 && year % 400 != 0) flag = false;
    return flag;
}
//检查是否是合法日期
bool check2(int x){
    int year = x/10000;
    int month = x%10000/100;
    int day = x%100;
    if(!month || month>12 || !day)  return false;
    if(month!=2 && months[month]<day)  return false;
    if(month==2){
        bool leap = (year%4==0 && year%100)||year%400==0 ;
        if(day>28+leap) return false;
    }

    return true;
}


void addOne(int & n) {
    string s = to_string(n);
    // string year = s.substr(0,4);
    bool leap = isleap(n / 10000);
    int year = n / 10000;
    int month = (n % 10000) / 100;
    int day = n % 100;
    day += 1;
    bool maxDay = false;
    if(month == 1 || month == 3 ||month == 5 ||month == 7 ||month == 8 ||month == 10 ||month == 12) {
        if(day > 31) {
            day = 1;
            maxDay = true;
        }
    } else if(month == 2){
        if(leap) {
            if(day > 29) {
                day = 1;
                maxDay = true;
            }
        } else {
            if(day > 28) {
                day = 1;
                maxDay = true;
            }
        }
    } else {
        if(day > 30) {
            day = 1;
            maxDay = true;
        }
    }
    bool maxMonth = false;
    if(maxDay) {
        month += 1;
        if(month > 12) {
            month = 1;
            maxMonth = true;
        }
    }
    if(maxMonth) {
        year += 1;
    }
    // if(month < 10) {
    //     year *= 10000;
    // } else {
    //     year *= 10000;
    // }
    // if(day < 10) {
    //     month *= 100;
    // } else {
    //     month *= 100;
    // }
    year *= 10000;
    month *= 100;
    n = year + month + day; 
}

bool checkP(int num) {
    string s = to_string(num);
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}

bool checkAB(int num) {
    string s = to_string(num);
    if(checkP(num)) {
        char a = s[0];
        char b = s[1];
        if(s[2] == a && s[3] == b && s[4] == b && s[5] == a && s[6] == b && s[7] == a) return true;
    } else {
        return false;
    }
    return false;
}



int main() {
    // int N1 = 20201231;
    // addOne(N1);
    // cout << N1 << endl;
    cin >> N;
    int t = N + 1;
    while(!checkP(t)) {
        addOne(t);
    }
    cout << t << endl;
    t = N + 1;
    while(!checkAB(t)) {
        addOne(t);
    }


    // string s = to_string(t);
    // cout << s << endl;
    // char a = s[0];
    // char b = s[1];
    // cout << a << " " << b << endl;
    // for(int i = 2; i <= s.size() / 2 - 2; i += 2) {
    //     cout << i << endl;
    //     if(s[i] != a && s[i + 1] != b) cout << false << endl;
    // }
    // for(int i = s.size() / 2; i <= s.size() - 2; i += 2) {
    //     cout << i << endl;
    //     if(s[i] != b && s[i + 1] != a) cout << false << endl;
    // }

    cout << t << endl;
    // if(check(N))
}