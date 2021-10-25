#include<iostream>
#include<unordered_set>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    unordered_set<int> s;
    for(int i = 0; i < n; i++) {
        if(s.find(a[i]) == s.end()){
            s.insert(a[i]);
            cout <<"insert" <<a[i] <<endl;
        } 
        else {
            int t = a[i];
            cout <<"add : t " <<t <<endl;
            while(s.find(t) != s.end()) {
                t++;
                cout <<"add" << t <<endl;
            }
            a[i] = t;
            s.insert(t);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
