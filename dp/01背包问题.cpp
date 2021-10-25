#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int getMaxValue(vector<int>& v , vector<int>& w, int N, int V) {
    vector<vector<int>> f(N + 1, vector<int>(V + 1, 0));
    for(int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            f[i][j] = f[i - 1][j];
            if(v[i] <= j) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
            // f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
        }
    }

    // for(int i = 0; i <= N; ++i) {
    //     for (int j = 0; j <= V; ++j) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return f[N][V];
}
//优化空间效率，滚动数组优化
int getMaxValue_2(vector<int>& v , vector<int>& w, int N, int V) {
    vector<int> dp(V + 1);
    for(int i = 1; i <= N; ++i) {
        for (int j = V; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
        for(auto item : dp) {
            cout << item << " ";
        }
        cout << endl;
    }
    return dp[V];
}
//完全背包
int getMaxValue_3(vector<int>& v , vector<int>& w, int N, int V) {
    vector<vector<int>> f(N + 1, vector<int>(V + 1, 0));
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j <= V; ++j) {
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) {
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
            }
        }
    }
    

    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j <= V; ++j) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return f[N][V];
}
//完全背包，数组优化
int getMaxValue_4(vector<int>& v , vector<int>& w, int N, int V) {
    vector<int> f(V + 1);
    for(int i = 1; i <= N; ++i) {
        for (int j = v[i]; j <= V; j++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    return f[V];
}

int getMaxValue_5(vector<int>& v, vector<int> &w, vector<int>& s, int N, int V) {
    vector<int> f(V + 1);
    for(int i = 1; i <= N; ++i) {
        for(int j = V; j >= v[i]; j--) {
            for(int k = 1; k <= s[i] && j >= k * v[i]; k++) {
                f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
            }
        }
    }
    return f[V];
}

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> v(N + 1);
    vector<int> w(N + 1);
    vector<int> s(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }
    cout << endl;
    // for(int i = 0; i < N; i++) {
    //     cout << v[i] << " " << w[i] << endl;
    // }
    cout << getMaxValue_2(v, w, N, V);
}