#include<iostream>
#include<algorithm>

using namespace std;


int temp[100];
int n;

void merge_sort(int a[], int l, int r) {
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1, k = 0;

    while(i <= mid && j <= r) {
        if(a[i] < a[j])     temp[k++] = a[i++];
        else    temp[k++] = a[j++];
    }

    while(i <= mid) {
        temp[k++] = a[i++];
    }

    while(j <= r) {
        temp[k++] = a[j++];
    }
    for(int i = l, k = 0; i <= r; i++) a[i] = temp[k++];

}

int main() {
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(a, 0, 9);
    for(auto x : a) {
        cout << x << " ";
    }
    puts("");
}