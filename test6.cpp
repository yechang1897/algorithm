#include "iostream"
#include "initializer_list"
#include "stdarg.h"
#include "vector"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::initializer_list;
using std::vector;
void error_msg(initializer_list<string> il);
void ArgFunc(const char *str, ... );
int sumAll(initializer_list<int> il);
int &get(int *array, int index);
void myPrint(vector<int> li);

int main () {
    // string s[] = {"hello", "motherfucker"};
    // error_msg({"hello", "motherfucker"});
    // cout << sumAll({11,12,13}) << endl;
    // int ia[10];
    // for (int i = 0; i != 10; ++i)
    //     get(ia, i) = i;
    // for (auto i : ia) {
    //     cout << i << " ";
    // }
    // cout << endl;

    vector<int> vec = {1,2,3,4,5};
    myPrint(vec);
    return 0;
}

void error_msg(initializer_list<string> il) {
    for (auto beg = il.begin(); beg != il.end(); ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
}

void ArgFunc(const char *str, ... ) 
{ 
va_list ap; 

int n = 3; 

char *s = NULL; 

int d = 0; 

double f = 0.0; 

va_start(ap, str); // 注意！这里第二个参数是本函数的第一个形参 

s = va_arg(ap, char*); 

d = va_arg(ap, int); 

f = va_arg(ap, double); // 浮点最好用double类型，而不要用float类型；否则数据会有问题 

va_end(ap); 

printf("%s is %s %d, %f", str, s, d, f); 
} 

int sumAll(initializer_list<int> il) {
    int res;
    // for (auto beg = il.begin(); beg != il.end(); ++beg) {
    //     res += *beg;
    // }
    for (const auto &beg : il)
        cout << beg << " ";
    return res;
}

int &get(int *array, int index) {
    return array[index];
}

static size_t i = 0;

void myPrint(vector<int> li) {
    if (i != li.size()) {
        cout << li[i++] << endl;
        myPrint(li);
    }
}