#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
//找顺序对，然后计算它们的
int trap(vector<int>& height) {
    int res = 0;
    int flag = 0;
    int i = 0;
    while (i < (int)height.size()) {
        flag = i + 1;
        if(i == 0 && height[i] == 0) {
            i++;
            flag++;
            continue;
        } else {
            while(flag < (int)height.size() && height[i] > height[flag]) {
                flag++;
            }
            if (flag == (int)height.size()) {
                flag = i + 1;
            }
            int lower = min(height[i], height[flag]);
            for (int k = i + 1; k < flag; k++){
                res += lower - height[k];
            }
            cout << i << " " << flag <<" " << res << endl;
            i = flag;
        }
    }
    return res;
}

int trap_2(vector<int>& height) {
    stack<int> polyStack;
    int res = 0;
    for (int i = 0; i < (int)height.size(); i++) {
        while (!polyStack.empty() && height[i] > height[polyStack.top()]) {
            int popNum = polyStack.top();
            polyStack.pop();
            while(!polyStack.empty() && height[popNum] == height[polyStack.top()]) {
                polyStack.pop();
            }
            if(!polyStack.empty()) {
                int temp = height[polyStack.top()];
                int hig = min(temp - height[popNum], height[i] - height[popNum]);
                int wid = i - polyStack.top() - 1;
                res += hig * wid;
            }
        }
        polyStack.push(i);
    }
    return res;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap_2(height);
}