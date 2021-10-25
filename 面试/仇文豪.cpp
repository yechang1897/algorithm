#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

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

int main() {
    string A, B;
    cin >> A >> B;
    vector<int> nums1;
    vector<int> nums2;
    vector<int> nums3;
    vector<int> nums4;
    int dot = A.find(".");
    int dot2 = B.find(".");
    for(int i = dot - 1; i >= 0; i--) {
        nums1.push_back(A[i] - '0');
    }
    for(int i = dot2 - 1; i >= 0; i--) {
        nums2.push_back(B[i] - '0');
    }
    int sz = A.size() - dot > B.size() - dot2 ? A.size() - dot : B.size() - dot2;
    // cout << sz << endl;
    int flag = 0;
    for (int i = dot + sz - 1; i > dot; i--) {
        // cout << i << endl;
        if(i >= A.size()) {
             nums3.push_back(0);
             //  cout << "test" << endl;
        } else  nums3.push_back(A[i] - '0');
    }

    // for(auto x : nums3)
    //     cout << x << " ";
    // cout << endl;

    for (int i = dot2 + sz - 1; i > dot2; i--) {
        if(i >= B.size()) {
            nums4.push_back(0);
        } else {
            nums4.push_back(B[i] - '0');
        }           
    }
        // cout << nums1.size() << " " << nums2.size() << endl;
    string res;
    vector<int> t;
    
    
    string res2;
    
    // for(auto x : nums4)
    //     cout << x << " ";
    // cout << endl;
    for (auto x : add(nums3, nums4))
    {
        char c = x + '0';
        res2.push_back(c);
    }
    sz = nums3.size() > nums4.size() ? nums3.size() : nums3.size();
    if(sz < res2.size())
        flag = 1;
    if(flag) {
        t.push_back(1);
    } else {
        t.push_back(0);
    }
    vector<int> t2 = add(nums1, nums2);
    for (auto x : add(t, t2))
    {
        char c = x + '0';
        res.push_back(c);
    }
    reverse(res.begin(), res.end());
    reverse(res2.begin(), res2.end());
    sz = nums3.size() > nums4.size() ? nums3.size() : nums3.size();
    if(res2.size() > sz) res2 = res2.substr(1, res2.size() - 1);
    res.push_back('.');
    res.append(res2);
    int i;
    for (i = res.size() - 1; i >= 0; i--) {
        if(res[i] != '0' && res[i] != '.')
            break;
    }
    cout << res.substr(0, i + 1) << endl;
    return 0;
}