#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(max < nums[i]) {
            max = nums[i];
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        if(max <= nums[i]) {
            res ++;
        }
    }
    printf("%d", res);
    return 0;
}