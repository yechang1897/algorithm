#include "iostream"
#include "vector"
#include "iterator"
using std::string;
using std::cin ; 
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;
int main () 
{
    // string word;
    // while (getline(cin, word)) 
    // {
    //     cout << word <<endl;
    // } //一次读入一行的字符串
    
    // while (cin >> word)
    //     cout << word <<endl; //一次只读入一个词
    
    // string first, second;
    // cin >> first >> second;
    // cout << (first == second) <<endl;
    // cout << (first > second ?first : second) << endl;
    // cout << (first.size() == second.size()) << endl;
    // cout << (first.size() > second.size() ? first : second)<<endl;
    // string word, temp;
    // while (cin >> temp)
    //     word += temp + " ";
    // // for (auto &c : word)//必须把c置为引用，不然无法改变word中的字符
    // //     c = toupper(c);
    // cout << word << endl;
    // string s("Hello World !!!");
    // decltype(s.size()) punt_cnt = 0;
    // for (auto c : s)
    //     if (ispunct(c)) 
    //         punt_cnt ++;
    // cout << punt_cnt << 
    // " punctuation characters in "<< s <<endl;
    //string s = "hello motherfucker";
    // for (auto &c : s)
    //     c = 'X';
    // cout << s << endl;
    //int cur = 0;
    // while (s[cur])
    // {
    //     s[cur] = 'X';
    //     cur++;
    // }
    // cout << s << endl;
    // string s;
    // cout << s[0] << endl;
    // string s("Hello World !!!");
    // string res = "";
    // int i;
    // int j = 0;
    // for (i = 0; i < s.size(); ++i )
    // {
    //     if (ispunct(s[i]))
    //         ;
    //     else
    //         res += s[i];
    // }   
    // cout << res.size() << res <<  endl;
    // const string s = "keep out !";
    // for (auto &c : s)
    // {
        
    // }    
    // vector<vector<int>> ivec;
    // vector<string> svec = ivec;
    // vector<string> svec(10,"null");
    // int i;
    // vector<int> list;
    // while (cin >> i)
    //     list.push_back(i);

    // string word;
    // vector<string> text;
    // while (cin >> word)
    //     text.push_back(word);
    // cout << text[0] <<endl;
    // string s("some string");
    // if (s.begin() != s.end()) {
    //     auto it = s.begin();
    //     *it = toupper(*it);
    // }
    // for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
    //     *it = toupper(*it);
    // cout << s <<endl;
    // for (auto it = s.begin(); it != s.end(); ++it)
    //     *it = toupper(*it);
    // cout << s;
    // for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)  
    //     *it = toupper(*it);
    // cout << s; 
    // vector<int> arr = {42,65,95,100,39,67,95,76,88,76,83,92,76,93};
    // for (auto it = arr.begin(); it != arr.end(); ++it)
    // {
    //         *it = *it * 2;
    //         cout << *it << " ";
    // }
    // for (auto itf = arr.begin(), itb = arr.end() - 1; itf < itb; ++itf, --itb)
    //     cout << *itf + *itb<< " ";
    // vector<int> scores(11,0);
    // auto head = scores.begin();
    // auto it = arr.begin();
    // while (it != arr.end())
    // {   
    //     int temp = *it++ / 10;
    //     ++(*(head + temp));  
    // }
    // auto it2 = scores.begin();
    // while (it2 != scores.end())
    // {
    //     cout << *it2++<< " ";
    //}
    // unsigned buf_size = 1024;
    // int ia[buf_size];
    // int ib[4 * 7 - 14];
    // int ic[abs(-10)];
    // int arr[10] = {};
    // int *e = &arr[10];
    // int *beg = std :: begin(arr);
    // int *end1 = end(arr);
    // int i;
    // for (i = 0; i < 10; i++) 
    //     arr[i] = i;
    // int arr2[10] = {};
    // for (i = 0; i < 10; i++)
    //     arr2[i] = arr[i];
    // int arr3[10] = {};
    // cout << arr3[0];
    // for (int *b = arr; b != e; ++b) 
    //     cout << *b << endl;
    // cout << sizeof(int) <<endl;
    // cout << sizeof(short) <<endl;
    // cout << sizeof(char) <<endl;
    // cout << sizeof(long) <<endl;
    // cout << sizeof(float) <<endl;
    // cout << sizeof(double) <<endl;
    // int x[10]; int *p = x;
    // cout << sizeof(x) / sizeof(*x) << endl;
    // cout << sizeof(p) / sizeof(*p) << endl;
    // int anum = 0, e_num = 0, inum = 0, onum = 0, unum = 0, othernum = 0;
    // int tabcnt = 0, spacecnt = 0, breakcnt = 0;
    // char ch;
    // while (cin >> ch) {
    //     if (ch == 'a' || ch == 'A')
    //         anum++;
    //     else if (ch == 'e' || ch == 'E')
    //         e_num++;
    //     else if (ch == 'i' || ch == 'I')
    //         inum++;
    //     else if (ch == 'o' || ch == 'O')
    //         onum++;
    //     else if (ch == 'u' || ch == 'U')
    //         unum++;
    //     else 
    //         othernum++;
    // }
    // cout << anum << e_num << inum << unum << othernum <<endl;
    // char ch;
    // char test = 'A';
    // while (cin.get(ch)) {
    //     switch (ch)
    //     {
    //     case 'a' : 
    //         anum++;
    //         break;
    //     case 'A' :
    //         anum++;
    //         break;
    //     case 'E' :
    //         e_num++;
    //         break;
    //     case 'e' :
    //         e_num++;
    //         break;
    //     case 'I' :
    //         inum++;
    //         break;
    //     case 'i' :
    //         inum++;
    //         break;
    //     case 'O' :
    //         onum++;
    //         break;
    //     case 'o' :
    //         onum++;
    //         break;
    //     case 'U' :
    //         unum++;
    //         break;
    //     case 'u' :
    //         unum++;
    //         break;
    //     case '\t' :
    //         tabcnt++;
    //         break;
    //     case ' ' :
    //         spacecnt++;
    //         break;
    //     case '\n' :
    //         breakcnt++;
    //         break;
    //     default:
    //         othernum++;
    //     }
    // }
    // cout << anum << e_num << inum << onum << unum << tabcnt << spacecnt << breakcnt << othernum <<endl;
    // string previousWord, word;
    // int maxCount = 0, count = 1;
    // cin >> previousWord;
    // while (cin >> word) {
    //     if (previousWord == word) {
    //         count++;
    //     } else {
    //         count = 1;
    //     }
    //     previousWord = word;
    //     if (maxCount < count) {
    //         maxCount = count;
    //     }
    // }
    // cout << maxCount;
    return 0;
}   
