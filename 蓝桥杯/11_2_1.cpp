#include<iostream>

using namespace std;

int main() {
    int sum = 10000;
    int time = 0;
    while(sum > 0) {
        sum -= 600;
        time++;
        if(sum > 0) {
            sum += 300;
            time++;
        }
        cout << sum << endl;
        cout << time << endl;        
    }
    cout << time << endl;
    cout << 64 * 60 + 40 << endl;
}

/*
res = 3880

2 = 10; a + b >= sqrt(ab)
*/