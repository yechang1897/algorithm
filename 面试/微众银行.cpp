#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int p[1000010];
int n = 5, m = 3;

int finds(int x) {
    if(p[x] != x) p[x] = finds(p[x]);
    return p[x];
}

vector<double> getNums(vector<int>& water, vector<vector<int>>& t) {
    
    for(int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for(auto item : t) {
        int a = item[0];
        int b = item[1];
        p[finds(a)] = finds(b);
    }
    unordered_map<int, int> m;
    vector<int> count(n + 1);
    for(int i = 1; i <= n; i++) {
        
        if(m.find(finds(i)) != m.end()) {
            m[finds(i)] += water[i];
        } else {
            m[finds(i)] = water[i];
        }       
        count[finds(i)]++;
    }
    vector<double> res(n + 1);
    for(int i = 1; i <= n; i++) {
        double temp = (double)m[finds(i)] / count[finds(i)];
        res[i] = temp;
    }
    return res;
}

int main() {
    vector<int> water = {0, 1, 6, 4, 5, 2};
    vector<vector<int>> t = {{1,2}, {2, 3}, {4, 5}};
    vector<double> res = getNums(water, t);
    for(auto item : res) {
        cout << item << " ";
    }
}