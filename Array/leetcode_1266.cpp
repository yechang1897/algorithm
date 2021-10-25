#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int distance(int x1, int y1, int x2, int y2) {
    int res = 0;
    int x = abs(x1 - x2);
    int y = abs(y1 - y2);
    cout << x << " " << y << endl;
    res += min(x, y);
    res += abs(x - y);
    return res;
}

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int sz = points.size();
    int res = 0;
    for(int i = 0; i < sz - 1; ++i) {
        res += distance(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
    }
    return res;
}

int main() {
    vector<vector<int>> points = {{3,2},{-2,2}};
    cout << minTimeToVisitAllPoints(points);
}