#include<iostream>

using namespace std;

int minArray(vector<int>& numbers) {
    int res = numbers[0];
    int sz = numbers.size();
    int temp = res;
    for(int i = 1; i < sz; i++) {
        if(temp > numbers[i]) res = numbers[i];
        else temp = numbers[i];
    }
    return res;
}

int main() {

}