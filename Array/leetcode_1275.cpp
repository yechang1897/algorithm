#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int judge(vector<vector<int>>& chessboard) {
    //横向
    int i;
    int j;
    int flag;
    int result = 0;
    for(i = 0; i < 3; ++i) {
        flag = chessboard[i][0];
        for(j = 1; j < 3; ++j) {
            if(chessboard[i][j] != flag) {
                break;
            }
        }
        if(j == 3) {
            result = flag;
        }
    }
    for(i = 0; i < 3; ++i) {
        flag = chessboard[0][i];
        for(j = 1; j < 3; ++j) {
            if(chessboard[j][i] != flag) {
                break;
            }
        }
        if(j == 3) {
            result = flag;
        }
    }
    // cout <<"hello" << endl;
    flag = chessboard[0][0];
    for(i = 1; i < 3; ++i) {
        if(chessboard[i][i] != flag) {
            break;
        }
    }
    // cout << i << " " << flag << endl;
    if (i == 3) {
        result = flag;
    }

    flag = chessboard[0][2];
    for(i = 1; i < 3; ++i) {    
        if(chessboard[i][2 - i] != flag) {
            break;
        }  
    }
    if (i == 3) {
        result = flag;
    }     
    return result;
}

string tictactoe(vector<vector<int>>& moves) {
    vector<vector<int>> chessboard(3, vector<int>(3, 0));
    int sz = (int)moves.size();
    if (sz <= 4) {
        return "Pending";
    }
    int k = 0;
    while(k < sz) {
        if (k % 2 != 0) {
            int x = moves[k][0];
            int y = moves[k][1];
            // cout << x <<"-1"<<  k << y << endl;
            chessboard[x][y] = -1;
        } 
        if(k % 2 == 0){
            int x = moves[k][0];
            int y = moves[k][1];
            // cout << x <<"1"<< k << y << endl;
            chessboard[x][y] = 1;
        }
        k++;
    }
    for (vector<int> v : chessboard) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    int result = judge(chessboard);
    // cout << result << endl;
    cout << result << endl;
    if(result == 1) {
        return "A";
    } else if(result == -1){
        return "B";
    } else {
        if(sz == 9) {
            return "Draw";
        } else {
            return "Pending";
        }       
    }
}



int main() {
    // vector<vector<int>> moves = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
    vector<vector<int>> moves = {{1,0},{2,2},{2,0},{0,1},{1,1}};
    cout << tictactoe(moves);
}