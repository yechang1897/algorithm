#include<iostream>

using namespace std;

int main() {
    while(true) {
        char c = getchar();
        if(c == ' ') cout << "%20";
        else if(c == '\n') break;
        else cout << c ;
    }
    return 0;
}