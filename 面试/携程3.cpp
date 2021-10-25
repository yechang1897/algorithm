// #include<iostream>
// #include<cstring>
// #include<algorithm>
// using namespace std;

// int v[105];
// int w[105];
// int n, m;
// // int getMaxNum(string str) {
// //     final int sz = (int)str.size();
// //     int f[sz + 1];
// //     memset(f, 0, sizeof f);
// //     for (int i = 1; i <= m ; i++) {
// //         for (int j = v[i]; j <= sz; j++) {
// //             f[j] = max(f[j], f[j - v[i]] + w[i]);
// //         }
// //     }    
// //     return f[sz];
// // }

// int main() {    
//     cin >> n >> m;
//     string str;
//     cin >> str;
//     memset(v, 0, sizeof v);
//     memset(w, 0, sizeof w);
//     for (int i = 1; i <= m; i++) {
//         cin >> v[i] >> w[i];
//     }    
//     int res = 0;
//     int t = 0;
//     int i;
//     for (i = 0; i < str.size(); i++) {
//         if(str[i] == '1')
//             t++;
//         else {
//             if(str[i - 1] == '1') {
//                 res += getMaxNum(str.substr(i - t, t));
//                 t = 0;
//             }
//         }
//     }
//     res += getMaxNum(str.substr(i - t, t));
//     cout << res << endl;
// }

