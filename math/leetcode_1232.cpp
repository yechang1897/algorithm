#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

double slope(int x1, int y1, int x2, int y2) {
    if(x2 - x1 == 0) return INT_MAX;
    return (double)(y2 - y1) /  (x2 - x1);    
}

bool checkStraightLine(vector<vector<int>>& coordinates) {
    double temp = slope(coordinates[0][0], coordinates[0][1], coordinates[1][0], coordinates[1][1]);
    for(int i = 1; i < (int)coordinates.size() - 1; ++i) {
        if(temp != slope(coordinates[i][0], coordinates[i][1], coordinates[i + 1][0], coordinates[i + 1][1])) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> coordinates = {{-4,-3},{1,0},{3,-1},{0,-1},{-5,2}};
    cout << checkStraightLine(coordinates);
}