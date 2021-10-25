#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N = 100000;
//高精度加法
// C = A + B, A >= 0, B >= 0
vector<int> add(vector<int>& A, vector<int>& B) {
    if(A.size() < B.size()) return add(B, A);
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++) {
        t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(1);
    return C;
}

//高精度减法
// C = A - B, 满足A >= B, A >= 0, B >= 0
bool cmp(vector<int> &A, vector<int> &B) {
    if(A.size() > B.size()) return true;
    else if(A.size() < B.size()) return false;
    else {
        for(int i = 0; i < A.size(); i++) {
            if(A[i] < B[i]) return false;
        }
        return true;
    }
}

vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++) {
        t += A[i];
        if(i < B.size()) t -= B[i];
        if(t < 0){
            C.push_back(10 + t);
            t = -1;
        } else {
            C.push_back(t);
            t = 0;
        }
    }

    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

// C = A * b, A >= 0, b >= 0
vector<int> mult(vector<int>& A, int b) {
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size() || t; i++) {
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

// A / b = C ... r, A >= 0, b > 0
vector<int> div(vector<int> &A, int b, int &r){
    vector<int> C;
    r = 0;
    for(int i = A.size() - 1; i >= 0 ; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    for(auto x : add(A, B)) {
        cout << x;
    }
    cout << endl;
    // for(auto x : A) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // auto C = add(A, B);
    vector<int> C;
    // if(cmp(A, B)) {
    //     C = sub(A, B);
    // } else {
    //     C = sub(B, A);
    // }
    // int res = 0;
    // C = mult(A, 123);
    // int mod = 0;
    // C = div(A, 9, mod);
    // reverse(C.begin(), C.end());
    // for(auto c : C) {
    //    cout << c << " ";
    // }
    // cout << endl;
    // cout << mod << endl;
    // reverse(C.begin(), C.end());
    // for(auto c : C) {
    //     res = res * 10 + c;
    // }
    // cout << res << endl;
}