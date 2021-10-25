#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;


unordered_map<int, int> map1;
unordered_map<int, int> map2;

void divide1(int x) {
    for (int i = 2; i <= x; i++) {
        while(x % i == 0) {
            map1[i]++;
            //cout << i << " ";
            x = x / i;
        }
    }
}

void divide2(int x) {
    for (int i = 2; i <= x; i++) {
        while(x % i == 0) {
            map2[i]++;
            //cout << i << " ";
            x = x / i;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        divide1(t);
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        divide2(t);
    }
    int sz = map1.size();
    int sz2 = map2.size();

    for (auto x = map1.begin(); x != map1.end(); x++) {
        //cout << x->first << " " << x->second << endl;
        if(map2.find(x->first) != map2.end()) {
            if(map2[x->first] > x->second){
                map2[x->first] -= x->second;
                x->second = 2;
            }
            else {
                x->second -= map2[x->first];
                map2[x->first] = 0;
            }
        }    
    }
    int prod1 = 1;
    for (auto x = map1.begin(); x != map1.end(); x++) {
        prod1 *= pow(x->first, x->second);
    }
    int prod2 = 1;
    for (auto x = map2.begin(); x != map2.end(); x++) {
        prod2 *= pow(x->first, x->second);
    }

    if(prod1 % prod2 == 0)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}