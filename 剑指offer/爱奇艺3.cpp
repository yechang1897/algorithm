#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

vector<string> getString(int n, const vector<int>& queens) {
    vector<string> res;
    for(int i = 0; i < n; i++) {
        string t(n, '.');
        t[queens[i]] = 'Q';
        res.push_back(t);
    }
    return res;
}

void dfs(int n, int row, vector<int>& queens,vector<vector<string>>& res, unordered_set<int>& cols, unordered_set<int> s1, unordered_set<int>s2) {
    if(row == n) {
        res.emplace_back(getString(n, queens));
        return;
    }

    for(int i = 0; i < n; ++i) {
        int col = i;
        if(cols.find(col) != cols.end()) {
            continue;
        }
        int diag1 = row - i;
        if(s1.find(diag1) != s1.end()) {
            continue;
        }
        int diag2 = row + i;
        if(s2.find(diag2) != s1.end()) {
            continue;
        }


        queens[row] = i;
        cols.insert(col);
        s1.insert(diag1);
        s2.insert(diag2);

        dfs(n, row + 1, queens, res, cols, s1, s2);

        cols.erase(col);
        s1.erase(diag1);
        s2.erase(diag2);
        queens[row] = -1;
    }
}


vector<vector<string>> nqueens(int n) {
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> s1;
    unordered_set<int> s2;
    vector<int> queens(n, -1);
    dfs(n, 0, queens, res, cols, s1, s2);
    return res;
}




int main() {
    string temp;
    cin >> temp;
    int pos = temp.find('=');
    int n = 0;
    for(int i = pos + 1; i < temp.size(); i++) {
        n *= 10;
        n += temp[i] - '0';
    }
    vector<vector<string>> ans = nqueens(n);
    int x = ans.size();
    int y = ans[0].size();
    // cout << x << " " << y << endl;
    string res = "";
    res += "[";
    for(int i = 0; i < x; i++) {
        res += "[";
        for(int j = 0; j < y; j++) {
            res += ans[i][j];
            if(j != y - 1) res += ", ";
        }
        if(i != x - 1)
            res += "], ";
        else 
            res +=  "]";
    }
    res += "]";
    cout << res <<  endl;
    return 0;
}