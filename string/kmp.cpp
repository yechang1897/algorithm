#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include <time.h>
#include<vector>

using namespace std;

int ViolentMatch(char* s, char* p) {  
    int sLen = strlen(s);  
    int pLen = strlen(p);  
  
    int i = 0;  
    int j = 0;  
    while (i < sLen && j < pLen) {  
        if (s[i] == p[j]) {  
            //①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++      
            i++;  
            j++;  
        } else {  
            //②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0      
            i = i - j + 1;  
            j = 0;  
        }  
    }  
    //匹配成功，返回模式串p在文本串s中的位置，否则返回-1  
    if (j == pLen) {
        return i - j;  
    }
    else {
        return -1;  
    }         
}  

//ababaca
void cal_next(char *str, int *next, int len){
    next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    int k = -1;//k初始化为-1
    for (int q = 1; q <= len-1; q++){
        while (k > -1 && str[k + 1] != str[q]){//如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
            k = next[k];//往前回溯
        }
        if (str[k + 1] == str[q]){//如果相同，k++
            k = k + 1;
        }
        next[q] = k;//这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
    }
}

int KMP(char *str, int slen, char *ptr, int plen){
    int *next = new int[plen];
    cal_next(ptr, next, plen);//计算next数组
    int k = -1;
    for (int i = 0; i < slen; i++){
        while (k >-1&& ptr[k + 1] != str[i])//ptr和str不匹配，且k>-1（表示ptr和str有部分匹配）
            k = next[k];//往前回溯
        if (ptr[k + 1] == str[i]){
            k = k + 1;
        }
        if (k == plen-1){//说明k移动到ptr的最末端
            //cout << "在位置" << i-plen+1<< endl;
            //k = -1;//重新初始化，寻找下一个
            //i = i - plen + 1;//i定位到该位置，外层for循环i++可以继续找下一个（这里默认存在两个匹配字符串可以部分重叠），感谢评论中同学指出错误。
            return i-plen+1;//返回相应的位置
        }
    }
    return -1;  
}

void Getnext(int next[],string t)
{
   int j=0,k=-1;
   next[0]=-1;
   while(j<t.size()-1)
   {
      if(k == -1 || t[j] == t[k])
      {
         j++;k++;
         if(t[j]==t[k])//当两个字符相同时，就跳过
            next[j] = next[k];
         else
            next[j] = k;
      }
      else k = next[k];
   }
}

//暴力破解
int violentMatch_2(string s, string p) {
    int lens = (int)s.size();
    int lenp = (int)p.size();
    int i = 0, j = 0;
    while(i < lens && j < lenp) {
       if(s[i] == p[j]) {
           i++;
           j++;
       } else {           
           i = i - j + 1;
           j = 0;
       }
    }
    if (j == lenp) {
        return i - j;
    } else {
        return -1;
    }
}

vector<int> getNext_2(string p) {
    int lenp = (int)p.size();
    vector<int> next(lenp, 0);
    next[0] = -1;
    int j = 0;
    int k = -1; 
    while(j < lenp - 1) {
        if(k == -1 || p[j] == p[k]) {
            next[++j] = ++k;
        } else {
            k = next[k];
        }
    }
    return next;
}

int kmp_2(string s, string p) {
    int lens = (int) s.size();
    int lenp = (int) p.size();
    vector<int> next;
    next = getNext_2(p);
    int i = 0;
    int j = 0;
    while (i < lens && j < lenp) {
        if (j == - 1 || s[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == lenp) {
        return i - j;
    } else {
        return -1;
    }
}

int main() {
    // string s1 = "bacbababadababacambabacaddababacasdsd";
    // string s2 = "ababaca";
    // int len1 = (int)s1.size();
    // int len2 = (int)s2.size();
    // time_t start = time(NULL);
    // cout << ViolentMatch(s1.data(), s2.data());
    // time_t end = time(NULL);
    // cout << "time:" <<  end - start << endl;
    // start = time(NULL);
    // cout << KMP(s1.data(), len1, s2.data(), len2);
    // end = time(NULL);
    // cout << "time:" << end - start << endl;
    // string s = "BBC ABCDAB ABCDABCDABDE";
    // string p = "ABCDABD";
    // cout << kmp_2(s, p);
    string s = "aaab";
    char* s1 = s.data();
    // cout << s1 << endl;
    int a[5] = {0,0,0,0,0};
    Getnext(a, s);
    for(int i : a) {
        cout << i << " ";
    }
}