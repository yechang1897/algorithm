#include<iostream> 
using namespace std; 
class TestClass{
    char x;
    public :
    TestClass(){cout << "A";}
    TestClass(char c) {cout << c;};
    ~TestClass(){cout << "B";}
};  
int main (){
    TestClass p1, *p2;
    p2 = new TestClass('X');
    delete(p2);
    return 0;
} 