#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

double areas_2(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    // cout << p << endl;
    // cout << sqrt( p * (p - a) * (p - b) * (p - c)) << endl;
    return sqrt( p * (p - a) * (p - b) * (p - c));
}

double largestTriangleArea_2(vector<vector<int>>& points) {
    int sz = (int)points.size();
    double res = 0;
    for (int i = 0; i < sz; ++i) {
        for (int j = i + 1; j < sz ; ++j) {
            for (int k = j + 1; k < sz; ++k) {
                double a = hypot(points[j][0] - points[i][0], points[j][1] - points[i][0]);
                double b = hypot(points[k][0] - points[j][0], points[k][1] - points[j][0]);
                double c = hypot(points[i][0] - points[k][0], points[i][1] - points[k][0]);
                double temp = areas_2(a, b, c);
                cout << a << " " << b << " " << c <<endl;
                cout << temp << endl;
                res = max(res, temp);
            }
        }
    }
    return res;
}


double distance(const vector<int>& p, const vector<int>& q) {
    return sqrt(pow(p[0] - q[0], 2.0) + pow(p[1] - q[1], 2.0));
}
    
    // s = (a + b + c) / 2; area = sqrt(s*(s -a) * (s -b) * (s - c));
double getArea(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) {
    double sideP1P2 = distance(p1, p2);
    double sideP1P3 = distance(p1, p3);
    double sideP2P3 = distance(p2, p3);
    if (sideP1P2 + sideP1P3 > sideP2P3 && sideP1P2 + sideP2P3 > sideP1P3 && sideP1P3 + sideP2P3 > sideP1P2) {
        double s = (sideP1P2 + sideP1P3 + sideP2P3) / 2.0;
        cout << sideP1P2 << " " << sideP1P3<< " " << sideP2P3 << endl;
        cout << sqrt(s * (s - sideP1P2) * (s - sideP1P3) * (s - sideP2P3)) << endl;
        return sqrt(s * (s - sideP1P2) * (s - sideP1P3) * (s - sideP2P3));
    }

    return -1.0;
}

double largestTriangleArea(vector<vector<int>>& points) {
    if (points.size() < 3) {
        return 0.0;
    }
    double res = 0;
    int N = points.size();
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N;j++) {
            for (int k = j + 1; k < N; k++) {
                res = max(res, getArea(points[i], points[j], points[k]));
            }
        }
    }
    return res;
}


int main() {
    vector<vector<int>> points = {{4,6},{6,5},{3,1}};
    cout << largestTriangleArea(points);
}