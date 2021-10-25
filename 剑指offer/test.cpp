#include<vector>
#include<iostream>
// using namespace std;

// void fun(char *&p) {
//     p = (char *) malloc(sizeof(char) * 10);
// }

// int main() {
//     for(int i = 0; i < 1000000000; i++) {
//         char *p = NULL;
//         fun(p);
//         free(p);
//     }
//     return 0;
// }

int main() {
    const int upper = 10;
    std::vector<int> testArray;
    testArray.push_back(5);
    testArray.push_back(6);
    for(auto it = testArray.begin(); it != testArray.end(); ++it) {
        std::cout << *it << std::endl;
        if(*it < upper) {
            testArray.push_back(upper - *it);
        }
    }

    for(auto &test : testArray) {
        std::cout << test << std::endl;
    }
}