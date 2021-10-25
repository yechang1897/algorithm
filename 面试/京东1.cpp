#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1005;
int grid[N][N];

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> nums;
    int x, y;
    memset(grid, 0, sizeof grid);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        grid[x - 1][y - 1] = 1;
    }
    int res = 0;
    for (int i = 0; i < 1005; i++) {
        for (int j = 0; j < 1005; j++) {
            int x = i, y = j;
            int t = 0;
            while(x < 1005 && y < 1005) {
                if(grid[x][y] == 1)
                    t++;
                x++;
                y++;
            }
            if(t != 0)
                cout << t << endl;
            if(t != 1)
                res += t * (t - 1) / 2;
            t = 0;
            while(x < 1005 && y >= 0) {
                if(grid[x][y] == 1) t++;
                x++;
                y--;
            }
            if(t != 0)
                cout << t << endl;
            res += t * (t - 1) / 2;
        }
    }
    cout << res << endl;
    return 0;
}