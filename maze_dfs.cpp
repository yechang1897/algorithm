#include<iostream>
#include<algorithm>

using namespace std;

int res = 0;
int map[105][105] = {0};
bool visit[105][105] = {0};
int R = 0, C = 0;

void maze(int i, int j) {
    if (i == R && j == C) {
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                cout << visit[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        res++;
        return;
    }    
    if (i != 1 && map[i - 1][j] == 1 && visit[i][j] == false) {
        visit[i][j] = true;
        maze(i - 1, j);
        visit[i][j] = false;
    }
    if (j != 1 && map[i][j - 1] == 1 && visit[i][j] == false) {
        visit[i][j] = true;
        maze(i, j - 1);
        visit[i][j] = false;
    }
    if (i != R && map[i + 1][j] == 1 && visit[i][j] == false) {
        visit[i][j] = true;
        maze(i + 1, j);
        visit[i][j] = false;
    }
    if (j != C && map[i][j + 1] == 1 && visit[i][j] == false) {
        visit[i][j] = true;
        maze(i, j + 1);
        visit[i][j] = false;
    }
}

int maze_2(int i, int j) {
    if (i < 1 || j < 1 || i > R || j > C || visit[i][j] == true || map[i][j] == 0) {
        return 0;
    }
    if (visit[R][C]){
        return 1;
    }
    int sum = 0;
    visit[i][j] = true;
    sum += maze_2(i - 1, j);
    sum += maze_2(i, j - 1);
    sum += maze_2(i + 1, j);
    sum += maze_2(i, j + 1);
    visit[i][j] = false;
    return sum;
}

int main() {
    
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> map[i][j];
        }
    }
    cout << endl;
    // cout << maze_2(1, 1) <<endl;
    maze(1, 1);
    cout << res <<endl;
}